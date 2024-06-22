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
bool iscircular(Node* head){
	if(head==NULL){
		return false;
	}
	if(head->next==head){
		return true;
	}
	Node* temp=head;
	map<Node*,bool> visit;
	while(temp!=NULL){
		if(visit[temp]==true){
			cout<<"LL is looped"<<endl;
			cout<<temp->data<<endl;
			return true;
		}
		visit[temp]=true;
		temp=temp->next;
	}
	return false;
}
int main(){
	Node* node1=new Node(10);
	cout<<node1->data<<endl;
	Node* head=node1;
	Node* tail=node1;
	insertattail(tail,20); 	
	insertattail(tail,30);
	insertattail(tail,40);
	print(head);
	tail->next=head->next;
	if(iscircular(head)){
		cout<<"yes"<<endl;
	}
	
	
	
	
}
