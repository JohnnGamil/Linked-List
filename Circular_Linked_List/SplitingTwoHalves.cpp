#include <bits/stdc++.h>
using namespace std;
#define Manga ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double


class Node{
    public:
    int value;
    Node* next;
    Node(int v){
        value = v;
        next = nullptr;
    } 
};

void traversal(Node* head){
    Node* temp = head;
    do
    {
        cout<<temp->value<<"->";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
}

void insertatStart(Node* &head, int v){
    Node* newNode = new Node(v);
    if(head==nullptr){
        head = newNode;
        head->next=head;
        return;
    }
    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = newNode;  //Changing the link from the last node to the head node
    newNode->next = head;  // making the new node points to current head node  
    head = newNode;        // updating the head node
}

void insertAtEnd(Node* &head, int v){
    Node* newNode = new Node(v);
    if(head==nullptr){
        head = newNode;
        head->next=head;
        return;
    }
    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}


//Implmented using slow and fast pointers approach
void splitLinkedList(Node* &head, Node* &head1, Node* &head2){
    
    if(head->next==head){ //if list only have one node
        head1=head;
        return;
    }

    //finding the middle node
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    // Placing the new head pointers
    head1 = head;
    head2 = slow->next;

    // in case of even nodes, we will move the fast pointer to last node
    if(fast->next->next==head){
        fast=fast->next;
    }
    //making the last nodes points to the head nodes
    slow->next = head1;
    fast->next=head2;

}

int main(){
    Node* head = nullptr;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    traversal(head);

    Node* head1 = nullptr;
    Node* head2 = nullptr;
    splitLinkedList(head, head1, head2);
    traversal(head1);
    traversal(head2);

}