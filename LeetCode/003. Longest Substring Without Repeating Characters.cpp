/*
Problem: 3. Longest Substring Without Repeating Characters
Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Description: Sliding Window
*/
//Runtime 0 ms   Memory: 11.27 MB


class Solution {
public:
    int max(int a,int b){
        if(a>b)return a;
        return b;
    }
    int lengthOfLongestSubstring(string s) {
        int ma=0;
        int b=0;
        std::vector<int> v(130,0);
        for(int i=0;i<s.length();i++){
            int cf=(int)s[i];
            v[cf]++;
            while(v[cf]>1){
                int cb=(int)s[b];
                v[cb]--;
                b++;
            }
            ma=max(ma,i-b+1);
        }
        return ma;
    }
};
