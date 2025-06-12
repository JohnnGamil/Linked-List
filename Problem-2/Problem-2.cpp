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




int findMiddleNode(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is now at the middle node
    return slow->value;
}


int main(){
    Node* head = nullptr;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    traverse(head);
    cout<<findMiddleNode(head)<<endl;
}