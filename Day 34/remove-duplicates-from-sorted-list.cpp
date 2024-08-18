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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *p = head, *ahead = p->next;
        while (ahead != nullptr) {
            if (p->val != ahead->val) {
                p = ahead;
            } else {
                p->next = ahead->next;
            }
            ahead=ahead->next;
        }
        return head;
    }
};
