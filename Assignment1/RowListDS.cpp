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

// INSERTION SORT: the new pixel is put at its correct place, so the list is always
// sorted from small to big by the chosen colour ('R', 'G' or 'B').
// pixels with the same value keep their order (the new one goes after them) -> stable
void RowListDS::insertSorted(Pixel p_pixel, char p_component)
{
    Pixel* newElem = new Pixel(p_pixel.getRed(), p_pixel.getGreen(), p_pixel.getBlue());
    int value = p_pixel.getComponent(p_component);

    if (isEmpty())
    {
        // first pixel of the list
        first = newElem;
        last = newElem;
    }
    else if (value < first->getComponent(p_component))
    {
        // smaller than all -> new first node
        newElem->setNext(first);
        first = newElem;
    }
    else if (value >= last->getComponent(p_component))
    {
        // bigger or equal than all -> at the end (fast, no walking)
        last->setNext(newElem);
        last = newElem;
    }
    else
    {
        // walk until the next pixel is bigger, then link the new node in between
        Pixel* previous = first;
        while (previous->getNext()->getComponent(p_component) <= value)
        {
            previous = previous->getNext();
        }
        newElem->setNext(previous->getNext());
        previous->setNext(newElem);
    }
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
