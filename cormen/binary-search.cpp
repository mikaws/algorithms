#include <iostream>
#include <vector>

int binary_search(std::vector<int> arr, int n, int l, int h)
{
        while (l <= h)
        {
                int mid = (l + h) / 2;
                if (n == arr[mid])
                        return mid;
                else if (n > arr[mid])
                        l = mid + 1;
                else
                        h = mid - 1;
        }

        return -1;
}

int main()
{
        std::vector<int> arr = {0, 3, 7, 21, 33, 47, 53, 64, 88, 91, 97};
        int number, size;
        std::cout << "insert the element you want to search(0 to 10): ";
        std::cin >> number;
        int position = binary_search(arr, number, 0, arr.size() - 1);
        if (position == -1)
                std::cout << "\nelement not found\n";
        else
                std::cout << "\nyour element is at position " << position << "\n";
        return 0;
}
