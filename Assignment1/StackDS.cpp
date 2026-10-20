#include "StackDS.hpp"

StackDS::StackDS()
{
    topElem = nullptr;
}

// delete all the nodes that are still in the stack
StackDS::~StackDS()
{
    while (!isEmpty())
    {
        pop();
    }
}

// the new node points to the old top and becomes the new top
void StackDS::push(Pixel p_pixel)
{
    Pixel* newElem = new Pixel(p_pixel.getRed(), p_pixel.getGreen(), p_pixel.getBlue());
    newElem->setNext(topElem);
    topElem = newElem;
}

// returns a copy of the top pixel and deletes the node
// (empty stack -> black pixel, but we always check isEmpty() before)
Pixel StackDS::pop()
{
    Pixel result;

    if (topElem != nullptr)
    {
        Pixel* oldTop = topElem;
        result = Pixel(oldTop->getRed(), oldTop->getGreen(), oldTop->getBlue());
        topElem = oldTop->getNext();
        delete oldTop;
    }

    return result;
}

Pixel StackDS::top()
{
    Pixel result;

    if (topElem != nullptr)
    {
        result = Pixel(topElem->getRed(), topElem->getGreen(), topElem->getBlue());
    }

    return result;
}

bool StackDS::isEmpty()
{
    return topElem == nullptr;
}
