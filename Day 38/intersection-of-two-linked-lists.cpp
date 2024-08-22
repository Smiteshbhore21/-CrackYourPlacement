/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // HASH MAP
        // unordered_map<ListNode*, int> mp;
        // for (auto p = headA; headA != nullptr; headA = headA->next)
        //     mp[headA]++;

        // for (auto p = headB; headB != nullptr; headB = headB->next) {
        //     if (mp.find(headB) != mp.end())
        //         return headB;
        // }
        // return headA;


      //TWO POINTER
        int len1=0, len2=0;
        ListNode *p1=headA, *p2=headB;
        while(p1!=NULL){
            len1++;
            p1=p1->next;
        }
        while(p2!=NULL){
            len2++;
            p2=p2->next;
        }
        int diff = abs(len1-len2);

        if(len1>len2)
            while(diff-- > 0)
                headA=headA->next;
        else
            while(diff-- > 0)
                headB=headB->next;

        while(headA!=headB && headA!=NULL && headB!=NULL){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
