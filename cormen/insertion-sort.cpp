#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr = {3, 9, 7, 8, 6, 4, 0, 5, 2, 1};
	for(int i = 1; i < arr.size(); i++) {
		int j = i-1;
		int key = arr[i];
		while(arr[j] > key && j >= 0) {
			cout << i << "-" << j << "\n";
			int temp = arr[j];
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	cout << "arr = [";
	for(int i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i == arr.size() - 1) {
			cout << "]\n";
		} else {
			cout << ", ";
		}
	}
	cout << "\n";
}
