
#include "HSLAPixel.h"

HSLAPixel::HSLAPixel(){
    h = 1.0;
    s = 0.0;
    l = 1.0;
    a = 1.0;
}
HSLAPixel::HSLAPixel(double th, double ts, double tl){
    h = th;
    s = ts;
    l = tl;
    a = 1.0;
}
HSLAPixel::HSLAPixel(double th, double ts, double tl, double ta){
    h = th;
    s = ts;
    l = tl;
    a = ta;
}
