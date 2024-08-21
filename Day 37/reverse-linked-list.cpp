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
    ListNode* reverseList(ListNode* head) {
        ListNode *p1=head, *p2=nullptr, *p3=nullptr;
        while(p1!=nullptr){
            p3=p2;
            p2=p1;
            p1=p1->next;
            p2->next=p3;
        }
        return p2;
    }
};
