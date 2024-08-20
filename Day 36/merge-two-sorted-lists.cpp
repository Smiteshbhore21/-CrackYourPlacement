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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1=list1, *p2=list2, *temp;
        ListNode *dummy = new ListNode(-1);
        temp=dummy;
        while(p1!=nullptr && p2!=nullptr){
            if(p1->val<p2->val){
                temp->next = p1;
                temp = p1;
                p1 = p1->next;
            } else {
                temp->next = p2;
                temp = p2;
                p2 = p2->next;
            }
        }
        if(p1) temp->next = p1;
        else temp->next = p2;
        return dummy->next;
    }
};
