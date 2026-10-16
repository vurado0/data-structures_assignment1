#ifndef ROWLISTDS_HPP
#define ROWLISTDS_HPP

#include "Pixel.hpp"

// list with the pixels of ONE row of the image.
// it also points to the next row, so the list of lists does not need an extra node class.
// first AND last pointer: insertEnd in O(1), and later the insertion sort can append fast at the end.
class RowListDS
{
    Pixel* first;
    Pixel* last;
    int size;
    RowListDS* nextRow;

public:
    RowListDS();
    ~RowListDS();

    void insertEnd(Pixel p_pixel);

    Pixel* getFirst();  // to READ the row: start here and follow getNext() until nullptr
    int getSize();
    bool isEmpty();

    RowListDS* getNextRow();
    void setNextRow(RowListDS* p_nextRow);
};

#endif // ROWLISTDS_HPP
