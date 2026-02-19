#include <iostream>
#include <vector>

using VecInt = std::vector<int>;

// Overloading the << operator to print the contents of the vector
std::ostream &operator<<(std::ostream &out, const VecInt &arr)
{
    for (auto &i : arr)
    {
        out << i << " ";
    }
    return out;
}

// Bubble Sort Algorithm
// Time Complexity: O(n^2) in worst and average case, O(n) in best case (when the array is already sorted)
// Space Complexity: O(1) - in-place sorting algorithm
// Implementation: it uses 2 for loops; the outer loop iterates through the array,
//      while the inner loop compares adjacent elements and swaps them if they are in the wrong order.
//      The process is repeated until the entire array is sorted, with an optimization to break early
//      if no swaps were made in a pass, indicating that the array is already sorted.

void bubbleSort(VecInt &arr)
{
    for (int i=0; i<arr.size()-1; ++i)
    {
        bool swapped {false};
        for (int j=i+1; j<arr.size(); ++j)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop,
        // then the array is already sorted
        if (not swapped)
        {
            break;
        }
    }
}

int main()
{
    //VecInt arr {0,1,2,3,4,5,6,7};
    VecInt arr {6,2,5,4,3,0,7,1};
    
    std::cout << "i/p: " << arr << std::endl;

    bubbleSort(arr);

    std::cout << "o/p: " << arr << std::endl;
}
