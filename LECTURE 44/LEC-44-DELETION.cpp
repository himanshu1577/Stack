#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			this-> next=NULL;
		}
		~Node(){
			if(this->next!=NULL){
				delete next;
				this->next=NULL;
			}
		}
};
void insertattail(Node* &tail,int d){
	Node* temp=new Node(d);
	tail->next=temp;
	tail=temp;
}
void deletion(Node * &head,int pos){
	if(pos==1){
		Node* temp=head;
		head=head->next;
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
	cout<<endl;
	deletion(head,1);
	cout<<"after deletion1"<<endl;
	cout<<tail->data<<endl;
	print(head);
}