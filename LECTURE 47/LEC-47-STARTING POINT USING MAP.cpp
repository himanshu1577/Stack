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
Node* startingpoint(Node* head){
	if(head==NULL){
		return NULL;
	}
	map<Node*,int>visit;
	Node* temp=head;
	while(temp!=NULL){
		if(visit[temp]==1){
			cout<<"loop"<<endl;
			return temp;
		}
		visit[temp]=1;
		temp=temp->next;
	}
	return NULL;	
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
	tail->next=head->next;
	cout<<startingpoint(head)->data<<endl;
   
}
