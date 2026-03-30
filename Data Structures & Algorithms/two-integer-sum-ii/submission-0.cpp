class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> result;
        while(left < right){
            int curSum = numbers[left] + numbers[right];
            if(curSum == target){
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }
            else if(curSum < target){
                left++;
            }
            else if(curSum > target){
                right--;
            }
        }
        return result;
    }
};
