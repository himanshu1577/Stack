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
void insertathead(Node* &head,int d){
	Node* temp=new Node(d);
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void insertattail(Node* &tail,int d){
	Node* temp=new Node(d);
	tail->next=temp;
	temp->prev=tail;
	tail=tail->next;
	
}
void pos(Node* &head, Node* &tail,int d,int position){
	if(position==1){
	insertathead(head,d);
	return;	
	}
	int cnt=1;
	Node* temp=head;
	while(cnt<position-1){
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL){
		insertattail(tail,d);
		return ;
	}
	else{
	Node* nodetoinsert=new Node(d);
	nodetoinsert->next=temp->next;
	(temp->next)->prev=nodetoinsert;
	nodetoinsert->prev=temp;
	temp->next=nodetoinsert;	
	}
	
}
int main(){
	Node* node1=new Node(12);
	Node* head=node1;
	Node* tail=node1;
	insertattail(tail,13);
	insertattail(tail,14);
	insertattail(tail,15);
	insertattail(tail,16);
	print(head);
	pos(head,tail,20,4);
	cout<<"inserting in middle pos:"<<endl;
	print(head);
		pos(head,tail,0,1);
		cout<<"inserting at head:"<<endl;
		print(head);
    pos(head,tail,0,8);
    cout<<"inserting at tail:"<<endl;
      print(head);
	
	
	
}