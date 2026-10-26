#include "Core.hpp"

Core::Core()
{
    fileName = "";
    baseName = "";
    width = 0;
    height = 0;
}

Core::~Core()
{
    std::cout << "Releasing the memory... done." << std::endl;
}

void Core::run()
{
    std::cout << "=== DATA STRUCTURES - ASSIGNMENT 1 ===" << std::endl;

    if (stage1LoadImage())
    {
        stage2TestImage();
        stage3Manipulation();
        stage4Menu();
    }
}

// STAGE 1: ask the name of the image, load it and push every pixel into the stack
bool Core::stage1LoadImage()
{
    bool loaded = false;
    bool quit = false;

    std::cout << std::endl << "--- STAGE 1: loading the image ---" << std::endl;

    // ask again until the image can be loaded (or the user types q)
    while (!loaded && !quit)
    {
        std::cout << "Name of the BMP image (q to quit): ";
        std::cin >> fileName;

        // q, or no more input (Ctrl+D) -> stop asking
        if (fileName == "q" || std::cin.fail())
        {
            quit = true;
        }
        else
        {
            TinyImageJM image(fileName);  // the teacher's library reads the file

            if (image.loadImageFromDisk())
            {
                loaded = true;
                pushPixelsFromImage(image);
            }
            else
            {
                std::cout << "  Could not load it: " << image.getInternalError() << std::endl;
            }
        }
    }

    if (loaded)
    {
        Pixel topPixel = pixelStack.top();
        std::cout << "  Image: " << width << " x " << height << " = " << width * height << " pixels" << std::endl;
        std::cout << "  Pixels in the stack: " << width * height << ", top (= last pixel of the file): ("
                  << (int)topPixel.getRed() << "," << (int)topPixel.getGreen() << "," << (int)topPixel.getBlue()
                  << ")" << std::endl;
    }

    return loaded;
}

// reads the size and every pixel of the loaded image and pushes the pixels into the stack
void Core::pushPixelsFromImage(TinyImageJM& p_image)
{
    width = p_image.getWidth();
    height = p_image.getHeight();
    baseName = fileName.substr(0, fileName.find_last_of('.'));
    unsigned char* bytes = p_image.getImagePointertoInternal();

    // every pixel has 3 bytes in the order Blue, Green, Red.
    // we push them in the same order as in the file (BMP starts with the bottom row)
    for (int i = 0; i < width * height; i++)
    {
        pixelStack.push(Pixel(bytes[i * 3 + 2], bytes[i * 3 + 1], bytes[i * 3]));
    }
}

// STAGE 2: pop all pixels to write a copy of the image (<name>_test.bmp).
// Every popped pixel goes into a helper stack and back at the end,
// so the stack is the same as before.
void Core::stage2TestImage()
{
    StackDS helper;
    int index = width * height - 1;  // the top is the LAST pixel of the file
    int popped = 0;
    int pushedBack = 0;
    std::string outName = baseName + "_test.bmp";

    std::cout << std::endl << "--- STAGE 2: test image ---" << std::endl;

    // the library loads the image again and makes the memory for the pixels itself,
    // we only overwrite the pixels (no array of our own on the heap)
    TinyImageJM output(fileName);
    output.loadImageFromDisk();
    unsigned char* bytes = output.getImagePointertoInternal();

    // pop until the stack is empty
    while (!pixelStack.isEmpty())
    {
        Pixel pixel = pixelStack.pop();
        bytes[index * 3] = pixel.getBlue();
        bytes[index * 3 + 1] = pixel.getGreen();
        bytes[index * 3 + 2] = pixel.getRed();
        helper.push(pixel);
        index--;
        popped++;
    }
    std::cout << "  " << popped << " pixels popped and pushed into the helper stack" << std::endl;

    // put everything back -> same order as at the start
    while (!helper.isEmpty())
    {
        pixelStack.push(helper.pop());
        pushedBack++;
    }

    saveImage(output, outName);
    std::cout << "  " << pushedBack << " pixels pushed back, the stack is like at the start" << std::endl;
}

// STAGE 3: stack -> 6 stacks -> queue -> list of lists -> new image
void Core::stage3Manipulation()
{
    std::cout << std::endl << "--- STAGE 3: data structure manipulation ---" << std::endl;

    std::cout << "  Step 1: pixels distributed into the 6 stacks" << std::endl;
    distributeToStacks();

    fillQueue();
    std::cout << "  Step 2: queue filled with " << pixelQueue.getSize() << " pixels" << std::endl;

    // check with isEmpty() that the 6 stacks were emptied completely
    bool allEmpty = true;
    for (int i = 0; i < 6; i++)
    {
        if (!stacks[i].isEmpty())
        {
            allEmpty = false;
        }
    }
    if (allEmpty)
    {
        std::cout << "    all 6 stacks are empty now" << std::endl;
    }
    else
    {
        std::cout << "    ERROR: not all stacks are empty" << std::endl;
    }

    fillListOfLists();
    std::cout << "  Step 3: list of lists has " << imageList.getNumRows() << " rows of " << width
              << " pixels (queue now: " << pixelQueue.getSize() << ")" << std::endl;

    saveListAsImage(baseName + "_stage3.bmp");
}

