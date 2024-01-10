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
    //function to insert at start
    void insertathead(int value){
        Node *newnode = new Node(value);
        if(head == NULL){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            newnode->prev = tail;
            head= newnode;
        }
        tail->next = head;
    }
    //function to insert at tail
    void insertattail(int data){
        Node *newnode = new Node(data);

         if(head == NULL){
                Node *newnode = new Node(data);
                head = tail = newnode;
            }

        else{
            Node *newnode = new Node(data);
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next=head;
            tail = newnode;
        }
    }
    //function to insert at any position.
    void insertatposition(int position , int data){
        Node *temp = head;
            int counter=1;
            
            while(counter < position){
                counter++;
                temp = temp->next;
            }

             if(position == 1){
                insertathead(data);
                return;
            }

            Node *newnode = new Node(data);
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->prev = temp;

             if(temp->next == head){
                insertattail(data);
                return ;
            }
    }
    //function to calculate the length of the list
   int getlength() {
    if (head == NULL) {
        return 0;  
    }
    Node* temp = head;
    int ctr = 0;  
    do {
        ctr++;
        temp = temp->next;
    } while (temp != head); 

    return ctr;
    }
    //function to delete
    void deletenode(int position){
        
        int ctr = 1;

        if(head == NULL){
            cout<<"The list in empty"<<endl;
        }

        if(position == 1){
            Node *temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }

        Node *curr = head;
        Node *prev = NULL;

        while(ctr < position){
            prev = curr;
            curr = curr->next;
            ctr++;
        }

        if(position < getlength()){
            prev->next = curr->next;
            prev->next->prev = prev;
            curr->next = NULL;
            delete curr;
        }
        else{
            cout<<"Position donot exsists."<<endl;
        }
    }

    //function to update a data
    void updatenode(int position , int value){
        int ctr = 1;
        Node *temp = head;

        while(ctr < position){
            temp = temp->next;
            ctr++;
        }
        if(position < getlength() && position >=1){
            temp->data = value;
        }
        else{
            cout<<"The position donot exsists."<<endl;
        }
    }
    void display(){
            Node *temp = head;
            do{
                cout<<temp->data<<" ";
                temp = temp->next;
            }while(temp != head);       
        }
};
int main(){
    doublelist obj1;
    obj1.insertathead(1);
    obj1.insertathead(2);
    obj1.insertathead(4);
    obj1.insertathead(5);

    obj1.insertattail(6);
    obj1.insertattail(7);

    obj1.updatenode(5,90);

    obj1.insertatposition(4,10);

    obj1.deletenode(5);

    obj1.display();
}