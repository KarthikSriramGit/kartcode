class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = left + k - 1;
        vector<int> result;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1){
                result.push_back(nums[dq.front()]);
                if(dq.front() == i - k + 1){
                   dq.pop_front();
                }

            }
        }
        return result;
    }
};