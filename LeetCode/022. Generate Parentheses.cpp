// 09/13/2026
// https://leetcode.com/problems/generate-parentheses/description/

// Medium

// Topics:
// String 、 Dynamic Programming 、 Backtracking 、 Bracket Sequences

// Description:
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Submission:
// Accepted
// Original solution - written by me
// Approach : Backtracking
// Runtime: 0 ms  Memory: 13.40 MB


// Submission:

class Solution {
public:
    string s;
    vector<string>v;
    void generateback(int a,int b,int n,int nums){
        if(s.length()==n*2){
            v.push_back(s);
            nums++;
            return;
        }
        if(a<n){
            s+='(';
            a++;
            generateback(a,b,n,nums);
            s.pop_back();
            a--;
        }
        if(b<a){
            s+=')';
            b++;
            generateback(a,b,n,nums);
            s.pop_back();
            b--;
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        generateback(0,0,n,0);
        return v;
    }
};





// end
