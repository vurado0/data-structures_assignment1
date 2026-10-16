#ifndef CORE_HPP
#define CORE_HPP

#include <cstdio>   // remove()
#include <cstdlib>  // malloc()
#include <iostream>
#include <string>

#include "ImageListDS.hpp"
#include "QueueDS.hpp"
#include "StackDS.hpp"
#include "peque-image-manager/TinyImageJM.hpp"

// Core = controls the program. All cin / cout and the file access are here,
// never inside the data structures.
class Core
{
    std::string fileName;  // for example "house_200x150.bmp"
    std::string baseName;  // the same without ".bmp" (for the output names)
    int width;
    int height;
    StackDS pixelStack;    // stage 1: all the pixels of the image
    StackDS stacks[6];     // stage 3: stacks[0] is "stack 1" ... stacks[5] is "stack 6"
    QueueDS pixelQueue;    // stage 3: the pixels in the new order
    ImageListDS imageList; // stage 3: list of lists (rows)

    bool stage1LoadImage();
    void pushPixelsFromImage(TinyImageJM& p_image);
    void stage2TestImage();
    void stage3Manipulation();

    // stage 3 step by step
    int chooseStack(int p_pixelNumber);
    void distributeToStacks();
    void fillQueue();
    Pixel popFromOddStacks();
    void fillListOfLists();
    void saveListAsImage(std::string p_fileName);

    // helpers
    void saveImage(unsigned char* p_bytes, std::string p_fileName);
    void printStackSizes();

public:
    Core();
    ~Core();
    void run();
};

#endif // CORE_HPP
