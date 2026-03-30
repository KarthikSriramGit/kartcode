class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) { // [1,3,2,3,2], 3
        sort(people.begin(), people.end()); // [ 1, 2, 2, 3, 3]
        int left = 0; 
        int right = people.size()-1;
        int count = 0;
        while(left <= right){
            if(left < right && people[left] + people[right] <= limit){
                left++;
                right--;
            }
            else if(people[right] <= limit){
                right--;
            }
            count++;
        }
        return count;
    }
};