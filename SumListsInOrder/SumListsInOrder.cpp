struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
private:
    ListNode* GetSum(ListNode* l1, ListNode *l2){
        struct StackNode{
            StackNode *past;
            ListNode *list;
            StackNode(ListNode* l, StackNode* p): list(l), past(p){}
        };
        StackNode *stack1(nullptr);
        StackNode *stack2(nullptr);
        while(l1||l2){
            StackNode *pastNode;
            if(l1){
                stack1 = new StackNode(l1, stack1);
                l1 = l1->next;
            }            
            if(l2){
                stack2 = new StackNode(l2, stack2);
                l2 = l2->next;
            }
        }
        int carry(0);
        ListNode head(0);
        while(stack1||stack2){
            int sum = carry;
            StackNode  *current;
            if(stack1){
                sum+=stack1->list->val;
                current = stack1;
                stack1 = stack1->past;
                delete current;
            }
            if(stack2){
                sum+=stack2->list->val;
                current = stack2;
                stack2 = stack2->past;
                delete current;
            }
            carry = sum/10;
            ListNode* past = new ListNode(sum%10);
            past->next = head.next;
            head.next = past;
        }
        if(carry){
            ListNode* past = new ListNode(1);
            past->next = head.next;
            head.next = past;
        }
        return head.next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return GetSum(l1,l2);
    }
};