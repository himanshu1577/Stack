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
		~Node(){
			if(this->next!=NULL){
				delete next;
				this->next=NULL;
			}
		}
};
void deletion(Node * &head,int pos){
	if(pos==1){
		Node* temp=head;
	   temp->next->prev=NULL;
	   head=temp->next;
	   temp->next=NULL;
		delete temp;
	}
	else{
		int cnt=1;
		Node* prev=NULL;
		Node* curr=head;
		while(cnt<pos){
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		curr->prev=NULL;
		prev->next->prev=prev;
		prev->next=curr->next;
		curr->next=NULL;
		delete curr;
	
	}
	
}
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
		insertattail(tail,16);
	print(head);
	deletion(head,5);
	cout<<tail->data<<endl;
	print(head);
	
}