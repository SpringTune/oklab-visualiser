#include "ColorRGB.hpp"

#include <ColorOkLab.hpp>

#include <cmath>

// ###############################
// ## ColorRGB color operations ##
// ###############################
void ColorRGB::exposure(double value) {
    r *= value;
    g *= value;
    b *= value;
}

void ColorRGB::brightness(double value) {
    r += value;
    g += value;
    b += value;
}

void ColorRGB::contrast(double value) {
    r = value*(r - 0.5) + 0.5;
    g = value*(g - 0.5) + 0.5;
    b = value*(b - 0.5) + 0.5;
}

void ColorRGB::saturation(double value) {
    double med_white = (r + g + b) / 3;
    r = (1-value)*med_white + value*r;
    g = (1-value)*med_white + value*g;
    b = (1-value)*med_white + value*b;
}

void ColorRGB::filter(ColorRGB color) {
    r *= color.r;
    g *= color.g;
    b *= color.b;
}

void ColorRGB::gamma_correct(double gamma) {
    r = std::pow(r, gamma);
    g = std::pow(g, gamma);
    b = std::pow(b, gamma);
}

void ColorRGB::clamp(double min, double max) {
    if (r < min) r = min; if (r > max) r = max;
    if (g < min) g = min; if (g > max) g = max;
    if (b < min) b = min; if (b > max) b = max;
}

void ColorRGB::invalidate() {
    if (r < 0 || 1 < r || g < 0 || 1 < g || b < 0 || 1 < b) {
        r = 0; g = 0; b = 0;
    }
}


// #########################
// ## ColorRGB conversion ##
// #########################
ColorOkLab ColorRGB::to_OkLab() {
    double l = 0.4122214708*r + 0.5363325363*g + 0.0514459929*b;
    double m = 0.2119034982*r + 0.6806995451*g + 0.1073969566*b;
    double s = 0.0883024619*r + 0.2817188376*g + 0.6299787005*b;

    l = std::pow(l, 1/3);
    m = std::pow(m, 1/3);
    s = std::pow(s, 1/3);

    return ColorOkLab(
        0.2104542553*l + 0.7936177850*m - 0.0040720468*s,
        1.9779984951*l - 2.4285922050*m + 0.4505937099*s,
        0.0259040371*l + 0.7827717662*m - 0.8086757660*s
    );
}