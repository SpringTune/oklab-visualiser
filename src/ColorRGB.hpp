#ifndef __COLORRGB_HPP__
#define __COLORRGB_HPP__

#include <cmath>
#include <cstdint>

class ColorOkLab;

// ####################
// ## ColorRGB class ##
// ####################
class ColorRGB {
public:
    double r;
    double g;
    double b;

public:
    // Constructors
    ColorRGB() = default;
    ColorRGB(double r, double g, double b) : r(r), g(g) , b(b) {}
    
    // Get color as u8
    uint8_t r_u8() { return uint8_t(r*255); }
    uint8_t g_u8() { return uint8_t(g*255); }
    uint8_t b_u8() { return uint8_t(b*255); }

    // Color operations
    void exposure(double value);
    void brightness(double value);
    void contrast(double value);
    void saturation(double value);
    void filter(ColorRGB color);
    void gamma_correct(double gamma);
    void clamp(double min, double max);
    void invalidate();

    // Convert to other color space
    ColorOkLab to_OkLab();
};

#endif