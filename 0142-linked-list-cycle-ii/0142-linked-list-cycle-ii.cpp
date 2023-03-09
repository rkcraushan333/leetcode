// x1 + x2 +x3 + x2 , x1+x2 :- x1 = x3 as slow = fast/2
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        if(!head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        bool check = 0;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) {
                check = 1;
                break;
            }
        }
        if(!check) return NULL;
        slow = head;
        while(slow!=fast){
            slow=slow->next;
            fast = fast->next;
        }
        return slow;
    }
};