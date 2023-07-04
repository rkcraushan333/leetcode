class Solution {
public:
    ListNode* findMid(ListNode* node)
    {
        ListNode* slow = node;
        ListNode* fast = node->next;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if((l1->val)>(l2->val)) swap(l1,l2);
        ListNode* l = l1;
        ListNode* lhead = l1;
        l1 = l1->next;
        while(l1&&l2)
        {
            if(l1->val<=l2->val) 
            {
                l->next = l1;
                l = l->next;
                l1 = l1->next;
            }else
            {
                l->next = l2;
                l = l->next;
                l2 = l2->next;
            }
        }
        while(l1)
        {
            l->next = l1;
            l = l->next;
            l1 = l1->next;
        }
        while(l2)
        {
            l->next = l2;
            l = l->next;
            l2 = l2->next;
        }
        return lhead;
    }
    ListNode* mergeSort(ListNode* head)
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = findMid(head);
        ListNode* right = mergeSort(mid->next);
        mid->next = NULL;
        ListNode* left = mergeSort(head);
        // ListNode* l = mergeSort(left);
        // ListNode* r = mergeSort(right);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) 
    {
        return mergeSort(head);
    }
};