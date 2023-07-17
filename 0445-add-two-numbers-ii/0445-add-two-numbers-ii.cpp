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
    ListNode* revlist(ListNode* head)
    {
        if(!head->next) return head;
        ListNode* temp = revlist(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* a = revlist(l1);
        ListNode* b = revlist(l2);
        int n1 = 0,n2=0;
        ListNode* temp1 = a;
        ListNode* temp2 = b;
        while(temp1)
        {
            n1++; temp1 = temp1->next;
        }
        while(temp2)
        {
            n2++; temp2 = temp2->next;
        }
        if(n1<n2) swap(a,b);
        int last = 0;
        temp1 = a;
        temp2 = b;
        ListNode* lastn = a;
        while((temp1!=NULL)&&(temp2!=NULL))
        {
            int curr = last+temp1->val+temp2->val;
            last = curr/10;
            temp1->val = curr%10;
            lastn = temp1;
            temp1 = temp1->next; temp2 = temp2->next;
        }
        if(last)
        {
            if(n1==n2)
            {
                lastn->next = new ListNode(last);
            }
            else
            {
                while((temp1)&&(last>0))
                {
                    int curr = temp1->val+last;
                    last = curr/10;
                    temp1->val = curr%10;
                    lastn = temp1;
                    temp1 = temp1->next;
                }
                if(last)
                {
                    lastn->next = new ListNode(last);
                }
            }
        }
        l1 = revlist(a);
        return l1;
    }
};