#include "ColorOkLab.hpp"

#include <ColorRGB.hpp>

// ###########################
// ## ColorOkLab conversion ##
// ###########################
ColorRGB ColorOkLab::to_RGB() {
    double l = L + 0.3963377774*a + 0.2158037573*b;
    double m = L - 0.1055613458*a - 0.0638541728*b;
    double s = L - 0.0894841775*a - 1.2914855480*b;

    l = l*l*l;
    m = m*m*m;
    s = s*s*s;

    return ColorRGB(
         4.0767416621*l - 3.3077115913*m + 0.2309699292*s,
        -1.2684380046*l + 2.6097574011*m - 0.3413193965*s,
        -0.0041960863*l - 0.7034186147*m + 1.7076147010*s
    );
}