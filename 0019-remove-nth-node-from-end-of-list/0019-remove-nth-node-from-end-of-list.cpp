class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* node = head;
        while(n--)
        {
            node = node->next;
        }
        if(node==NULL) return head->next;
        ListNode* l1 = head;
        while(node->next) 
        {
            node = node->next;
            l1 = l1->next;
        }
        l1->next = l1->next->next;
        return head;
    }
};