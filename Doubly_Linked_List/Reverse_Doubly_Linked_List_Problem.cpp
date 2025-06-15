#include <bits/stdc++.h>
using namespace std;
#define Manga ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double


class Node{
    public:
    int value;
    Node* next;
    Node* prev;
    Node(int v){
        value = v;
        next = nullptr;
        prev = nullptr;
    } 
};


void forwardTravesal(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->value<<"--";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}


void backwardTraversal(Node* head){
    Node* temp = head;
    while(temp->next){
        temp=temp->next;
    }

    while(temp){
        cout<<temp->value<<"--";
        temp=temp->prev;
    }
    cout<<"Null"<<endl;
}


void insertAtStart(Node* &head, int v){
    Node* newNode = new Node(v);
    if(head==nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


void insertAtEnd(Node* &head, int v){
    if(head == nullptr){
        insertAtStart(head, v);
        return;
    }
    Node* newNode = new Node(v);
    Node* lastNode = head;
    while(lastNode->next){
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}


void insertAtMiddle(Node* &head, int v, int k){
    if(k==1){
        insertAtStart(head, v);
        return;
    }
    Node* temp = head;
    for(int i=1;i<k-1;i++){
        temp=temp->next;
    }
    Node* newNode = new Node(v);
    if(temp->next){
         temp->next->prev = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}



void reverseDll(Node* &head) {
    if (!head || !head->next) return; // If list is empty or has one node, no need to reverse
    Node* currptr = head;
    Node* prevptr = nullptr;
    Node* last = nullptr; // To track the new head

    while (currptr) {
        // Store the last node (will become the new head)
        last = currptr;
        
        // Swap prev and next pointers
        prevptr = currptr->prev;
        currptr->prev = currptr->next;
        currptr->next = prevptr;
        
        // Move to the next node
        currptr = currptr->prev;
    }
    // Update head to point to the new first node (original last node)
    head = last;
}

int main(){
    Node* n1 = new Node(1);    
    Node* n2 = new Node(2);
    n1->next = n2;
    n2->prev = n1;    
    Node* head = n1;
    forwardTravesal(head);
    backwardTraversal(head);
    insertAtStart(head,9);
    forwardTravesal(head);
    insertAtMiddle(head,3,1);
    forwardTravesal(head);
    reverseDll(head);
    forwardTravesal(head);
} 