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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyHead(-1);
        dummyHead.next = head;
        ListNode *lastSmall(&dummyHead), *current(&dummyHead), *aux(nullptr);
        while(current->next&&current->next->val<x){
            current = current->next;
        }
        if(!current)
            return dummyHead.next;
        lastSmall = current;
        while(current->next){
            //cout<<current->val<<endl;
            if(current->next->val<x){
                aux = current->next;
                current->next = aux->next;
                aux->next = lastSmall->next;
                lastSmall->next = aux;
                lastSmall = aux;
            }else{
                current = current->next;
            }
        }
        return dummyHead.next;
    }
};