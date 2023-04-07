#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int peakfinder(int* arr, int p) {
        if(arr[p] >= arr[p-1] && arr[p] >= arr[p+1]) {
                return p;
        }
        else if (arr[p] <= arr[p-1]) {
        cout << "next is position is " << p-1 << "\n";
                return peakfinder(arr, p-1);     
        } else if (arr[p] <= arr[p+1]) {
        cout << "next is position is " << p+1 << "\n";
                return peakfinder(arr, p+1);
        } return -1;
}

int main() {
        srand((unsigned) time(NULL));
        int size = rand() % 9; // 1 to 9 pseudo-random value
        int* arr = new int[size];

        for (int i=0;i<size;i++) {
                int random = rand() % 10; // 0 to 9 pseudo-random value
                cout << "pos[" << i << "]: " << random << "\n";
                arr[i] = random;
        }

        int half = size/2;
        int peak = peakfinder(arr, half);
        cout << peak << "is the peak\n";
        delete[] arr;
        return 0;
}
