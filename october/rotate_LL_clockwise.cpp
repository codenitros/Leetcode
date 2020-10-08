/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL


*/


//solution


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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || k<=0)return head;
        
        //get the length of list
        ListNode *temp = head;
        int listLength = 1;
        while(temp->next!= NULL){
            temp=temp->next;
            listLength++;
        }

        //if shifts > listlength take mod        
        k = k % listLength;
        if(k == 0 || k == listLength)return head;
        
        //point last node to prev head
        temp->next = head;
        
        // from prev head go upto kth node
        temp = head;
        int go = (listLength - k);
        while(go>1){
            temp=temp->next;
            go--;
        }
        
        //mark (k+1)th node as new head 
        head=temp->next;
        
        // make the next of kth node as null
        temp->next =  NULL;
        
        //return the new head
        return head;
    }
};