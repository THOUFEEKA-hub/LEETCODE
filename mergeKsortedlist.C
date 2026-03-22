struct ListNode* mergeTwo(struct ListNode* a, struct ListNode* b) {
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    dummy.next = NULL;
    while (a && b) {
        if (a->val < b->val) {
            temp->next = a;
            a = a->next;
        } else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }

    temp->next = (a) ? a : b;
    return dummy.next;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    struct ListNode* result = lists[0];
    for (int i = 1; i < listsSize; i++) {
        result = mergeTwo(result, lists[i]);
    }
    return result;
}
