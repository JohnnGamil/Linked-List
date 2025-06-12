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


void traverse(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<"Null"<<endl;
}


void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int val){
    if(head == nullptr){
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertAtMidlle(Node* head, int val, int position){
    if(position == 1){
        insertAtHead(head,val);
        return;
    }
    Node* newNode = new Node(val);
    Node* prev = head;
    int count = 1;
    while(count<(position - 1)){
        prev = prev->next;
        count++;
    }
    // prev is pointing to the node that should come before the new node
    newNode->next = prev->next;
    prev->next = newNode;
}

void deleteAtHead(Node* &head){
    if(head==nullptr){
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(Node* &head){

    if(head==nullptr){
        return;
    }
    if(head->next==nullptr){
        deleteAtHead(head);
        return;
    }

    Node* secondLastNode = head;
    while(secondLastNode->next->next!=nullptr){
        secondLastNode = secondLastNode->next;
    }
    Node* lastNode = secondLastNode->next;
    secondLastNode->next = nullptr;
    free(lastNode);
}


void deleteAtMiddle(Node* &head, int position){
    if(position == 1){
        deleteAtHead(head);
        return;
    }
    Node* prev = head;
    int count = 1;
    while(count<(position-1)){
        prev=prev->next;
        count++;
    }
    //prev is pointing to node at position-1
    Node* curr = prev->next;
    prev->next = curr->next;
    free(curr);
}

void updateNodeValue(Node* &head, int k ,int updatedeValue){
    Node* temp = head;
    int count = 1;
    while(count<k){
        temp=temp->next;
        count++;
    }
    temp->value = updatedeValue;
}


int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next = node2;
    Node* head = node1;
    traverse(head); // 1->2->Null
    insertAtHead(head,3);
    traverse(head); // 3->1->2->Null
    insertAtEnd(head,4);
    traverse(head); // 3->1->2->4->Null
    insertAtMidlle(head,5,3);
    traverse(head); // 3->1->5->2->4->Null
    deleteAtHead(head);
    traverse(head); // 1->5->2->4->Null
    deleteAtEnd(head); 
    traverse(head); // 1->5->2->Null
    deleteAtMiddle(head,2);
    traverse(head); // 1->2->Null
    updateNodeValue(head,1,8);
    traverse(head); // 8->2->Null
}