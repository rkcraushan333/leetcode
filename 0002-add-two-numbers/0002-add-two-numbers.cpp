/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp = l1;
        int a=0,b=0;
        while(temp)
        {
            a++;
            temp = temp->next;
        }
        temp = l2;
        while(temp)
        {
            b++;
            temp = temp->next;
        }
        if(a<b) swap(l1,l2);
        ListNode* ans = l1;
        int last = 0;
        while(l2)
        {
            l1->val += l2->val+last;
            if(l1->val>9)
            {
                l1->val %= 10;
                last = 1;
            }
            else
            {
                last = 0;
            }
            l1 = l1->next; l2 = l2->next;
        }
        while(l1)
        {
            l1->val += last;
            if(l1->val>9)
            {
                l1->val %= 10;
                last = 1;
            }
            else
            {
                last = 0;
            }
            l1 = l1->next;
        }
        
        if(last)
        {
            ListNode* tp = ans;
            while(tp->next)
            {
                tp = tp->next;
            }
            tp->next = new ListNode(last);
        }
        return ans;
    }
};