/*
主題: 746. Min Cost Climbing Stairs
來源: https://leetcode.com/problems/min-cost-climbing-stairs/
內容: Dynamic Programming
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=2;i<cost.size();i++){
            if(cost[i-2]>=cost[i-1])cost[i]+=cost[i-1];
            else cost[i]+=cost[i-2];
        }
        if(cost[cost.size()-1]>cost[cost.size()-2])return cost[cost.size()-2];
        return cost[cost.size()-1]; 
    }
};
//Runtime: 0 ms  Memory: 17.40 MB
