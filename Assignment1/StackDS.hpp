#ifndef STACKDS_HPP
#define STACKDS_HPP

#include "Pixel.hpp"

// stack of pixels (LIFO), made with pointers. Insert and remove only at the top.
// the stack does not count its pixels: to empty it we pop while it is not empty.
// no cout / cin in here
class StackDS
{
    Pixel* topElem;  // nullptr if the stack is empty

public:
    StackDS();
    ~StackDS();

    void push(Pixel p_pixel);  // copy the colour into a new node on the top
    Pixel pop();               // take the top pixel out (and delete its node)
    Pixel top();               // look at the top pixel without removing it
    bool isEmpty();
};

#endif // STACKDS_HPP
