/*
Problem: 931. Minimum Falling Path Sum
Source: https://leetcode.com/problems/minimum-falling-path-sum/description/
Description: Dynamic Programming
*/
//Runtime: 0 ms   Memory: 14.11 MB


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int min=matrix[i-1][j];
                if(j>0)
                    if(matrix[i-1][j-1]<min)min=matrix[i-1][j-1];
                if(j<matrix[i].size()-1)
                    if(matrix[i-1][j+1]<min)min=matrix[i-1][j+1];
                matrix[i][j]+=min;
            }
        }
        int mi=matrix[matrix.size()-1][0];
        for(int i=1;i<matrix[matrix.size()-1].size();i++)
            if(matrix[matrix.size()-1][i]<mi)mi=matrix[matrix.size()-1][i];
        return mi;
    }
};
