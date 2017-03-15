#ifndef _COLOR_H_
#define _COLOR_H_

struct CHSV {
	union {
		uint8_t hue;
		uint8_t h;
	};

	union {
		uint8_t saturation;
		uint8_t sat;
		uint8_t s;
	};

	union {
		uint8_t value;
		uint8_t val;
		uint8_t v;
	};
};


/// Pre-defined hue values for HSV objects
typedef enum {
	HUE_RED = 0,
	HUE_ORANGE = 32,
	HUE_YELLOW = 64,
	HUE_GREEN = 96,
	HUE_AQUA = 128,
	HUE_BLUE = 160,
	HUE_PURPLE = 192,
	HUE_PINK = 224
} HSVHue;


struct CRGB {
	union {
		uint8_t r;
		uint8_t red;
	};
	union {
		uint8_t g;
		uint8_t green;
	};
	union {
		uint8_t b;
		uint8_t blue;
	};

	CRGB( uint8_t ir, uint8_t ig, uint8_t ib)
        : r(ir), g(ig), b(ib)
    {
    }
};

#endif
