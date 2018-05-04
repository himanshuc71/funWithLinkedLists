
#ifndef HSLA_PIXEL
#define HSLA_PIXEL

class HSLAPixel{
public:
    double h;
    double s;
    double l;
    double a;

    HSLAPixel();
    HSLAPixel(double th, double ts, double tl);
    HSLAPixel(double th, double ts, double tl, double ta);

};

#endif
