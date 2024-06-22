#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int d){
			this->data=d;
			this->next=NULL;
		}
		~Node(){
			if(this->next!=NULL){
				delete next;
				this->next=NULL;
			}
		}
};
void insertnode(Node* &tail,int element,int d){
	// assuming that the element will be there
	
	// empty list
	if(tail==NULL){
	 Node* newNode=new Node(d);
	 tail=newNode;
	 newNode->next=newNode;	
	}
	else{
		//non element list
		Node* curr=tail;
		while(curr->data!=element){
			curr=curr->next;
		}
		Node* temp=new Node(d);
		temp->next=curr->next;
		curr->next=temp;
	}
}
void print(Node* tail){
	Node* temp=tail;
	do{
		cout<<tail->data<<" ";
		tail=tail->next;
	}while(tail!=temp);
	cout<<endl;
}
int main(){
	Node* tail=NULL;
	insertnode(tail,5,3);
	print(tail);
	insertnode(tail,3,5);
	insertnode(tail,5,7);
    print(tail);
	
}