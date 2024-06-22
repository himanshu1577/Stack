#include <iostream>
#include<map>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			this-> next=NULL;
		}
};
void insertattail(Node* &tail,int d){
	Node* temp=new Node(d);
	tail->next=temp;
	tail=temp;
}
	void print(Node* &head){
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		}	 
	}
Node* flyod(Node* head){
	if(head==NULL ){
		return NULL;
	}
	Node* slow=head;
	Node* fast=head;
	while(slow!=NULL && fast!=NULL){
		fast=fast->next;
		if(fast->next!=NULL){
			fast=fast->next;
		}
		slow=slow->next;
		if(slow==fast){
			return slow;
		}
	}
	return NULL;
}
Node* startingpoint(Node* head){
       if(head==NULL){
       	return NULL;
	   }
	   Node* meet=flyod(head);
	   Node* slow=head;
	   while(slow!=meet){
	   	slow=slow->next;
	   	meet=meet->next;
	   }
	   return slow;
	   	
}
int main(){
	Node* node1=new Node(10);
	//cout<<node1->data<<endl;
	Node* head=node1;
	Node* tail=node1;
	insertattail(tail,20); 	
	insertattail(tail,30);
	insertattail(tail,40);
	insertattail(tail,50); 	
	insertattail(tail,60);
	insertattail(tail,70);
	print(head);
	tail->next=head->next->next->next;
	cout<<"checking loop:"<<endl;
	if(flyod(head)!=NULL){
		cout<<"yes loop is there"<<endl;
	}
	cout<<"starting point of loop is: ";
	cout<<startingpoint(head)->data<<endl;
	
	
	
   
}
