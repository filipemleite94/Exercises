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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        unordered_map<int, ListNode*> map;
        ListNode* current(&dummyHead);
        while(current->next){
            const int val(current->next->val);
            auto it = map.find(val);
            if(it==map.end()){
                map[val] = current;
                current = current->next;
            }else{
                cout<<val<<endl;
                ListNode *aux(it->second);
                current->next = current->next->next;
                if(aux){
                    map[val] = nullptr;
                    if(aux->next==current){
                        current = aux;
                    }
                    aux->next = aux->next->next;
                }
            }
        }
        return dummyHead.next;
    }
};