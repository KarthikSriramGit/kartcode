class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int left = 0;
        int right = 0;
        while(left < nums1.size() && right < nums2.size()){
            if(nums1[left] < nums2[right]){
                merged.push_back(nums1[left]);
                left++;
            }
            else{
                merged.push_back(nums2[right]);
                right++;
            }
        }
        while(left < nums1.size()){
            merged.push_back(nums1[left]);
            left++;
        }
        while(right < nums2.size()){
            merged.push_back(nums2[right]);
            right++;
        }
        int p1 = 0;
        int p2 = merged.size() - 1;
        int mid = p1 + (p2 - p1)/2;
        if(merged.size() % 2 == 0){
            return (double(merged[mid]) + merged[mid + 1])/2.0;
        }
        else{
            return double(merged[mid]);
        }
    }
};
