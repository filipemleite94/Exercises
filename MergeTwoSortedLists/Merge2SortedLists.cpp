/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* current(&dummy);
        while(l1&&l2){
            if(l1->val < l2->val){
                current->next = l1;
                l1 = l1->next;
            }else{
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        while(l1){
            current->next = l1;
            l1 = l1->next;
            current = current->next;
        }
        while(l2){
            current->next = l2;
            l2 = l2->next;
            current = current->next;
        }
        return dummy.next;
    }
};