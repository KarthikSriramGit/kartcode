class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = m + n - 1;
        int right2 = n - 1;
        while(right2 >= 0){
            if(left >= 0 && nums1[left] > nums2[right2]){
                nums1[right] = nums1[left];
                left--;
            }
            else{
                nums1[right] = nums2[right2];
                right2--;
            }
            right--;
        }
    }
};