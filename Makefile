#CXX = g++-4.9
#CPPFLAGS = --std=c++14 -g
#LDLIBS = -lm -ldl

.PHONY: all clean

all: fastled.js

bindings.cpp: bindings.yaml
	python gen_embind.py $^ $@

fastled.js: bindings.cpp math8.cpp hsv2rgb.cpp colorutils.cpp
	emcc -o $@ --bind $^

clean:
	rm -f fastled.js
