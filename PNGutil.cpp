#include <iostream>
#include <cmath>
#include <cstdlib>

#include "cs221util/PNG.h"
#include "cs221util/HSLAPixel.h"
#include "PNGutil.h"

using namespace cs221util;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
   for (unsigned x = 0; x < image.width(); x++) {
      for (unsigned y = 0; y < image.height(); y++) {
         HSLAPixel *pixel = image.getPixel(x, y);
         pixel->s = 0;
      }
   }

   return image;
}

/**
 * Returns a image transformed to UBC colors.
 *
 * The hue of every pixel is set to the a hue value of either yellow or
 * blue, based on if the pixel's hue value is closer to yellow than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The UBCify'd image.
**/
PNG ubcify(PNG image) {
for (unsigned x = 0; x < image.width(); x++) {
   for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel *pixel = image.getPixel(x, y);
      if (fabs(pixel->h -60) <fabs (pixel->h -240)) {
        pixel->h=40;
      }
      else
        pixel->h = 210;
   }
}
return image;
}
