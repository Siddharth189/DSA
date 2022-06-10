#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node();
};

void createLL(Node *&head, std::vector<int> v){
    Node * tail = NULL;

    for(auto x: v){
        Node *t = new Node(x);
        t->next = NULL;
        if(head == NULL){
            head = t;
            tail = t;
        }else{
            tail->next = t;
            tail = t;

        }
    }   
}

Node * tailOfLL(Node *head){
    while(head->next) head = head->next;

    return head;
}

Node * sizeOfLL(Node * p){
    int ans = 0
    while(p){
        p = p->next;
        ans++;
    }

    return ans;
}

void reverseLL1(Node *&head){
    Node *tail = tailOfLL(head);
    Node *temp = head;

    while(head!=tail){
        head = head->next;
        temp->next = tail->next;
        tail->next = temp;

        temp = head;
    }
}

Node* reverseRecLL(Node *head){
    if(head == NULL || head->next == NULL) return head;

    Node *shead = reverseRecLL(head->next);
    
    Node *t = head->next;
    t->next = head;
    head->next = NULL;

    return shead;
}

void printLL(Node *p){
    while(p->next){
        cout << p->data << " --> ";
        p = p->next; 
    }

    cout << p->data;
}

int main(){
    Node * head = NULL;
    createLL(head, {1,2,3,4,5,6});
    
    cout << "\nList created: ";
    printLL(head);

    cout << "\nList reversed using iterative method: ";
    reverseLL1(head);
    printLL(head);

    cout << "\nList reversed using recursive method: ";
    head = reverseRecLL(head);
    printLL(head);


    return 0;
}
