#include<iostream>
using namespace std;
class Node{
    public:
	int data;
	Node *next;
	public:
		//parametrized constructor
		 Node(int data ){
		 	this->data = data;
		 	next = NULL;
		 }
		 //default constructor
		 Node(){
		 	data = 0;
		 	next = NULL; 
		 } 
        ~Node(){
            int value = this ->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"the data at the deleted node was"<<value<<endl;
        }
};
class circular{
	public:
		Node *head;
		Node *tail;
		//default constructor
		circular(){
			head = tail =NULL;
		}
		
		//parametrized constructor
		circular(Node *n){
			head  = n;
		}
        //function to insert at head
        void insertathead(int data){
            if(head == NULL){
                Node *newnode = new Node(data);
                head = tail = newnode;

            }
            else{
                Node *newnode = new Node(data);
                newnode->next = head;
                head = newnode;
            }
            tail->next = head;
        }
        //function to insert at tail
        void insertattail(int data){
            if(head == NULL){
                Node *newnode = new Node(data);
                head = tail = newnode;
            }
            else{
                Node *newnode = new Node(data);
                tail->next = newnode;
                newnode->next = head;
                tail = newnode;
            }
        }
        //function to insert at a position
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

            if(temp->next == head){
                insertattail(data);
                return ;
            }
        }
        //function to delete
        void deletenode(int position){
            int ctr = 1;

            if(head==NULL){
                cout<<"The list is empty"<<endl;
            }
            if(position ==1){
                Node *temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
                tail->next=head;
            }
            else{
                Node *curr = head;
                Node *pre = NULL;

                while(ctr < position){
                    pre = curr;
                    curr = curr->next;
                    ctr++;
                }
                pre->next = curr->next;
                curr->next = NULL;
                delete curr;
            }
        }
        //function to update
        void update(int position , int value){
            int counter = 1;
            Node *temp = head;

             while(counter < position){
                counter++;
                temp = temp->next;
            }
            
            temp->data = value;
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
    circular obj1;
    obj1.insertathead(1);
    obj1.insertathead(2);
    obj1.insertathead(4);
    obj1.insertathead(5);

    obj1.insertattail(10);
    obj1.insertattail(18);

    obj1.insertatposition(5,15);

    obj1.deletenode(1);

    obj1.update(3,55);
    
    obj1.display();
}