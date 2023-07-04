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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int l1=0,l2 = 0;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a) 
        {
            a = a->next;
            l1++;
        }
        while(b)
        {
            l2++;
            b = b->next;
        }
        if(l1<l2)
        {
            swap(headA,headB);
        }
        else{
            swap(l1,l2);
        }
        a = headA;
        b = headB;
        while(l1<l2)
        {
            a = a->next;
            l1++;
        }
        while(a!=b)
        {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};