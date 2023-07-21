class Solution {
public:
    int len(ListNode* head)
    {
        int cnt = 0;
        ListNode* temp = head;
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    int n = len(head);
    if (n < k) return head;
    ListNode* dummy = new ListNode(0);  // Dummy node to handle edge cases
    dummy->next = head;
    ListNode* prev_group_tail = dummy;  // Previous group tail node

    while (n >= k) {
        ListNode* group_head = prev_group_tail->next;  // Current group head
        ListNode* group_tail = group_head;  // Current group tail
        for (int i = 1; i < k; i++) {
            group_tail = group_tail->next;  // Move group_tail k-1 steps forward
        }
        ListNode* next_group_head = group_tail->next;  // Head of the next group

        // Reverse the current group
        ListNode* prev = next_group_head;
        ListNode* curr = group_head;
        while (curr != next_group_head) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Connect the reversed group to the previous group
        prev_group_tail->next = group_tail;
        prev_group_tail = group_head;
        n -= k;
    }

    ListNode* result = dummy->next;
    delete dummy;
    return result;
}

};