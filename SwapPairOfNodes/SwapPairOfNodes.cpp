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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* first(&dummy), *second(&dummy), *third(&dummy);
        if(first){
            second = first->next;
        }else{
            return head;
        }
        if(second){
            third = second->next;
        }else{
            return head;
        }
        while(third){
            first->next = third;
            second->next = third->next;
            third->next = second;
            first = second;
            second = first->next;
            if(second)
                third = second->next;
            else
                third = nullptr;
        }
        return dummy.next;
    }
};