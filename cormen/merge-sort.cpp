#include <iostream>
#include <vector>

void merge(int* arr, int l, int mid, int h) {
        int nLeft = mid - l + 1;
        int nRight = h - mid;
        int leftArr[nLeft];
        int rightArr[nRight];
        for(int i = 0; i < nLeft; i++) {
                leftArr[i] = arr[l + i];
        }
        for(int i = 0; i < nRight; i++) {
                rightArr[i] = arr[mid + i + 1];
        }
        int i = 0;
        int j = 0;
        int k = l;
        while(i < nLeft && j < nRight) {
                if (leftArr[i] < rightArr[j]) {
                        arr[k++] = leftArr[i++];
                } else {
                        arr[k++] = rightArr[j++];
                }
        }
        while(i < nLeft) {
                arr[k++] = leftArr[i++];
        }
        while(j < nRight) {
                arr[k++] = rightArr[j++];
        }
}

void merge_sort(int* arr, int l, int h) {
        if (l < h) {
                int mid = (l + h) / 2;
                merge_sort(arr, l, mid);
                merge_sort(arr, mid + 1, h);
                merge(arr, l, mid, h);
        }
}

int main() {
        int arr[8] = {9, 3, 7, 5, 6, 4, 8, 2};
        merge_sort(arr, 0, 8);
	return 0;
}
