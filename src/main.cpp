#include <Framebuffer.hpp>
#include <ColorOkLab.hpp>

#include <cstdio>
#include <format>

// Draw OKLab color space at L, (a, b) = [-0.5, 0.5]^2
void draw_oklab(Framebuffer& framebuffer, double L) {
    for (double y = 0; y < framebuffer.height; y++) {    
        for (double x = 0; x < framebuffer.width; x++) {
            ColorRGB color = ColorOkLab(
                L,
                0.5*2*(x/framebuffer.width - 0.5),
                0.5*2*(y/framebuffer.height - 0.5)
            ).to_RGB();
            
            // Remove invalid values
            // In practice, these could be clipped, or tonemapped.
            // At the very least something needs to be done for negative values.
            color.invalidate();

            // Apply gamma correction
            color.gamma_correct(1/2.2);
            color.clamp(0, 1);
    
            framebuffer[x + y*framebuffer.width] = color;
        }
    }
}


int main() {

    // Create Framebuffer
    Framebuffer framebuffer = Framebuffer(800, 600);

    // Draw and save to file
    for (double L = 0; L < 1; L += 0.05) {
        draw_oklab(framebuffer, L);
        framebuffer.save_ppm(std::format("../data/oklab_L{:.2f}.ppm", L));
    }
    return 0;
}