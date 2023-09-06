#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int l, int mid, int h)
{
    int nLeft = mid - l + 1;
    int nRight = h - mid;
    std::vector<int> leftArr(nLeft);
    std::vector<int> rightArr(nRight);
    for (int i = 0; i < nLeft; i++)
        leftArr[i] = arr[l + i];
    for (int i = 0; i < nRight; i++)
        rightArr[i] = arr[mid + i + 1];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < nLeft && j < nRight)
    {
        if (leftArr[i] < rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while (i < nLeft)
        arr[k++] = leftArr[i++];
    while (j < nRight)
        arr[k++] = rightArr[j++];
}

void mergeSort(std::vector<int> &arr, int l, int h)
{
    if (l >= h)
        return;
    int mid = (l + h) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, h);
    merge(arr, l, mid, h);
}

bool hasPairWithSum(std::vector<int> &arr, int num)
{
    mergeSort(arr, 0, arr.size() - 1);
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        int currentSum = arr[left] + arr[right];
        if (currentSum == num)
        {
            std::cout << "Pair found: " << arr[left] << " + " << arr[right] << " = " << num << std::endl;
            return true;
        }
        else if (currentSum < num)
            left++;
        else
            right--;
    }

    return false;
};

int main()
{
    std::vector<int> arr = {93, 1, 926, 829, 137, 323, 212, 728, 3, 538, 190};
    int num = 4;
    hasPairWithSum(arr, num);
    return 0;
}
