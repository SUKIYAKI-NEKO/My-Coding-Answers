/*
主題: 198. House Robber
來源: https://leetcode.com/problems/house-robber/description/
內容: Dynamic Programming
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==2)if(nums[0]>=nums[1])return nums[0];
        else return nums[1];
        if(nums.size()==1)return nums[0];
        nums[2]+=nums[0];
        for(int i=3;i<nums.size();i++){
            if(nums[i-2]>=nums[i-3])nums[i]+=nums[i-2];
            else nums[i]+=nums[i-3];
        }
        if(nums[nums.size()-1]>nums[nums.size()-2])return nums[nums.size()-1];
        else return nums[nums.size()-2]; 
    }
};
// Runtime: 0 ms  Memory: 10.18 MB
