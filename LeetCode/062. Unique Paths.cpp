/*
主題: 62. Unique Paths
source: https://leetcode.com/problems/unique-paths/description/
內容: Dynamic Programming
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int map[101][101];
        for(int i=0;i<m;i++)map[0][i]=1;
        for(int i=0;i<n;i++)map[i][0]=1;
        for(int i=1;i<n;i++)for(int j=1;j<m;j++)map[i][j]=map[i-1][j]+map[i][j-1];
        return map[n-1][m-1];
    }
};
//Runtime: 0 ms  Memory: 8.13 MB
