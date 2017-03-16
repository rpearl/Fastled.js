#include <emscripten/bind.h>
#include "color.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(color) {
	class_<CHSV>("CHSV")
		.constructor<uint8_t, uint8_t, uint8_t>()
		.property("hue", &CHSV::hue)
		.property("sat", &CHSV::sat)
		.property("val", &CHSV::val)
		;

	class_<CRGB>("CRGB")
		.constructor<uint8_t, uint8_t, uint8_t>()
		.class_function("fromColorCode", &CRGB::fromColorCode)
		.class_function("fromHSV", &CRGB::fromHSV)
		.property("r", &CRGB::r)
		.property("g", &CRGB::g)
		.property("b", &CRGB::b)

		.function("setHSV", &CRGB::setHSV)
		.function("setHue", &CRGB::setHue)
		.function("setColorCode", &CRGB::setColorCode)
		;
}
