#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int d){
			data=d;
			this-> next=NULL;
		}
};
void insertathead(Node* &head,int d){
		Node* temp=new Node(d);  
		temp->next=head;
		head =temp;
	}
void insertattail(Node* &tail,int d){
	Node* temp=new Node(d);
	tail->next=temp;
	tail=temp;
}
void insertatpos(int position,Node* &head,Node* &tail,int d){
	if(position==1){
		insertathead(head,d);
		return;
	}
	int cnt=1;
	Node* temp=head;
	Node* nodetoinsert=new Node(d);
	while(cnt< position-1){
		temp=temp->next;
		cnt++;  
	}
	if(temp->next==NULL){
		insertattail(tail,d);
		return;
	}
	else{
	nodetoinsert->next=temp->next;
	temp->next=nodetoinsert;
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
int main(){
	Node* node1=new Node(10);
	Node* head=node1;
	Node* tail=node1;
	insertattail(tail,20); 	insertattail(tail,30);
	insertattail(tail,40);  insertattail(tail,50); 
	insertattail(tail,60);	insertattail(tail,70);
	print(head);
	insertatpos(5,head,tail,45);
	cout<<"LINKED LIST AFTER ADDING ELEMENT IN MIDDLE "<<endl;
	print(head);
	insertatpos(1,head,tail,5);
	insertatpos(10,head,tail,75);
	cout<<"LINKED LIST AFTER ALL "<<endl;
	print(head);	
}