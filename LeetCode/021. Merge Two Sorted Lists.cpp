// 09/14/2026
// https://leetcode.com/problems/merge-two-sorted-lists/description/

// Easy

// Topics:
// Linked List 、 Recursion

// Description:
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.


// Submission:
// Original solution - written by me
// Accepted
// Runtime: 0 ms  Memory: 19.95 MB


// Submission:


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t=new ListNode(0);
        ListNode* code=t;
        while(list1 != nullptr || list2 != nullptr){
            if(list1!=nullptr && list2==nullptr){
                code->next=new ListNode(list1->val);
                list1=list1->next;
            }
            else if(list1==nullptr && list2!=nullptr){
                code->next=new ListNode(list2->val);
                list2=list2->next;
            }
            else {
                if(list1->val<=list2->val){
                    code->next=new ListNode(list1->val);
                    list1=list1->next;
                }
                else {
                    code->next=new ListNode(list2->val);
                    list2=list2->next;
                }
            }
            code=code->next;
        }
        return t->next;
    }
};




//end
