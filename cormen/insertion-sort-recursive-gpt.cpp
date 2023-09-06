/**
 * This is not my code. It was did by ChatGPT for studying purposes
*/

#include <iostream>
#include <vector>

void recursive_insertion_sort(std::vector<int> &arr, int n)
{
    if (n <= 1)
        return;
    recursive_insertion_sort(arr, n - 1);
    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
}

int main()
{
    std::vector<int> arr = {5, 2, 4, 6, 1, 3};
    int n = arr.size();
    recursive_insertion_sort(arr, n);
    return 0;
}
