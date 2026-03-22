struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* temp = head;
    int count = 0;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    if (count < k) return head;
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    head->next = reverseKGroup(curr, k);
    return prev;
}    
