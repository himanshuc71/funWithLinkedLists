#include "block.h"
#include <iostream>

int Block::width() const{
   /* your code here */
   return data.size();
}
int Block::height() const{
   /* your code here */
   return data[0].size();
}

void Block::render(PNG & im, int upLeftX, int upLeftY) const {
   for (int i = upLeftX; i < height(); i++) {
     std::cout<<"line 14"<<std::endl;
     for (int j = upLeftY; j < width(); j++) {
       HSLAPixel* currPixel = im.getPixel(i,j);
       *currPixel = data[i-upLeftX][j-upLeftY];
       std::cout<<"line 18"<<std::endl;
     }
   }
   return;
}

void Block::build(PNG & im, int upLeftX, int upLeftY, int cols, int rows) {
   for (int i = upLeftX; i < rows; i++) {
     std::vector<HSLAPixel> v;
     std::cout<<"line 27"<<std::endl;
     for (int j = upLeftY; j < cols; j++) {
       HSLAPixel* pix = im.getPixel(i,j);
       v.push_back(*pix);
       std::cout<<"line 31"<<std::endl;
     }
     data.push_back(v);
   }
   std::cout<<"line 36"<<std::endl;
   return;
}
