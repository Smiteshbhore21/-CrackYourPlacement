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
    bool isPalindrome(ListNode* head) {
        stack <int> st;
        int temp=0;
        ListNode *p=head;
        while(p!=NULL){
            st.push(p->val);
            p=p->next;
        }
        p=head;
        while(p!=NULL){
            temp=st.top();
            st.pop();
            if(temp!=p->val)
                return false;
            p=p->next;
        }
        return true;
    }
};
