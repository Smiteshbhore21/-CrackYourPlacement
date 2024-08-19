#include<iostream>
using namespace std;
class LinkedNode{
    public:
        int val;
        LinkedNode *next;
        LinkedNode(int val){
            this->val=val;
            this->next=nullptr;
        }
};

void sortL(LinkedNode *head){
    LinkedNode *p=head;
    int c[3]={0};
    while(p!=nullptr){
        c[p->val]++;
        p=p->next;
    }

    p=head;
    int index=0;
    while(p!=nullptr){
        if(c[index]==0)
            index++;
        else{
            p->val=index;
            c[index]--;
            p=p->next;
        }
    }
}

void Display(LinkedNode *head){
    LinkedNode *p=head;
    while(p!=nullptr){
        cout<<p->val<<"=>";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    LinkedNode *head = new LinkedNode(1);
    head->next = new LinkedNode(1);
    head->next->next = new LinkedNode(2);
    head->next->next->next = new LinkedNode(1);
    head->next->next->next->next = new LinkedNode(0);
    Display(head);
    sortL(head);
    Display(head);
    return 0;
}
