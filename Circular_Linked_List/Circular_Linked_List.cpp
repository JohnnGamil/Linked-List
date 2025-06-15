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


void traversalnLoop(Node* head){
    Node* temp = head;
    int k = 10;
    while(k--){
        cout<<temp->value<<"->";
        temp=temp->next;
    } cout<<endl;
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


void deleteAtStart(Node* &head){
    Node* temp = head;
    if(head==nullptr){
        return;
    }
    if(head->next==head){
        free(head);
        return;
    }
    Node* tail = head;
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next = head->next;
    head = head->next;
    free(temp);

}


void deleteAtEnd(Node* &head){
    if(head==nullptr){
        return;
    }
    if(head->next==head){
        free(head);
        return;
    }
    Node* secondLast = head;
    while(secondLast->next->next!=head){
        secondLast=secondLast->next;
    }
    Node* last = secondLast->next;
    secondLast->next = head;
    free(last);
}



int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->next = n2;
    n2->next = n1;
    Node* head = n1;
    traversal(head);
    traversalnLoop(head);
    insertatStart(head, 3);
    traversal(head);
    insertAtEnd(head,4);
    traversal(head);
    deleteAtStart(head);
    traversal(head);
    deleteAtEnd(head);
    traversal(head);
}