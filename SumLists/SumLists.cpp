struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
private:
    ListNode* GetNextNode(int value, bool &overFlow){
        int sum = value;
        if(overFlow)
            sum++;
        if(sum>9){
            sum-=10;
            overFlow = true;
        }else{
            overFlow = false;
        }
        return new ListNode(sum);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool oF = false;
        ListNode head(0);
        ListNode* current = &head;
        while(l1!=nullptr&&l2!=nullptr){
            current->next = GetNextNode(l1->val+l2->val, oF);
            l1=l1->next;
            l2=l2->next;
            current=current->next;        
        }
        while(l1!=nullptr){
            current->next=GetNextNode(l1->val, oF);
            l1=l1->next;
            current=current->next;   
        }
        while(l2!=nullptr){
            current->next = GetNextNode(l2->val, oF);
            l2=l2->next;
            current=current->next;   
        }
        if(oF){
            current->next = GetNextNode(0,oF);
        }
        return head.next;
    }
};