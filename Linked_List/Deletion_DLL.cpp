#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1 = nullptr, Node* back1 = nullptr){
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

void printDLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// Function to delete the head of the DLL
void deleteHead(Node*& head){
    // take care for the edge cases where the LL has 1 or 0 elements
   if(!head) return;
   if(!head->next){
    delete head;
    head = nullptr;
    return;
   }

   Node* temp = head;
   head= head->next;
   delete temp;
}

// Fucntion to delete the tail of the DLL
void deleteTail(Node*& head){
    if(!head) return;
    if(!head->next){
        delete head;
        head = nullptr;
        return;
    }
    
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    Node* newtail = tail->back;
    tail->back = nullptr;
    newtail->next = nullptr;
    delete tail;
}

// Function to delete the k index element
void deletethat(Node*& head, int k){
    int cnt = 0;
    Node* temp = head;
    while(temp && cnt<k ){
        cnt++;
        temp = temp->next;
    }

    if(!temp) return;
    if(temp == head){
        head = head->next;
        if(head) head->back = nullptr;
        delete temp;
        return;
    }

    if(temp->back) temp->back->next = temp->next;
    if(temp->next) temp->next->back = temp->back;

    delete temp;

}

// Fucntion to delete given element
void deleteit(Node* & head, int k){
    Node* temp = head;
    while(temp->data != k && temp){
        temp = temp->next;
    }
    if(!temp) return;
    if(temp == head){
        head = head->next;
        if(head) head->back = nullptr;
        delete temp;
        return;
    }

    if(temp->back) temp->back->next = temp->next;
    if(temp->next) temp->next->back = temp->back;

    delete temp;

}

int main(){
    vector<int> arr = {22,17,12,44,54,23,41};
    Node *head = constructDLL(arr);
    printDLL(head);
    cout<<endl;
    
}