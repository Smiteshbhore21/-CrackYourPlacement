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
    ListNode* middleNode(ListNode* head) {
        ListNode *c, *t;
        c=head;
        t=head;
        int flag=0;
        if(head==nullptr) return head;
        while(t->next != nullptr){
            if(t->next->next==nullptr){
                flag=1;
                break;
            }
            t=t->next->next;
            c=c->next;
        }
        if(flag){
            c=c->next;
        }
        return c;
    }
};
