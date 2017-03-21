import sys
import yaml

def emit(s, indent=0):
    global output
    spacing = '    '*indent
    output.write(spacing + s+'\n')

def emit_class_function(d, cls, indent=0):
    fmt = dict(
        name=d['name'],
        ref=cls+'::'+d.get('ref', d['name'])
    )
    emit('.class_function("%(name)s", &%(ref)s)' % fmt, indent)

def emit_function(d, cls=None, indent=0):
    assert d['type'] == 'function'


    if cls is not None:
        fmt = dict(
            begin='.',
            end='',
            name=d['name'],
            ref=d.get('ref', '&'+cls+'::'+d['name']),
        )
    else:
        fmt = dict(
            begin='',
            end=';',
            name=d['name'],
            ref=d.get('ref', d['name']),
        )

    emit('%(begin)sfunction("%(name)s", %(ref)s)%(end)s' % fmt,
         indent)

def emit_property(d, cls, indent=0):
    assert d['type'] == 'property'

    fmt = dict(
        name=d['name'],
        cls=cls
    )
    emit('.property("%(name)s", &%(cls)s::%(name)s)' % fmt, indent)

def emit_class(d, indent):
    constructor = ', '.join(d['constructor'])
    emit('class_<%(name)s>("%(name)s")' % dict(name=d['name']), indent)
    emit('.constructor<%s>()' % constructor, indent+1)

    for field in d['fields']:
        if field['type'] == 'property':
            emit_property(field, cls=d['name'], indent=indent+1)
        elif field['type'] == 'function':
            emit_function(field, cls=d['name'], indent=indent+1)
        elif field['type'] == 'class_function':
            emit_class_function(field, cls=d['name'], indent=indent+1)

    emit(';', indent)

def emit_enum_value(name, prefix, indent):
    fmt = dict(
        name=name,
        prefix=prefix+'::'
    )
    emit('.value("%(name)s", %(prefix)s%(name)s)' % fmt, indent)

def emit_enum(d, indent):
    fmt = dict(
        cls=d['prefix']+'::'+d['name'],
        name=d['name']
    )
    emit('enum_<%(cls)s>("%(name)s")' % fmt, indent)
    for value in d['values']:
        emit_enum_value(value, prefix=d['prefix'], indent=indent+1)
    emit(';', indent)

def emit_module(module):
    emit('#include "%s.h"' % module['name'])
    emit("EMSCRIPTEN_BINDINGS(%s) {" % module['name'])
    for d in module['bindings']:
        if d['type'] == 'function':
            emit_function(d, indent=1)
        elif d['type'] == 'class':
            emit_class(d, indent=1)
        elif d['type'] == 'enum':
            emit_enum(d, indent=1)
    emit('}')

def main():
    filename = sys.argv[1]
    outputname = sys.argv[2]
    global output
    output = open(outputname, 'w')
    emit('#include <emscripten/bind.h>')
    emit('using namespace emscripten;')
    with open(filename) as f:
        inp = yaml.safe_load(f)
        for module in inp:
            emit_module(module)

if __name__=='__main__':
    main()
