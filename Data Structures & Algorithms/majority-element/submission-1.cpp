class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxfreq = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            maxfreq = max(maxfreq, freq[nums[i]]);
            if(freq[nums[i]] == maxfreq){
                res = nums[i];
            }
        }
        return res;
    }
};