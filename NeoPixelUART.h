#ifndef NEOPIXELUART_H
#define NEOPIXELUART_H

#include <vector>
#include <cstdint>
#include "ThreadHelpers.h"

class ColorRGB
{
	double r, g, b;
public:
	ColorRGB(double r = 0, double g = 0, double b = 0) : r(r), g(g), b(b) {}
	uint32_t toHEX() const;
};

class Serial
{
	int out;
	void setupInterface(unsigned baud_rate);
public:
	Serial(const std::string portname, const unsigned baud_rate);
	~Serial();
	void write(const uint8_t *data, const unsigned size);
};


class AdressingLEDstrip
{
	Serial out;

	std::vector<uint8_t> encode(const uint32_t color_hex);
public:
	AdressingLEDstrip(
		const std::string portname = "/dev/ttyUSB0",
		const unsigned baud_rate = 2400000
	);
	//~AdressingLEDstrip();

	// uint32_t rgb2hex(const double r, const double g, const double b);
	// uint32_t hsv2hex(const double r, const double g, const double b);
	void setLEDsHEX(const std::vector<uint32_t> &led_colors_hex);
	void setLEDs(const std::vector<ColorRGB> &led_colors);
};



#endif // NEOPIXELUART_H 