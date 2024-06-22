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
void insertathead(Node* &head,Node* &tail,int d){
	if(head==NULL){
		Node* temp=new Node(d);
		head=temp;
		tail=temp;
	}
	else{
	Node* temp=new Node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
	}
}
int main(){
	Node* node1=NULL;
	Node* head=node1;
	Node* tail=NULL;
	insertathead(head,tail,13);
	print(head);
	insertathead(head,tail,14);
	print(head);
	insertathead(head,tail,15);
	print(head);
		
}