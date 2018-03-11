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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *toRemove(head), *last(head);
        for(int i = 0; i<n; i++){
            last = last->next;
        }
        if(last != nullptr)
            last = last->next;
        else{
            return toRemove->next;
        }
        while(last!=nullptr){
            toRemove = toRemove->next;
            last = last->next;
        }
        toRemove->next = toRemove->next->next;
        return head;
    }
};

//Using stack
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *it(head);
        stack<ListNode*> st;
        while(it!=nullptr){
            st.push(it);
            it = it->next;
        }
        while(n--)
            st.pop();
        if(st.empty())
            return head->next;
        st.top()->next = st.top()->next->next;
        return head;
    }
};