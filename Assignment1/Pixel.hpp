#ifndef PIXEL_HPP
#define PIXEL_HPP

// Pixel = one node of our linked structures.
// It has only the colour (no coordinates, the assignment asks for that)
// and a pointer to the next pixel.
class Pixel
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    Pixel* next;

public:
    Pixel();
    Pixel(unsigned char p_red, unsigned char p_green, unsigned char p_blue);

    unsigned char getRed();
    unsigned char getGreen();
    unsigned char getBlue();

    Pixel* getNext();
    void setNext(Pixel* p_next);
};

#endif // PIXEL_HPP
