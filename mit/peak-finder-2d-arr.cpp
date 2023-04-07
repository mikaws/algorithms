#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <array>

using namespace std;

int peak_finder_y(std::array<std::array<int, 11>, 11> arr, int size_a, int px, int py) {
	if(px == 0 || px == size_a) {
		return px;
	} else if(arr[px][py] > arr[px-1][py] && arr[px][py] > arr[px+1][py]) {
                return px;
        } else if (arr[px][py] <= arr[px-1][py]) {
                return peak_finder_y(arr, size_a, px-1, py);
        } else if (arr[px][py] <= arr[px+1][py]) {
                return peak_finder_y(arr, size_a, px+1, py);
        } return -1;
}

int get_highest_y(std::array<std::array<int, 11>, 11> arr, int px, int py) {
	if(arr[px][py+1] > arr[px][py-1]) {
		return py+1;
	} else {
		return py-1;
	}
}

int is_peak(std::array<std::array<int, 11>, 11> arr, int px, int py) {
	if(arr[px][py] > arr[px-1][py] && arr[px][py] > arr[px+1][py] && arr[px][py] > arr[px][py+1] && arr[px][py] > arr[px][py-1]) {
                return 1;
        } else {
		return 0;
	}
}

void peak_finder(std::array<std::array<int, 11>, 11> arr, int size_a, int px, int py) {
	int peak = peak_finder_y(arr, size_a, px, py);
	if(is_peak(arr, peak, py)) {
                cout << "the peak is arr[" << peak << "][" << py << "]\n";
        	return;
	}
	int next_y = get_highest_y(arr, px, py);
	if(arr[peak][next_y] > arr[peak][py]) {
		return peak_finder(arr, size_a, peak, next_y);
	}
}

int main() {
	srand((unsigned) time(NULL));
	int size_a = 11;
	std::array<std::array<int, 11>, 11> arr {{
		{ 4,  5,  6,  7,  8,  7,  6,  5,  4,  3,  2},
		{ 5,  6,  7,  8,  9,  8,  7,  6,  5,  4,  3},
		{ 6,  7,  8,  9, 10,  9,  8,  7,  6,  5,  4},
		{ 7,  8,  9, 10, 11, 10,  9,  8,  7,  6,  5},
		{ 8,  9, 10, 11, 12, 11, 10,  9,  8,  7,  6},
		{ 7,  8,  9, 10, 11, 10,  9,  8,  7,  6,  5},
		{ 6,  7,  8,  9, 10,  9,  8,  7,  6,  5,  4},
		{ 5,  6,  7,  8,  9,  8,  7,  6,  5,  4,  3},
		{ 4,  5,  6,  7,  8,  7,  6,  5,  4,  3,  2},
		{ 3,  4,  5,  6,  7,  6,  5,  4,  3,  2,  1},
		{ 2,  3,  4,  5,  6,  5,  4,  3,  2,  1,  0}
	}};
	int start = size_a/2;
	peak_finder(arr, size_a, start, start);
	return 0;
}
