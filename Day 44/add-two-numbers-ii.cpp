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
    void listToStack(ListNode* l1, stack<int> &s1){
        while(l1!=NULL){
            s1.push(l1->val);
            l1=l1->next;
        }
        return;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //INT OVERFLOW -> 1561/1563 TEST CASES PASSED
        // stack<int> num1;
        // stack<int> num2;
        // while(l1!=NULL || l2!=NULL){
        //     if(l1){
        //         num1.push(l1->val);
        //         l1=l1->next;
        //     }
        //     if(l2){
        //         num2.push(l2->val);
        //         l2=l2->next;
        //     }
        // }
        // int n1=0, n2=0, carry=0, sum=0; 
        // __int128 res=1;
        // while(!(num1.empty()) && (!num2.empty())){
        //     sum=carry;
        //     n1=num1.top();
        //     num1.pop();
        //     n2=num2.top();
        //     num2.pop();
        //     sum=sum+(n1+n2);
        //     carry=sum/10;
        //     res=(res*10)+(sum%10);
        // }
        // while(!(num1.empty())){
        //     sum=carry;
        //     n1=num1.top();
        //     num1.pop();
        //     sum=sum+n1;
        //     res=(res*10)+(sum%10);
        //     carry=sum/10;
        // }
        // while(!(num2.empty())){
        //     sum=carry;
        //     n2=num2.top();
        //     num2.pop();
        //     sum=sum+n2;
        //     res=(res*10)+(sum%10);
        //     carry=sum/10;
        // }
        // if(carry){
        //     res=(res*10)+carry;
        // }
        // ListNode *dummyNode = new ListNode(-1);
        // ListNode *curr=dummyNode;
        // if(res==1){
        //     ListNode *newNode = new ListNode(0);
        //     curr->next = newNode;
        // }
        // while(res>1){
        //         ListNode *newNode = new ListNode(res%10);
        //         curr->next = newNode;
        //         curr=curr->next;
        //         res/=10;
        // }

        // return dummyNode->next;

        stack<int> s1,s2, ans;
        listToStack(l1,s1);
        listToStack(l2,s2);
        int carry = 0;
        while(s1.size() && s2.size()){
            int x=s1.top();
            int y=s2.top();
            s1.pop();
            s2.pop();
            int sum = x+y+carry;
            ans.push(sum%10);
            carry=sum/10;
        }

        while(s1.size()){
            int x=s1.top();
            s1.pop();
            int sum = x+carry;
            ans.push(sum%10);
            carry=sum/10;
        }

        while(s2.size()){
            int x=s2.top();
            s2.pop();
            int sum = x+carry;
            ans.push(sum%10);
            carry=sum/10;
        }

        if(carry){
            ans.push(carry);
        }

        ListNode* dummyNode = new ListNode(-1), *curr=dummyNode;
        while(ans.size()){
            ListNode *newNode = new ListNode(ans.top());
            curr->next=newNode;
            curr=curr->next;
            ans.pop();
        }
        return dummyNode->next;
    }
};
