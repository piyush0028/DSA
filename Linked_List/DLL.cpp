#include <bits/stdc++.h>
using namespace std;

                        // Construction of Doubly Linked List //
//---------------------------------------------------------------------------------------

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1 = nullptr , Node* back1 = nullptr){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* constructDLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i] , nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

//---------------------------------------------------------------------------------------

void printDLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int> arr = {10,5,6,85,41};
    Node* head =  constructDLL(arr);
    printDLL(head);
}