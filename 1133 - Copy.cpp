#include <iostream>
#include  <string>
using namespace std;

struct llnode {
	
int val;
llnode* next;	
	
};

typedef llnode* LinkedList;

LinkedList createLL(int v) {
llnode*head;
head = new llnode;
head->val = v;
head->next= NULL;
return head;	
}

LinkedList pushToStartLL(LinkedList head, int v) 
{
	llnode* newhead = new llnode;
	newhead->val=v;
	newhead->next=head;
	return newhead;
}

void printLL(LinkedList head)
{
	llnode* current = head;
	while (current !=NULL) 
	{
	cout <<	current->val << endl;
	current = current->next;
	}
	cout << "----------" << endl;
}

void pushToEndLL(LinkedList head, int v)
{
	llnode* current = head;
	while (current->next != NULL)
	{
			current = current->next;
	}
	llnode* end = new llnode;
	end->val=v;
	end->next=NULL;
	current->next= end;
}

int popLastLL(LinkedList head)
{
		llnode* current= head;
		if (current->next ==NULL) 
		{
			int val = current->val;
			delete current;
			return val;
		}	
		while (current->next->next != NULL)
		{
			current=current->next;
		}
		int v=current->next->val;
		delete current->next;
		current->next =NULL;
		return v;
}




int main() {
		
		LinkedList ll = createLL(1);
		printLL(ll);
	//	cout << ll->val << endl;
	LinkedList ll2 = pushToStartLL(ll, 5);
//	cout << ll2->val << endl;
//	cout << ll2->next->val << endl;
	printLL(ll2);
	
	pushToEndLL(ll2, 8);
	printLL(ll2);
	
		cout << "Popping off the last node, value= " << popLastLL(ll2) << endl;
	printLL(ll2);
	

	
	return 0;
	
}















