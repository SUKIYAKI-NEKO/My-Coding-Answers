// https://leetcode.com/problems/combinations/description/

// Medium

// Topics:
// Backtracking


// Description :
// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// You may return the answer in any order.

// Submission (line 20):
// Accepted
// Original solution - written by me
// Runtime: 71 ms  Memory: 82.46 MB



// Submission :

class Solution {
public:
    vector<vector<int>> v;
    void combination(int s,int k ,vector<int>& cpv ,vector<int>& num){
        if(s>num.size())return;
        if(cpv.size()==k){
            v.push_back(cpv);
            return;
        }

        for(int i=s;i<num.size();i++){
            cpv.push_back(num[i]);
            combination(i+1,k,cpv,num);
            cpv.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {

        vector<int> cpv;
        vector<int> num;
        for(int i=0;i<n;i++)num.push_back(i+1);
        combination(0,k,cpv,num);
        return v;
    }
};