// the rules of the assignment, the counter starts with 1.
// the order of the ifs matters: 6 is divisible by 2 and by 3, but the first rule wins -> stack 1
int Core::chooseStack(int p_pixelNumber)
{
    int stackNumber = 6;  // "otherwise"

    if (p_pixelNumber == 1 || p_pixelNumber % 2 == 0)
    {
        stackNumber = 1;
    }
    else if (p_pixelNumber % 3 == 0)
    {
        stackNumber = 2;
    }
    else if (p_pixelNumber % 5 == 0)
    {
        stackNumber = 3;
    }
    else if (p_pixelNumber % 7 == 0)
    {
        stackNumber = 4;
    }
    else if (p_pixelNumber % 11 == 0)
    {
        stackNumber = 5;
    }

    return stackNumber;
}

// take every pixel out of the main stack and put it into one of the 6 stacks
// the stacks do not know their size, so we count here how many pixels go into each one
void Core::distributeToStacks()
{
    int pixelNumber = 1;
    int counter[6] = { 0, 0, 0, 0, 0, 0 };  // pixels per stack (only for the output)

    while (!pixelStack.isEmpty())
    {
        int index = chooseStack(pixelNumber) - 1;  // -1: the array starts at 0
        stacks[index].push(pixelStack.pop());
        counter[index]++;
        pixelNumber++;
    }

    std::cout << "    pixels per stack: ";
    for (int i = 0; i < 6; i++)
    {
        std::cout << "S" << (i + 1) << "=" << counter[i] << "  ";
    }
    std::cout << std::endl;
}

// position 1 and every even position -> from stack 1
// odd positions -> from stack 6 until it is empty, then 5, 4, 3, 2
void Core::fillQueue()
{
    int total = width * height;

    for (int position = 1; position <= total; position++)
    {
        Pixel pixel;

        if ((position == 1 || position % 2 == 0) && !stacks[0].isEmpty())
        {
            pixel = stacks[0].pop();
        }
        else
        {
            pixel = popFromOddStacks();
        }
        pixelQueue.enqueue(pixel);
    }
}

// first stack that is not empty, starting with stack 6 (index 5) and going down.
// if 6..2 are all empty the loop stops at index 0 (stack 1)
Pixel Core::popFromOddStacks()
{
    int index = 5;

    while (index > 0 && stacks[index].isEmpty())
    {
        index--;
    }
    Pixel result = stacks[index].pop();

    return result;
}

// the first "width" pixels of the queue are row 0, the next "width" are row 1, ...
void Core::fillListOfLists()
{
    for (int y = 0; y < height; y++)
    {
        RowListDS* row = new RowListDS();  // deleted by the destructor of imageList

        for (int x = 0; x < width; x++)
        {
            row->insertEnd(pixelQueue.dequeue());
        }
        imageList.addRow(row);
    }
}

// write the list of lists to a file, row by row.
// we only READ the nodes with pointers (nothing in the list is changed)
// and WRITE the colours into the memory of the output image
void Core::saveListAsImage(std::string p_fileName)
{
    TinyImageJM output(fileName);  // the library makes the memory for the pixels
    output.loadImageFromDisk();
    unsigned char* bytes = output.getImagePointertoInternal();
    int index = 0;
    RowListDS* row = imageList.getFirstRow();

    while (row != nullptr)
    {
        index = writeRowToBytes(row, bytes, index);
        row = row->getNextRow();
    }

    saveImage(output, p_fileName);
}

// READS the pixels of one row with pointers and WRITES them into p_bytes,
// starting at pixel number p_index. returns the number of the next free pixel.
int Core::writeRowToBytes(RowListDS* p_row, unsigned char* p_bytes, int p_index)
{
    int index = p_index;
    Pixel* pixel = p_row->getFirst();

    while (pixel != nullptr)
    {
        p_bytes[index * 3] = pixel->getBlue();
        p_bytes[index * 3 + 1] = pixel->getGreen();
        p_bytes[index * 3 + 2] = pixel->getRed();
        index++;
        pixel = pixel->getNext();
    }

    return index;
}

// writes the image to a file with the teacher's library
void Core::saveImage(TinyImageJM& p_image, std::string p_fileName)
{
    remove(p_fileName.c_str());  // the library does not overwrite old files

    if (p_image.saveImageToDisk(p_fileName) == 0)
    {
        std::cout << "  Image saved: " << p_fileName << std::endl;
    }
    else
    {
        std::cout << "  ERROR: could not save " << p_fileName << std::endl;
    }
}

