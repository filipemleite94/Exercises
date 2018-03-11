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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        n-=m;
        if(n<1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current(&dummy);
        while(--m){
            current = current->next;
        }
        ListNode *last(current->next);
        ListNode *aux(last->next);
        while(n--){
            //cout<<n<<endl;
            aux = aux->next;
            last->next->next = current->next;
            current->next = last->next;
            last->next = aux;
        }
        return dummy.next;
    }
};