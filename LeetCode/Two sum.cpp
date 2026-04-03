/*
Two Sum
source:
context:
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nums_map;
        for(int i=0;i<nums.size();i++){
            int com=target - nums[i];
            if(nums_map.count(com))return {nums_map[com],i};
            nums_map[nums[i]]=i;
        }
        return {};
    }
};
