#include "QueueDS.hpp"

QueueDS::QueueDS()
{
    frontElem = nullptr;
    rearElem = nullptr;
    size = 0;
}

// delete all the nodes that are still in the queue
QueueDS::~QueueDS()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

// the new node goes after the rear
void QueueDS::enqueue(Pixel p_pixel)
{
    Pixel* newElem = new Pixel(p_pixel.getRed(), p_pixel.getGreen(), p_pixel.getBlue());

    if (isEmpty())
    {
        // only one node -> it is front and rear at the same time
        frontElem = newElem;
    }
    else
    {
        rearElem->setNext(newElem);
    }
    rearElem = newElem;
    size++;
}

// returns a copy of the front pixel and deletes the node
Pixel QueueDS::dequeue()
{
    Pixel result;

    if (frontElem != nullptr)
    {
        Pixel* oldFront = frontElem;
        result = Pixel(oldFront->getRed(), oldFront->getGreen(), oldFront->getBlue());
        frontElem = oldFront->getNext();
        delete oldFront;
        size--;

        // queue empty now -> rear must not point to the deleted node
        if (frontElem == nullptr)
        {
            rearElem = nullptr;
        }
    }

    return result;
}

bool QueueDS::isEmpty()
{
    return frontElem == nullptr;
}

int QueueDS::getSize()
{
    return size;
}