// ---------------------------------------------------------------
// STAGE 4: menu
// the options only READ the list of lists with pointers and WRITE the
// result into the memory of a new image -> the list of lists is never changed
// ---------------------------------------------------------------
void Core::stage4Menu()
{
    int option = 0;

    do
    {
        std::cout << std::endl << "--- STAGE 4: menu ---" << std::endl;
        std::cout << "  1. Search pixels by colour" << std::endl;
        std::cout << "  2. Sort the pixels of every row (insertion sort)" << std::endl;
        std::cout << "  3. Image reconstruction (flop: mirror left <-> right)" << std::endl;
        std::cout << "  4. Exit" << std::endl;
        option = askNumber("Option: ", 1, 4);

        if (option == 1)
        {
            searchPixels();
        }
        else if (option == 2)
        {
            sortRows();
        }
        else if (option == 3)
        {
            flopImage();
        }
        else
        {
            std::cout << "  Exit: all the memory is released now." << std::endl;
        }
    } while (option != 4);
}

// MENU 1: print the coordinates (x,y) of every pixel with the colour typed by the user.
// x = position in the row, y = row counted from the TOP of the picture
// (the BMP file starts with the bottom row, so we turn the row number around)
void Core::searchPixels()
{
    int found = 0;
    int y = 0;

    std::cout << "  Colour to search:" << std::endl;
    int red = askNumber("    Red   (0-255): ", 0, 255);
    int green = askNumber("    Green (0-255): ", 0, 255);
    int blue = askNumber("    Blue  (0-255): ", 0, 255);

    std::cout << "  Pixels with colour (" << red << "," << green << "," << blue << "):" << std::endl << "  ";

    RowListDS* row = imageList.getFirstRow();
    while (row != nullptr)
    {
        Pixel* pixel = row->getFirst();
        int x = 0;

        while (pixel != nullptr)
        {
            if (pixel->getRed() == red && pixel->getGreen() == green && pixel->getBlue() == blue)
            {
                std::cout << "(" << x << "," << (height - 1 - y) << ") ";
                found++;

                // 10 coordinates per line, so the list stays short
                if (found % 10 == 0)
                {
                    std::cout << std::endl << "  ";
                }
            }
            pixel = pixel->getNext();
            x++;
        }
        row = row->getNextRow();
        y++;
    }

    std::cout << std::endl << "  " << found << " pixel(s) found" << std::endl;
}

// MENU 2: sort the pixels of every row by R, G or B with INSERTION SORT.
// every row is read with pointers and its pixels are inserted into a NEW list
// (sortedRow), so the list of lists stays as it was at the start.
void Core::sortRows()
{
    char component = askComponent();
    TinyImageJM output(fileName);  // the library makes the memory for the pixels
    output.loadImageFromDisk();
    unsigned char* bytes = output.getImagePointertoInternal();
    int index = 0;
    std::string outName = baseName + "_sorted_" + component + ".bmp";

    RowListDS* row = imageList.getFirstRow();
    while (row != nullptr)
    {
        RowListDS sortedRow;  // new list, it is deleted automatically at the end of each loop

        // read every pixel of the row and insert it at its place in the new list
        Pixel* pixel = row->getFirst();
        while (pixel != nullptr)
        {
            sortedRow.insertSorted(*pixel, component);
            pixel = pixel->getNext();
        }

        // show the first row as an example
        if (row == imageList.getFirstRow())
        {
            printRowValues(row, component, "first row before");
            printRowValues(&sortedRow, component, "first row after ");
        }

        index = writeRowToBytes(&sortedRow, bytes, index);  // write the sorted row into the new image
        row = row->getNextRow();
    }

    std::cout << "  " << imageList.getNumRows() << " rows sorted by " << component
              << " (the list of lists was not changed)" << std::endl;
    saveImage(output, outName);
}

