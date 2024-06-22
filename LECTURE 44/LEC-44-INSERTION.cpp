 #include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
		this->data=data;
		this->next=NULL;	
		}
	};
	void insertathead(Node* &head,int d){
		Node* temp=new Node(d);  // new node create
		temp->next=head;
		head =temp;
	}
	void print(Node* &head){
		Node *temp1=head;
		while(temp1!=NULL){
			cout<<temp1->data<<endl;
			temp1=temp1->next;
		}	 
	}
int main(){
	Node* node1=new Node(10);  // new node creation 
	Node* node2=new Node(110);  
	cout<<node1->data<<endl;
	cout<<node1->next<<endl;
	Node* head=node1;
	  insertathead(head,12);
	  insertathead(head,14);
	 
	  print(head);
	  // print(head1);

}