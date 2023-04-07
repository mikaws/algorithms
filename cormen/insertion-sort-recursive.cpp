#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(vector<int> arr, int j, int key)
{
        if (arr[j] > key && j >= 0)
        {
                int temp = arr[j];
                arr[j+1] = arr[j];
		return sort(arr, j-1, key);
        }
        arr[j+1] = key;
	return arr;
}

vector<int> insertion_sort(vector<int> arr, int i, int end)
{
	if (i >= end) return arr;
	int j = i-1;
	int key = arr[i];
	arr = sort(arr, j, key);
	return insertion_sort(arr, i+1, end);
}


int main()
{
        vector<int> arr = {3, 9, 7, 8, 6, 4, 0, 5, 2, 1};
	arr = insertion_sort(arr, 0, arr.size());
        cout << "arr = [";
        for(int i = 0; i < arr.size(); i++)
	{
                cout << arr[i];
                if (i == arr.size() - 1) { cout << "]\n"; }
        	else { cout << ", "; }
        }
        cout << "\n";
}
