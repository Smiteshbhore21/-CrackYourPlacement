/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    /*HASH_MAP*/
        Node *dummyNode = new Node(-1), *curr=dummyNode;
        Node *p1=head, *copyNode=NULL;
        unordered_map<Node*,Node*> mp;
        while(head!=NULL){
            Node *newNode = new Node(head->val);
            curr->next=newNode;
            mp[head]=newNode;
            curr=curr->next;
            head=head->next;
        }
        while(p1!=NULL){
            copyNode = mp[p1];
            copyNode->random = mp[p1->random];
            p1=p1->next;
        }
    return dummyNode->next;
    }
};
