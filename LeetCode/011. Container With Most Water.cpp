// https://leetcode.com/problems/container-with-most-water/

// Medium

// Topics:
// Array 、 Two Pointers 、 Greedy

// Description:
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

// Submission :
// Original solution - written by me
// Accepted
// Runtime: 0 ms  Memory: 66.30 MB


class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=height.size();
        int m=0;
        int f=0,b=s-1;
        while(f<b){
            int h;
            if(height[f]<=height[b])h=height[f];
            else h=height[b];
            int c=b-f;
            if(m<=c*h)m=c*h;
            if(f+1==b)break;
            if(height[f]<height[b]) f++;
            else b--;
        }
        return m;
    }
};

