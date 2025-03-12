#include <bits/stdc++.h>
using namespace std;

class Node {
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
};

void printLL(Node* head){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
};

// Function to delete the head
void deleteHead(Node*& head){
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete the tail
void deleteTail(Node*& head){
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}


// Function to delete any ith element
void deleteith(Node*& head , int i){
    if(i==0){   // For deleting the head
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for(int j=0;j<i-1 ;j++){  // use && temp->next to prevent segmentation fault
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Delete any element given 
void deletevalue(Node*& head, int k){
    Node* temp = head;
    if(temp->data == k) {  // if 1st element matches with value of K(element to be removed)
        head = head->next;
        delete temp;
        return;
    }

    while(temp->next){   // temp->next checks for segmentation fault
        if(temp->next->data == k){
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }

        temp = temp->next;
    }

  
}


int main(){
    vector<int> arr = {12,15,18,5,65,54};
    Node* head = constructLL(arr);
    printLL(head);
    cout<<endl;
    deletevalue(head,1);
    printLL(head);

}