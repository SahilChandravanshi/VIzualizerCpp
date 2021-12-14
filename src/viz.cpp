// C++ program for visualization of bubble sort

#include "graphics.h"
#include <bits/stdc++.h>

using namespace std;

// Initialize the size
// with the total numbers to sorted
// and the gap to be maintained in graph
vector<int> numbers;
int size = 200;
int gap = 4;

// Function for swapping the lines graphically
void swap(int i, int j, int x, int y)
{
    // Swapping the first line with the correct line
    // by making it black again and then draw the pixel
    // for white color.

    setcolor(GREEN);
    line(i, size, i, size - x);
    setcolor(BLACK);
    line(i, size, i, size - x);
    setcolor(WHITE);
    line(i, size, i, size - y);

    // Swapping the first line with the correct line
    // by making it black again and then draw the pixel
    // for white color.
    setcolor(GREEN);
    line(j, size, j, size - y);
    setcolor(BLACK);
    line(j, size, j, size - y);
    setcolor(WHITE);
    line(j, size, j, size - x);
}

// Bubble sort function
void bubbleSort()
{
    int temp, i, j;

    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;

                // As we swapped the last two numbers
                // just swap the lines with the values.
                // This is function call
                // for swapping the lines
                swap(gap * j + 1,
                     gap * (j + 1) + 1,
                     numbers[j + 1],
                     numbers[j]);
            }
        }
    }
}

// Driver program
int main()
{

    // auto detection of screen size
    int gd = DETECT, gm;
    int wid1;

    // Graph initialization
    initgraph(&gd, &gm, NULL);

    // setting up window size (gap*size) * (size)
    wid1 = initwindow(gap * size + 1, size + 1);
    setcurrentwindow(wid1);

    // Initializing the array
    for (int i = 1; i <= size; i++)
        numbers.push_back(i);

    // Find a seed and shuffle the array
    // to make it random.
    // Here  different type of array
    // can be taken to results
    // such as nearly sorted, already sorted,
    // reverse sorted to visualize the result
    unsigned seed = chrono::system_clock::now()
                        .time_since_epoch()
                        .count();

    shuffle(numbers.begin(),
            numbers.end(),
            default_random_engine(seed));

    // Initial plot of numbers in graph taking
    // the vector position as x-axis and its
    // corresponding value will be the height of line.
    for (int i = 1; i <= gap * size; i += gap)
    {
        line(i, size, i, (size - numbers[i / gap]));
    }

    // Delay the code
    delay(200);

    // Call sort
    bubbleSort();

    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Wait for sometime .
    delay(5000);

    // Close the graph
    closegraph();

    return 0;
}