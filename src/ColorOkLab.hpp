#ifndef __COLOROKLAB_HPP__
#define __COLOROKLAB_HPP__

class ColorRGB;

// ######################
// ## ColorOkLab class ##
// ######################
class ColorOkLab {
public:
    double L;
    double a;
    double b;

public:
    // Constructors
    ColorOkLab() = default;
    ColorOkLab(double L, double a, double b) : L(L), a(a) , b(b) {}

    // Convert to other color space
    ColorRGB to_RGB();
};

#endif