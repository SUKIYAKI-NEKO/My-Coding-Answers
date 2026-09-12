// https://leetcode.com/problems/single-number/description/

// Easy

// Topics:
// Array 、 Bit Manipulation

// Description:
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.


// Submission1(line 28):
// Original solution - written by me
// Approach: map
// Accepted
// Runtime: 12 ms Memory: 24.5 MB


// Submission2(line 46):
// Learn from https://www.youtube.com/watch?v=nMC78grcvGw (Leetcode Solutions)
// Approach: XOR (If the inputs are different, the result is true (1); if they are the same, the result is false (0).)
// Accepted
// Runtime: 0 ms Memory: 20.75 MB



// Submission 1:

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mpa;
        int ans=0;
        for(auto t:nums) mpa[t]++;
        
        for(auto i=mpa.begin();i!=mpa.end();i++)
            if(i->second==1)return i->first;
        mpa.clear();
            return ans;
    }
};



// Submissipn 2:

// a ^ a = 0\
// a ^ 0 = a
// a ^ b = b ^ a
// ( a ^ b ) ^ c = a ^ ( b ^ c )

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto i:nums)ans^=i;
        return ans;
    }
};








//end
