#ifndef QUEUEDS_HPP
#define QUEUEDS_HPP

#include "Pixel.hpp"

// queue of pixels (FIFO), made with pointers.
// insert at the rear, remove at the front. no cout / cin in here
class QueueDS
{
    Pixel* frontElem;  // first node (leaves first)
    Pixel* rearElem;   // last node (new pixels go after it)
    int size;

public:
    QueueDS();
    ~QueueDS();

    void enqueue(Pixel p_pixel);  // add at the rear
    Pixel dequeue();              // take the front pixel out (and delete its node)
    bool isEmpty();
    int getSize();
};

#endif // QUEUEDS_HPP
