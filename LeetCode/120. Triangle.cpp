/*
Problem: 120. Triangle
Source: https://leetcode.com/problems/triangle/
Description: Dynamic Programming
*/
//Runtime: 0 ms   Memory: 12.49 MB

class Solution {
public:
    int min(int a,int b){
        if(a>=b)return b;
        return a;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0)triangle[i][j]+=triangle[i-1][j];
                else if(j==triangle[i].size()-1)triangle[i][j]+=triangle[i-1][triangle[i-1].size()-1];
                else triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }
        int ans=triangle[triangle.size()-1][0];
        for(int i=1;i<triangle[triangle.size()-1].size();i++)ans=min(ans,triangle[triangle.size()-1][i]);
        return ans;
    }
};
