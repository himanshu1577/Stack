#include <iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* prev;
	Node* next;
	Node(int d){
		this->data=d;
		this->prev=NULL;
		this->next=NULL;		
	}
};
void print(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void insertattail(Node* &tail,int d){
	Node* temp=new Node(d);
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next;
	
}
int main(){
	Node* node2=new Node(12);
	Node* head=node2;
	Node* tail=node2;
	insertattail(tail,13);
	print(head);
		insertattail(tail,14);
	print(head);
		insertattail(tail,15);
	print(head);
	
}