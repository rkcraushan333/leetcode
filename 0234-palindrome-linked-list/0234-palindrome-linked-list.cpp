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
    ListNode* rev(ListNode* node)
    {
        if(node==NULL||node->next==NULL) return node;
        ListNode* t = rev(node->next);
        node->next->next = node;
        node->next = NULL;
        return t;
    }
    bool isPalindrome(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt = 0;
        while(fast && (fast->next)) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(cnt&1) slow = slow->next;
        ListNode* mid = rev(slow);
        ListNode* temp = head;
        while(mid)
        {
            if(mid->val!=temp->val) return 0;
            mid = mid->next;
            temp = temp->next;
        }
        return 1;
    }
};