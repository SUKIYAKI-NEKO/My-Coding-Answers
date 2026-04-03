/*
Two Sum
source: https://leetcode.com/problems/two-sum/description/
context: hash
*/

//first:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a,b;
        for(a=0;a<nums.size();a++){
            for(b=0;b<nums.size();b++){
                if(a==b) continue;
                if(nums[a]+nums[b]== target)return {a,b};
            }
        }
        return {};
    }
};
//Runtime: 144 ms  Memory: 14.15 MB

//second:
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
//Runtime: 1 ms  Memory: 14.89 MB

//third:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nums_map;
        for(int i=0;i<nums.size();i++){
            int com=target - nums[i];
            auto t=nums_map.find(com);
            if(t!=nums_map.end())return {nums_map[com],i};
            nums_map[nums[i]]=i;
        }
        return {};
    }
};
//Runtime: 0 ms  Memory: 14.89 MB