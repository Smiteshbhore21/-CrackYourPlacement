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
    ListNode* middle(ListNode* head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode *p=head, *q=nullptr, *r=nullptr;
        while(p!=nullptr){
            r = q;
            q = p;
            p = p->next;
            q->next=r;
        }
        return q;
    }

    bool isPalindrome(ListNode* head) {
        // stack <int> st;
        // int temp=0;
        // ListNode *p=head;
        // while(p!=NULL){
        //     st.push(p->val);
        //     p=p->next;
        // }
        // p=head;
        // while(p!=NULL){
        //     temp=st.top();
        //     st.pop();
        //     if(temp!=p->val)
        //         return false;
        //     p=p->next;
        // }
        // return true;
        ListNode *curr=head;
        ListNode *mid=middle(head),*last=reverse(mid);
        while(curr->next!=last->next || curr!=nullptr){
            if(head->val!=last->val){
                return false;
            }
            curr=curr->next;
            last=last->next;
        }
        return true;
    }
};
