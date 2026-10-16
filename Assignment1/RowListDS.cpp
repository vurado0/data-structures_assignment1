#include "RowListDS.hpp"

RowListDS::RowListDS()
{
    first = nullptr;
    last = nullptr;
    size = 0;
    nextRow = nullptr;
}

// delete every pixel node of the row (not the next row, the list of lists does that)
RowListDS::~RowListDS()
{
    while (first != nullptr)
    {
        Pixel* toDelete = first;
        first = first->getNext();
        delete toDelete;
    }
}

// the new node goes after the last one
void RowListDS::insertEnd(Pixel p_pixel)
{
    Pixel* newElem = new Pixel(p_pixel.getRed(), p_pixel.getGreen(), p_pixel.getBlue());

    if (isEmpty())
    {
        first = newElem;
    }
    else
    {
        last->setNext(newElem);
    }
    last = newElem;
    size++;
}

Pixel* RowListDS::getFirst()
{
    return first;
}

int RowListDS::getSize()
{
    return size;
}

bool RowListDS::isEmpty()
{
    return first == nullptr;
}

RowListDS* RowListDS::getNextRow()
{
    return nextRow;
}

void RowListDS::setNextRow(RowListDS* p_nextRow)
{
    nextRow = p_nextRow;
}
