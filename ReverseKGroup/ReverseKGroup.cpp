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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *current(&dummy), *next(head);
        stack<ListNode*> st;
        int i(k);
        bool flag(false);
        while(!flag){
            i = k;
            while(i--){
                if(next){
                    st.push(next);
                    next = next->next;
                }else{
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ListNode *lastNext(st.top()->next);
                while(!st.empty()){
                    current->next = st.top();
                    current = current->next;
                    st.pop();
                }
                current->next = lastNext;
            }
        }
        return dummy.next;
        
    }
};