/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<algorithm>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> vec;
        ListNode dumb(-1);
        ListNode* current(&dumb);
        auto comp = [](ListNode* l1, ListNode* l2){ return l1->val > l2->val;};
        //auto pheap = [&](ListNode* l){vec.push_back(l); push_heap(vec.begin(), vec.end(), comp);};
        for(auto it : lists){
            if(it){
                vec.push_back(it);
                push_heap(vec.begin(), vec.end(), comp);
            }
        }
        int size(vec.size());
        while(size){
            ListNode* l(vec.front());
            pop_heap(vec.begin(), vec.end(), comp);
            vec.pop_back();
            if(l->next){
                vec.push_back(l->next);
                push_heap(vec.begin(), vec.end(), comp);
            }else{
                size--;
            }
            current->next = l;
            current = current->next;
        }
        return dumb.next;
    }
};