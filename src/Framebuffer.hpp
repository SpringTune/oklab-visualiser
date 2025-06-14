#ifndef __FRAMEBUFFER_HPP__
#define __FRAMEBUFFER_HPP__

#include <ColorRGB.hpp>

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

// #######################
// ## Framebuffer class ##
// #######################
class Framebuffer {
public:
    int16_t width;
    int16_t height;
    std::vector<ColorRGB> framebuffer;

public:
    // Constructor
    Framebuffer(int16_t width, int16_t height) :
        width(width),
        height(height),
        framebuffer(std::vector<ColorRGB>(width*height)) {}

    // Buffer operations
    ColorRGB& operator[](int index) { return framebuffer[index]; }

    // Iterators
    std::vector<ColorRGB>::iterator begin() { return framebuffer.begin(); }
    std::vector<ColorRGB>::iterator end()   { return framebuffer.end(); }

    // File I/O
    void save_ppm(std::string filepath) {
        // Open file
        FILE* f = fopen(filepath.c_str(), "w");
        if (f == nullptr) return;

        // Write signature
        fprintf(f, "P6\n");
        fprintf(f, "%d %d\n", width, height);
        fprintf(f, "255\n");

        // Write framebuffer data
        for (ColorRGB color : framebuffer) {
            uint8_t color_buffer[3] = {
                color.r_u8(),
                color.g_u8(),
                color.b_u8()
            };
            fwrite(color_buffer, 3, 1, f);
        }

        // Close file
        fclose(f);
    }
};

#endif