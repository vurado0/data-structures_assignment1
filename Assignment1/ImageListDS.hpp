#ifndef IMAGELISTDS_HPP
#define IMAGELISTDS_HPP

#include "RowListDS.hpp"

// list of lists: the rows of the image (row number = y, position in the row = x).
// the list owns its rows: they are deleted in the destructor.
class ImageListDS
{
    RowListDS* firstRow;
    RowListDS* lastRow;
    int numRows;

public:
    ImageListDS();
    ~ImageListDS();

    void addRow(RowListDS* p_row);  // the row must be created with new

    RowListDS* getFirstRow();  // to READ the list: start here and follow getNextRow() until nullptr
    int getNumRows();
};

#endif // IMAGELISTDS_HPP
