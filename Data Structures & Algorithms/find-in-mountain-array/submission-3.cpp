/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();
        int left = 1;
        int right = length - 2;
        int peak = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            int l = mountainArr.get(mid - 1);
            int m = mountainArr.get(mid);
            int r = mountainArr.get(mid + 1);
            if(l < m && m < r){
                left = mid + 1;
            }
            else if( l > m && m > r){
                right = mid - 1;
            }
            else{
                peak = mid;
                break;
            }
        } 
        int tar_left = 0;
        int tar_right = peak - 1;
        while(tar_left <= tar_right){
            int mid = tar_left + (tar_right - tar_left)/2;
            int curr = mountainArr.get(mid);
            if(curr == target){
                return mid;
            } 
            else if(curr < target){
                tar_left = mid + 1;
            }
            else{
                tar_right = mid - 1; 
            }
        }
        tar_left = peak;
        tar_right = length - 1;
        while(tar_left <= tar_right){
            int mid = tar_left + (tar_right - tar_left)/2;
            int curr = mountainArr.get(mid);
            if(curr == target){
                return mid;
            } 
            else if(curr > target){
                tar_left = mid + 1;
            }
            else{
                tar_right = mid - 1; 
            }
        }
        
        return -1; 
    }
};