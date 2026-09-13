// 09/13/2026
// https://leetcode.com/problems/n-th-tribonacci-number/description/


// Easy

// Topics:
// Junior 、 Math 、 Dynamic Programming 、 Memoization 、 Weekly Contest 147

// Description:
// The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

// Submission:
// Original solution - written by me
// Accepted
// Runtime: 0 ms  Memory: 8.24 MB


// Submission

class Solution {
public:
    int tribonacci(int n) {
        
        vector<int>v1;
        v1.push_back(0);
        v1.push_back(1);
        v1.push_back(1);
        if(n<3)return v1[n]; 
        for(int i=3;i<=n;i++){
            v1.push_back(v1[i-1]+v1[i-2]+v1[i-3]);
        }
        return v1[n];
    }
};




//end
