/*
Problem: 2. Add Two Numbers
Source: https://leetcode.com/problems/add-two-numbers/description/
Descripption: Linked List
*/
//Runtime: 1 ms  Memory: 77.02 MB



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ch=0;
        ListNode* t=new ListNode(0);
        ListNode* code=t;
        while(1){
            if(l1!=nullptr && l2 != nullptr){
                int aa=l1->val+l2->val+ch;
                if(ch==1)ch=0;
                if(aa>=10){
                    ch=1;
                    code->next=new ListNode(aa%10); 
                }
                else code->next=new ListNode(aa);
                l1=l1->next;
                l2=l2->next;
                code=code->next;
            }
            else if(l1!=nullptr && l2 == nullptr){
                int aa=l1->val+ch;
                if(ch==1)ch=0;
                if(aa>=10){
                    ch=1;
                    code->next=new ListNode(aa%10); 
                }
                else code->next=new ListNode(aa);
                l1=l1->next;
                code=code->next;
            }
            else if(l1==nullptr && l2 != nullptr){
                int aa=l2->val+ch;
                if(ch==1)ch=0;
                if(aa>=10){
                    ch=1;
                    code->next=new ListNode(aa%10); 
                }
                else code->next=new ListNode(aa);
                l2=l2->next;
                code=code->next;
            }
            if(l1==nullptr && l2 == nullptr) {
                if(ch==1)code->next=new ListNode(1);
                break;
            }

        }
        return t->next;
    }
};
