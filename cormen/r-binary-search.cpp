#include <iostream>
#include <vector>

int binary_search(std::vector<int> arr, int n, int low, int high)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (n == arr[mid])
			return mid;
		else if (n > arr[mid])
		{
			return binary_search(arr, n, mid + 1, high);
		}
		else
		{
			return binary_search(arr, n, low, mid - 1);
		}
	}

	return -1;
}

int main()
{
	std::vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int number, size;
	std::cout << "insert the element you want to search(0 to 10): ";
	std::cin >> number;
	int position = binary_search(arr, number, 0, arr.size() - 1);
	if (position == -1)
	{
		std::cout << "\nelement not found\n";
	}
	else
	{
		std::cout << "\nyour element is at position " << position << "\n";
	}
	return 0;
}
