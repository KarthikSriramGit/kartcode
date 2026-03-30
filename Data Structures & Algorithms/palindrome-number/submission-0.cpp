class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        vector<int> num;
        while(x){
            num.push_back(x % 10);
            x /= 10;
        }
        int left = 0, right = num.size() - 1;
        while(left < right){
            if(num[left] != num[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};