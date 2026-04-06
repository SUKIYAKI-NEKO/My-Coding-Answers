/*
Problem: 63. Unique Paths II
Source: https://leetcode.com/problems/unique-paths-ii/description/
Description: Dynamic Programming
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> v(m,vector<int>(n,0));
        bool ch=false;
        for(int i=0;i<obstacleGrid[0].size();i++)
            if(obstacleGrid[0][i]==0 && !ch)v[0][i]=1;
            else {
                v[0][i]=0;
                ch=true;
            }
        ch=false;
        for(int i=0;i<obstacleGrid.size();i++)
            if(obstacleGrid[i][0]==0 && !ch)v[i][0]=1;
            else {
                v[i][0]=0;
                ch=true;
            }
        for(int i=1;i<obstacleGrid.size();i++) for(int j=1;j<obstacleGrid[0].size();j++)
            if(obstacleGrid[i][j]==0 )v[i][j]=v[i-1][j]+v[i][j-1];
        return v[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
//Runtime: 0 ms   Memory: 12.00 MB 
