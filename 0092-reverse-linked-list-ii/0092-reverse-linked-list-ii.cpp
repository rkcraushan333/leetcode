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
   
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--;
        right--;
        ListNode *pre = NULL;
        ListNode *ans=head;
        for(int i = 0 ;i <left;i++){
            pre = head;
            head = head->next;
        }
        ListNode *t = pre;
        ListNode *temp = head;
        int d = right-left+1;
        while(d-- && head){
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        if(t) t->next = pre;
        else{
            ans = pre;
        }
        temp->next = head;
        return ans;
    }
};