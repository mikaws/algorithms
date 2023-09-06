#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &arr)
{
        for (int i = 0; i < arr.size(); i++)
        {
                for (int j = arr.size() - 1; j > i; j--)
                {
                        if (arr[j] < arr[j - 1])
                        {
                                int temp = arr[j];
                                arr[j] = arr[j - 1];
                                arr[j - 1] = temp;
                        }
                }
        }
}

int main()
{
        std::vector<int> arr = {9, 8, 7, 6};
        bubble_sort(arr);
        return 0;
}
