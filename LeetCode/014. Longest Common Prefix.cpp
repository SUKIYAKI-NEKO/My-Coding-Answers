// 09/13/2026
// https://leetcode.com/problems/longest-common-prefix/description/

// Easy

// Topics:
// Array 、 String 、 Trie

// Description:
// Write a function to find the longest common prefix string amongst an array of strings.

// Submission:
// Original solution - written by me
// Accepted
// Runtime: 0 ms  Memory: 11.86 MB


//Submission

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        string re;
        bool ch=true;
        bool lch=true;
        for(int i=0;i<strs[0].size();i++){
            if(ch==false){
                re="";
                lch=true;
                ch=0;
            }
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size()){
                    ch=false;
                    break;
                }
                if(strs[0][i]!=strs[j][i]){
                    ch=0;
                    break;
                }
            }
            if(ch)re+=strs[0][i];
            if(re.size()>ans.size() && ch==true)ans=re;
            if(lch==false)break;
        }
        return ans;
    }
};



//end
