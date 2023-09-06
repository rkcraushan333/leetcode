class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*>res;
        int n = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            n++;
        }
        int cnt1 = (n/k);
        int cnt2 = (n%k);
        temp = head;
        while(k--)
        {
            if(n>cnt1)
            {
                int c =(cnt2>0);
                ListNode*temp2 = temp;
                for(int i=1;i<cnt1+c;i++)
                {
                    temp2 = temp2->next;
                }
                ListNode* temp3 = temp2->next;
                temp2->next = NULL;
                res.push_back(temp);
                temp = temp3;
                n-=cnt1+c;
                cnt2--;
            }
            else if(n)
            {
                res.push_back(temp);
                n=0;
            }
            else
            {
                res.push_back(NULL);
            }
        }
        return res;
    }
};