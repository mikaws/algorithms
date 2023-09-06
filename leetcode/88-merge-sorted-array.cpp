#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
	std::cout << m << n << "\n";
	std::vector<int> nums3(m + n);
	int i = 0;
        int j = 0;
        int k = 0;
        if(!nums2.size()) {
	    return;
	}
        if(!nums1.size()) {
            nums1 = nums2;
            return;
        }
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                nums3[k++] = nums1[i++];
            } else {
                nums3[k++] = nums2[j++];
            }
        }
        for(i; i < m; i++) {
            nums3[k++] = nums1[i];
        }
        for(j; j < n; j++) {
            nums3[k++] = nums2[j];
        }

        nums1 = nums3; 
    }
};

int main() {
	Solution solution;
	std::vector<int> sums1 = {1,2,3,0,0,0};
	std::vector<int> sums2 = {2,5,6};
	solution.merge(sums1, 3, sums2, 3);
	for (int i = 0; i < sums1.size(); i++) {
		std::cout << "sums[" << i << "] = " << sums1[i] << "\n";
	}
	return 0;
}
