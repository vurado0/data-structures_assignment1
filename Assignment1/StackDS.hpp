#ifndef STACKDS_HPP
#define STACKDS_HPP

#include "Pixel.hpp"

// stack of pixels (LIFO), made with pointers. Insert and remove only at the top.
// no cout / cin in here
class StackDS
{
    Pixel* topElem;  // nullptr if the stack is empty
    int size;

public:
    StackDS();
    ~StackDS();

    void push(Pixel p_pixel);  // copy the colour into a new node on the top
    Pixel pop();               // take the top pixel out (and delete its node)
    Pixel top();               // look at the top pixel without removing it
    bool isEmpty();
    int getSize();
};

#endif // STACKDS_HPP
