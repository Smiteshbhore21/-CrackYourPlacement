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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        ListNode *p = head->next, *behind = head;
        while (p != nullptr) {
            if (p->val == val) {
                behind->next = p->next;
                delete p;
                p = behind->next;
            } else {
                p = p->next;
                behind = behind->next;
            }
        }
        if (head->val == val) {
            p = head->next;
            delete head;
            head = p;
        }
        return head;
    }
};
