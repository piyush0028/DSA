#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

Node* constructLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1;i<arr.size();i++){
        Node* Node1 = new Node(arr[i]);
        temp->next = Node1;
        temp = Node1;
    }

    return head;
}

void printLL(Node*& head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


// Function to insert head in Linked List 
// here we need to creat a new node
void insertHead(Node*& head, int k){
    Node* temp = new Node(k, head); // constructed new node
    head = temp;
}

// Function to insert tail in Linked List 
void insertTail(Node*& head, int k){
    Node* newNode = new Node(k);
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Inserting element in LL with given value and given position
void insertThisHere(Node*& head, int val, int pos){
    Node* newNode = new Node(val);
    Node* temp = head;

    if(pos==0){
        Node* temp1 = new Node(val,head);
        head = temp1;
        return;
    } else {
        
     int flag = pos-1;
     while(flag--){
        temp = temp->next;
     }

     newNode->next = temp->next;
     temp->next = newNode;

    }
}

int main(){
    vector<int> arr = {28,45,74,96,21};
    Node* head = constructLL(arr);
    printLL(head);
    cout<<endl;
    insertThisHere(head, 12 , 0);
    printLL(head);
}