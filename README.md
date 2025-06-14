# oklab-visualiser

This repo contains an oklab color space visualiser.

## OkLab color space

OkLab is a color space described by 3 numbers :
- L : luminosity, bounded between [0, 1]
- a, b : hues, bounded in a weird shape

OkLab was designed to be easier to compute and to improve perceptual uniformity. This means that distance in color points are more uniform:
- OkLab(0.3, 0.2, 0.1) and OkLab(0.3, 0.2, 0.2) are just as different as OkLab(0.3, 0.2, 0.1) and OkLab(0.3, 0.2, 0)

However, it is a bit difficult to visualise what these values correspond to in sRGB space, the color space used in the overwhelmingly majority of devices.
This repo contains images representing the colors in OkLab for any given luminosity. This tool allows to visualise what corresponding (a, b) values would map to real sRGB values.

## Bypassing invalid values

When a OkLab color is mapped to an invalid sRGB color, there are multiple ways to bypass and still use the color. We propose a few methods:
- Clipping : easy but loses color information
- Tonemapping : this methods handles values that are above 1, but doesn't take care of negative values
- Color correction : Negative colors are impossible to represent. However, we could still represent the relations between colors: As such, if a color is impossible to represent, we will represent it by shifting all other colors, effectively performing a color correction. This method requires an initial pass to get the most shifted colors.



## Reference

- Original post : https://bottosson.github.io/posts/oklab/
- Wikipedia article : https://en.wikipedia.org/wiki/Oklab_color_space