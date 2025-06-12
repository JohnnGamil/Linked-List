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


int main(){
    Node* n1 = new Node(1);    
    Node* n2 = new Node(2);
    n1->next = n2;
    n2->prev = n1;    
    Node* head = n1;
    forwardTravesal(head);
    backwardTraversal(head);
}