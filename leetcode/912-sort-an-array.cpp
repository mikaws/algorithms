class Solution {
public:
    void merge(std::vector<int>& arr, int l, int mid, int h) {
        int nLeft = mid - l + 1;
        int nRight = h - mid;
        std::vector<int> leftArr(nLeft);
        std::vector<int> rightArr(nRight);
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

    void mergeSort(std::vector<int>& nums, int l, int h) {
        if(l < h) {
            int mid = (l + h)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, h);
            this->merge(nums, l, mid, h);
        }
    }

    std::vector<int> sortArray(std::vector<int>& nums) {
        this->mergeSort(nums, 0, nums.size() -1);
        return nums;
    }
};
