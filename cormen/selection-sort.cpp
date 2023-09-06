#include <iostream>
#include <vector>

void selection_sort(std::vector<int> &arr)
{
        for (int i = 0; i < arr.size(); i++)
        {
                int minIndex = i;
                for (int j = i + 1; j < arr.size(); j++)
                {
                        if (arr[minIndex] > arr[j])
                        {
                                minIndex = j;
                        }
                }
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
        }
}

int main()
{
        std::vector<int> arr = {9, 8, 7, 6};
        selection_sort(arr);
        return 0;
}
