#include <iostream>
using namespace std;

class list{
	public:
		list();
		bool empty();
		int size();
		void add(int k,int x);
		int get(int k);
		void remove(int k);
		void printList();
};

struct Node{
		int data;
		Node* next;
};

struct Node* list_head;

list::list(){
	list_head=NULL;
}

bool list::empty(){
	if(list_head==NULL){
		return true;
	}
	else{
		return false;
	}
}

int list::size(){
	int size=0;
	Node* temp=new Node();
	temp=list_head;
	while(temp!=NULL){
		size++;
		temp=temp->next;
	}
	delete temp;
	return size;
}

int list::get(int k){
	Node* temp=new Node();
	int count=0;
	temp=list_head;
	while(temp!=NULL){
		if(count==k-1){
			cout<<temp->data<<endl;
			return 0;
		}
		count++;
		temp=temp->next;
	}
}

void list::add(int k,int x){
	Node* temp1=new Node();
	temp1->data=x;
	temp1->next=NULL;
	if(k==1){
		temp1->next=list_head;
		list_head=temp1;
		return;
	}
	Node* temp2=list_head;
	for(int i=0;i<k-2;i++){
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
}

void list::remove(int k){
	Node* temp1=new Node();
	temp1=list_head;
	if(k==1){
		list_head=temp1->next;
		delete temp1;
		return;
	}
	for(int i=0;i<k-2;i++){
		temp1=temp1->next;
	}
	struct Node* temp2=new Node();
	temp2=temp1->next;
	temp1->next=temp2->next;
	delete temp2;
}

void list::printList(){
	Node* temp;
	temp=list_head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}	
}

int main(){
	list obj;
	list_head=NULL;
	int K,X,N,M;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>K>>X;
		obj.add(K,X);
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>K;
		obj.remove(K);
	}
	cin>>K;
	int size=obj.size();
	cout<<size<<" ";
	obj.get(K);
}
