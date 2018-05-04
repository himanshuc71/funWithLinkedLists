#include "block.h"
#include <iostream>

int Block::width() const{
   return data[0].size();
}
int Block::height() const{
   return data.size();
}

void Block::render(PNG & im, int upLeftX, int upLeftY) const {
   for (int i = upLeftY; i < upLeftY + height(); i++) {
     for (int j = upLeftX; j < upLeftX + width(); j++) {
       HSLAPixel* currPixel = im.getPixel(j,i);
       *currPixel = data[i-upLeftY][j-upLeftX];
     }
   }
   return;
}

void Block::build(PNG & im, int upLeftX, int upLeftY, int cols, int rows) {
   for (int i = upLeftY; i < upLeftY + rows; i++) {
     std::vector<HSLAPixel> v;
     for (int j = upLeftX; j < upLeftX + cols; j++) {
       HSLAPixel* pix = im.getPixel(j,i);
       v.push_back(*pix);
     }
     data.push_back(v);
   }
   return;
}
