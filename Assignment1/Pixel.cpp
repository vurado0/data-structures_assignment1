#include "Pixel.hpp"

// black pixel
Pixel::Pixel()
{
    red = 0;
    green = 0;
    blue = 0;
    next = nullptr;
}

Pixel::Pixel(unsigned char p_red, unsigned char p_green, unsigned char p_blue)
{
    red = p_red;
    green = p_green;
    blue = p_blue;
    next = nullptr;
}

unsigned char Pixel::getRed()
{
    return red;
}

unsigned char Pixel::getGreen()
{
    return green;
}

unsigned char Pixel::getBlue()
{
    return blue;
}

Pixel* Pixel::getNext()
{
    return next;
}

void Pixel::setNext(Pixel* p_next)
{
    next = p_next;
}
