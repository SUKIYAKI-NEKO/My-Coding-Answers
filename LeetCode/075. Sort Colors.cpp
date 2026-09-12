// https://leetcode.com/problems/sort-colors/description/

// Medium

// Topics:
// Array 、 three Pointers 、 Sorting 、 Insertion Sort 、 Three-Color Flag

// Description:
// You are given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// Submission 1(line 26): 
// Insertion Sort
// Accepted
// Runtiime: 0 ms  Memory: 11.67 MB

// Submission 2(line 52):
// Learn : https://leetcode.com/problems/sort-colors/solutions/6751648/6-sorting-methods-with-images-cpythonjav-phsy/
// Three-Color Flag
// Accepted
// Runtiime: 0 ms  Memory: 11.78 MB




// Submission 1:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            int n=i;
            while(n>0){
                if(nums[n]<nums[n-1]){
                    int a=nums[n];
                    nums[n]=nums[n-1];
                    nums[n-1]=a;
                }
                else break;
                n--;
            }
        }
        return;
    }
};






// Submission 2:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int f=0,m=0,b=nums.size()-1;
        while(m<=b){
            if(nums[m]==0){
                int a=nums[m];
                nums[m]=nums[f];
                nums[f]=a;
                m=f+1;
                f++;
            }
            else if(nums[m]==2){
                int a=nums[m];
                nums[m]=nums[b];
                nums[b]=a;
                b--;
            }
            else m++;
        }
        return;
    }
};
