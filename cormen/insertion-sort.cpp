#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& arr) {
	for(int i = 1; i < arr.size(); i++) {
		int j = i-1;
		int key = arr[i];
		while(arr[j] > key && j >= 0) {
			int temp = arr[j];
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main() {
	std::vector<int> arr = {3, 9, 7, 8, 6, 4, 0, 5, 2, 1};
	insertion_sort(arr);
	return 0;
}