// MENU 3: image reconstruction = FLOP (mirror across a vertical axis).
// the pixel in column x is written into column (width - 1 - x) of the same row,
// so the left and the right side are swapped. the list of lists is only read.
/*void Core::flopImage()
{
    TinyImageJM output(fileName);  // the library makes the memory for the pixels
    output.loadImageFromDisk();
    unsigned char* bytes = output.getImagePointertoInternal();
    int y = 0;

    RowListDS* row = imageList.getFirstRow();
    while (row != nullptr)
    {
        Pixel* pixel = row->getFirst();
        int x = 0;

        while (pixel != nullptr)
        {
            int index = y * width + (width - 1 - x);  // mirrored column
            bytes[index * 3] = pixel->getBlue();
            bytes[index * 3 + 1] = pixel->getGreen();
            bytes[index * 3 + 2] = pixel->getRed();
            pixel = pixel->getNext();
            x++;
        }
        row = row->getNextRow();
        y++;
    }

    std::cout << "  Flop: pixel (x, y) -> (" << width - 1 << " - x, y), " << imageList.getNumRows()
              << " rows mirrored (the list of lists was not changed)" << std::endl;
    saveImage(output, baseName + "_flop.bmp");
}

// prints the first 12 values (only the chosen colour) of a row
void Core::printRowValues(RowListDS* p_row, char p_component, std::string p_title)
{
    int count = 0;
    Pixel* pixel = p_row->getFirst();

    std::cout << "  " << p_title << " (" << p_component << "): ";
    while (pixel != nullptr && count < 12)
    {
        std::cout << pixel->getComponent(p_component) << " ";
        pixel = pixel->getNext();
        count++;
    }
    std::cout << "..." << std::endl;
}*/

void Core::flopImage()
{
    QueueDS reconstructionQueue;
    StackDS reverseOrder[6];
    StackDS reconstructedStacks[6];
    int remaining[6] = { 0, 0, 0, 0, 0, 0 };
    int total = width * height;

    // Count the pixels originally assigned to each stack.
    for (int pixelNumber = 1; pixelNumber <= total; pixelNumber++)
    {
        int stackIndex = chooseStack(pixelNumber) - 1;
        remaining[stackIndex]++;
    }

    // Copy the list of lists into a queue in its current order.
    RowListDS* row = imageList.getFirstRow();

    while (row != nullptr)
    {
        Pixel* pixel = row->getFirst();

        while (pixel != nullptr)
        {
            reconstructionQueue.enqueue(*pixel);
            pixel = pixel->getNext();
        }

        row = row->getNextRow();
    }

    // Reverse the queue-filling step and route pixels back to their stacks.
    for (int position = 1; position <= total; position++)
    {
        int stackIndex = -1;

        if ((position == 1 || position % 2 == 0) && remaining[0] > 0)
        {
            stackIndex = 0;
        }
        else
        {
            stackIndex = 5;

            while (stackIndex >= 0 && remaining[stackIndex] == 0)
            {
                stackIndex--;
            }
        }

        if (stackIndex >= 0)
        {
            reverseOrder[stackIndex].push(reconstructionQueue.dequeue());
            remaining[stackIndex]--;
        }
    }

    // Reverse each stack's removal order to restore its original contents.
    for (int stackIndex = 0; stackIndex < 6; stackIndex++)
    {
        while (!reverseOrder[stackIndex].isEmpty())
        {
            reconstructedStacks[stackIndex].push(reverseOrder[stackIndex].pop());
        }
    }

    TinyImageJM output(fileName);
    output.loadImageFromDisk();
    unsigned char* bytes = output.getImagePointertoInternal();

    // Recreate the original file order, writing each pixel to its mirrored column.
    for (int pixelNumber = total; pixelNumber >= 1; pixelNumber--)
    {
        int stackIndex = chooseStack(pixelNumber) - 1;
        Pixel pixel = reconstructedStacks[stackIndex].pop();

        int originalIndex = total - pixelNumber;
        int rowIndex = originalIndex / width;
        int columnIndex = originalIndex % width;
        int mirroredIndex = rowIndex * width + (width - 1 - columnIndex);

        bytes[mirroredIndex * 3] = pixel.getBlue();
        bytes[mirroredIndex * 3 + 1] = pixel.getGreen();
        bytes[mirroredIndex * 3 + 2] = pixel.getRed();
    }

    std::cout << "  Flop: original image reconstructed and mirrored left to right"
              << std::endl;
    saveImage(output, baseName + "_flop.bmp");
}

// asks for a number until it is a number between p_min and p_max
int Core::askNumber(std::string p_text, int p_min, int p_max)
{
    int number = p_min - 1;

    while (number < p_min || number > p_max)
    {
        std::cout << p_text;
        std::cin >> number;

        if (std::cin.eof())
        {
            // no more input (Ctrl+D) -> take the last value (in the menu: Exit)
            number = p_max;
        }
        else if (std::cin.fail())
        {
            // letters instead of a number -> clean cin and ask again
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            number = p_min - 1;
        }

        if (number < p_min || number > p_max)
        {
            std::cout << "  Please type a number from " << p_min << " to " << p_max << std::endl;
        }
    }

    return number;
}

// asks R, G or B until the answer is correct (small letters are ok too)
char Core::askComponent()
{
    char component = ' ';

    while (component != 'R' && component != 'G' && component != 'B')
    {
        std::cout << "  Sort by which colour? (R/G/B): ";
        std::cin >> component;

        if (std::cin.eof())
        {
            component = 'R';  // no more input -> take R
        }
        component = toupper(component);
    }

    return component;
}

