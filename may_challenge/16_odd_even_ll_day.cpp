/*

Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes)
 time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

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
    ListNode* oddEvenList(ListNode* head) {
        //base case
        if(head == NULL)return NULL;
        
        
        //using two pointer method
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        
        // we need this even starting point for adding later
        ListNode* even = ptr2;
        while(1)
        {
            //if no more odd/even add even to odd
            if(ptr1 == NULL || ptr2 == NULL || ptr2->next == NULL)
            {
                ptr1->next = even;
                break;
            }
            // else start appending add
            ptr1->next = ptr2->next;
            ptr1 = ptr2->next;
            
            //if last odd node found... append null to even and attach even to odd
            if(ptr1->next == NULL)
            {
                ptr2->next = NULL;
                ptr1->next = even;
                break;
            }
            
            //else start appending even
            ptr2->next = ptr1->next;
            ptr2 = ptr1->next;
        }
        return head;
    }
};