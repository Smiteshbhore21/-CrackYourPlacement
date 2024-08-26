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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *dummynode = new ListNode(-1), *curr = dummynode;
        int carry = 0, sum = 0;
        while (p1 != NULL || p2 != NULL) {
            sum = carry;
            if (p1)
                sum = sum + p1->val;
            if (p2)
                sum = sum + p2->val;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            curr = curr->next;
            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }
        return dummynode->next;
    }
};
