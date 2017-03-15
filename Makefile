#CXX = g++-4.9
#CPPFLAGS = --std=c++14 -g
#LDLIBS = -lm -ldl

.PHONY: all clean

all: fastled

fastled: math8.cpp hsv2rgb.cpp colorutils.cpp
	emcc $^

clean:
	rm -f fastled
