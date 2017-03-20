#CXX = g++-4.9
#CPPFLAGS = --std=c++14 -g
#LDLIBS = -lm -ldl

.PHONY: all clean

all: fastled.js

fastled.js: math8.cpp hsv2rgb.cpp colorutils.cpp color.cpp
	emcc -o $@ --bind $^

clean:
	rm -f fastled.js
