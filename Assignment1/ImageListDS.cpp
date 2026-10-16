#include "ImageListDS.hpp"

ImageListDS::ImageListDS()
{
    firstRow = nullptr;
    lastRow = nullptr;
    numRows = 0;
}

// delete every row (the destructor of the row deletes its pixels)
ImageListDS::~ImageListDS()
{
    while (firstRow != nullptr)
    {
        RowListDS* toDelete = firstRow;
        firstRow = firstRow->getNextRow();
        delete toDelete;
    }
}

// the new row goes after the last one
void ImageListDS::addRow(RowListDS* p_row)
{
    if (firstRow == nullptr)
    {
        firstRow = p_row;
    }
    else
    {
        lastRow->setNextRow(p_row);
    }
    lastRow = p_row;
    numRows++;
}

RowListDS* ImageListDS::getFirstRow()
{
    return firstRow;
}

int ImageListDS::getNumRows()
{
    return numRows;
}
