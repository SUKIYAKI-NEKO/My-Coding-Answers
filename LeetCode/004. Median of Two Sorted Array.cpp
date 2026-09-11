//https://leetcode.com/problems/median-of-two-sorted-arrays/

//Hard

//Topics:
//Mid Level , Array , Binary Search , Divide and Conquer

//Description:
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).

//Submission:
//Accepted
//Runtime: 0 ms Memory: 96.11 MB

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=0,n2=0;
        vector<int>nums3;
        while(1){ 
            if(n1<nums1.size() && n2<nums2.size()){
                if(nums1[n1]<=nums2[n2]){
                nums3.push_back(nums1[n1]);
                n1++;
                }
                else{
                nums3.push_back(nums2[n2]);
                n2++;
                }
            }
            else if(n1<nums1.size()){
                nums3.push_back(nums1[n1]);
                n1++;
            }
            else{
                nums3.push_back(nums2[n2]);
                n2++;
            }
            if(n1>=nums1.size() && n2>=nums2.size()){
                break;
            }
        }
        int a=nums1.size()+nums2.size();
        if(a%2==1){
            a=a/2+1;
            return nums3[a-1];
        }
        else {
            a/=2;
            return (nums3[a]+nums3[a-1])/2.0;
        }
    }
};
