#include <bits/stdc++.h>
using namespace std;

// making struct because LL has address of the next and also data 
// their is no such Data structure henc ewe need to create our own

// use class this works same as struct

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1) {
        data = data1;
        next = next1;
    }
};


// Convert array ---> Linked List
Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0] , nullptr);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i] , nullptr);
        mover->next = temp;
       // mover = mover->next;
        mover = temp; 
    }
    return head;
}

// Length of arr
int lengthOfLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp){
        // cout<<temp->data <<" ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// Check 4 element 
int checkPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}


int main(){
    vector<int> arr = {12,4,6,88};
    Node* y = new Node(arr[1] , nullptr);
    cout<<y->data<<endl;;


    // conversion arr->LL
    Node* head = convertArr2LL(arr);
    cout<<head->data<<endl;

    // traversing LL
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    // length of LL
    int length = lengthOfLL(head);
    cout<<length<<endl;

    // Check if present
    int present = checkPresent(head, 88);
    cout<<present<<endl;
}

// Constructing a Linked List 


/* class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        
        Node* head = new Node(arr[0]);
        Node* temp = head;
        
        for(int i=1;i<arr.size();i++){
            Node* Node1 = new Node(arr[i]);
            temp->next = Node1;
            temp = Node1;
        }
        return head;
    }
};                                 */

// Memory space used
// for 64 byte system 
// int = 4 byte and * = 8 byte

// How to convert array ----> Linked List
// we need to know where is head arr[] = {2,1,4,6}
// [2](head) ---> [1] ---> [4] ---> [6](tail)
// this can be acheived by mover and temp
// mover -> next = temp;

// Traversing the Linked List
// do not temper the head
// assign temp to head

// Length of LL

// Check if a given element is present 
