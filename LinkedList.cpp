#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
        // Constructor
        node(int val){
            data = val;
            next = NULL;
        }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    // If there's no node in list
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    // Iterate through the list
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void searchLinkedList(node* head, int key){
    node* temp = head;
    int index = 0;
    while(temp != NULL){
        if(temp->data == key){
            cout<< "Key Found At Index : "<< index << endl;
            return;
        }
        index++;
        temp = temp->next;
    }
    cout << "Key is not present in the list "<< endl;
    return;
}

void deleteNode(node* &head, int val){
    // If the list is empty
    if(head == NULL){
        return;
    }
    // Deleting the first node in list
    if(head->data == val){
        node* delNode = head;
        head = head -> next;
        delete delNode;
        return;
    }
    // If there's only one element in list
    if(head -> next == NULL){
        delete head;
        return;
    }
    node* temp = head;
    // Iterate through the list
    while(temp->next->data != val){
        temp = temp -> next;
    }
    node* delNode = temp -> next;
    temp-> next = temp->next->next;
    delete delNode;
}

void printLinkedList(node* head){
    // If list is empty
    if(head == NULL){
        cout<< "Nothing to print in the list "<< endl;
        return;
    }
    node* temp = head;
    // Iterate through the list
    while(temp != NULL){
        cout<< temp->data<< " "<<temp->next<< endl;
        temp = temp->next;
    }
}

int main(){
    node* head = NULL;
    int i = 0;
    //insertAtHead(head, 20);
    while(i<10){
        insertAtTail(head, i);
        i++;
    }
    printLinkedList(head);
    searchLinkedList(head, 3);
    printLinkedList(head);
    // Delete all the nodes
    for(int i = 0; i< 10; i++){
        deleteNode(head, i);
    }
    printLinkedList(head);
    return 1;
}