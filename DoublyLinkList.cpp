#include<iostream>
using namespace std;
class Node{
    public:
	int data;
	Node *next;
    Node *prev;
	public:
		//parametrized constructor
		 Node(int data ){
		 	this->data = data;
		 	next = NULL;
            prev = NULL;
		 }
		 //default constructor
		 Node(){
		 	data = 0;
		 	next = NULL; 
            prev = NULL;
		 } 
};
class doublelist{
    public:
    Node *head; 
    Node *tail;

    doublelist(){
		head = tail =NULL;
	}
    //function to insert at head
    void insertathead(int data){
        if(head == NULL){
            Node *newnode = new Node(data);
            head = tail =newnode;
        }
        else{
            Node *newnode = new Node(data);
            Node *temp = head;
            newnode->next = head;
            head->prev = newnode;
            head=newnode;

        }
    }
    //function to insert at tail
    void insertattail(int data){
        Node *newnode = new Node(data);

        if(head == NULL){
            head = tail =newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    //function to insert at node
    void insertatnode(int position , int data){
            Node *temp = head;
            int counter =1;

            while(counter < position){
                temp=temp->next;
                counter++;
            }

        if(position == 1){
            insertathead(data);
            return ;
        }

        Node *newnode = new Node(data);
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;

        if(temp->next == NULL){
            insertattail(data);
            return;
        } 
    }
    //function to delete
    void deletenode(int position){
        
        int ctr=1;

        if(head == NULL){
            cout<<"The list is empty."<<endl;
        }

        if(position == 1){
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            Node *curr = head;
            Node *prev = NULL;
            while(ctr < position){
                prev = curr;
                curr = curr->next;
                ctr++;
            }
            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            delete curr;
        }
    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    doublelist obj1;
    obj1.insertathead(1);
    obj1.insertathead(2);
    obj1.insertathead(3);
    obj1.insertathead(4);

    obj1.insertattail(5);
    obj1.insertattail(6);

    obj1.insertatnode(2,10);

    obj1.deletenode(3);

    obj1.display();
}