#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next = NULL;
};

#pragma region prototypes
	//prototypes
	void printListRecursive(Node* nodeRef);
	void printList(Node* headRef, bool newLine);
	void pushHead(Node** headRef, int data);
	void popHead(Node** headRef);
	void pushBack(Node* headRef, int data);
	void pushBackRecursive(Node* headRef, int data);
	void popBack(Node* headRef);
	void popBackRecursive(Node* nodeRef);
	int countNodesRecursive(Node* headRef);
	void countNode(Node* nodeRef, int* t_counter);

#pragma endregion

int main(){
	Node* head = new Node();
	head->data = 0;

	cout << endl << "---------------" << endl;


	printListRecursive(head);
	cout << endl << "---------------" << endl;

	return 0;
}

#pragma region functions
//functions
void printListRecursive(Node* nodeRef){
	if(nodeRef == NULL) {
		cout << "The list is empty";
		return;
	}
	if(nodeRef->next == NULL){
		cout << "[" << nodeRef->data << "] ";
		return;
	}
	
	cout << "[" << nodeRef->data << "] ";
	
	printListRecursive(nodeRef->next);
}

void printList(Node* headRef, bool newLine){
	if(headRef == NULL) {
		cout << "The list is empty";
		return;
	}

	if(newLine) cout << endl;

    while(headRef != NULL){
        cout << headRef->data << " ";

        headRef = headRef->next;
    }
}


void pushHead(Node** headRef, int data){
	if(headRef == NULL) {
		cout << "The list is empty";
		return;
	}

	Node* newHead = new Node();
	newHead->data = data;
	newHead->next = *headRef;

	*headRef = newHead;
}


void popHead(Node** headRef){
	if(*headRef == NULL) {
		cout << "The list is empty";
		return;
	}
     
    Node* temp = *headRef;
	*headRef = temp->next;

	free(temp);            
	
	return;
}


void pushBack(Node* headRef, int data){
	if(headRef == NULL) {
		cout << "The list is empty";
		return;
	}

	Node* newNode = new Node();
	newNode->data = data;

	while(headRef->next != NULL){
		headRef = headRef->next;
	}

	headRef->next = newNode;
}

void pushBackRecursive(Node* nodeRef, int data){
	if(nodeRef == NULL) {
		cout << "The list is empty";
		return;
	}

	if(nodeRef->next == NULL){
		Node* newNode = new Node();
		newNode->data = data;

		nodeRef->next = newNode;
		return;
	}

	pushBackRecursive(nodeRef->next, data);
}


void popBack(Node* headRef){
    if(headRef == NULL) return;
     
    while(headRef->next->next != NULL){
		headRef = headRef->next;
	}

	free(headRef->next);
	headRef->next = NULL;            
	
	return;
}

void popBackRecursive(Node* nodeRef){
    if(nodeRef == NULL){
		cout << "The list is empty";
		return;
	} 
    if(nodeRef->next == NULL){
		cout << "The list has only one element";
		return;
	} 
	
	if(nodeRef->next->next == NULL){
		free(nodeRef->next);
		nodeRef->next = NULL;  
		return;
	}

	popBackRecursive(nodeRef->next);           
}


int countNodesRecursive(Node* headRef){
	if(headRef == NULL) {
		return 0;
	}
	int counter = 0;

	countNode(headRef, &counter);
	
	return counter;
}
void countNode(Node* nodeRef, int* t_counter) {
	if(nodeRef->next == NULL){
		*t_counter = *t_counter + 1;
		return;
	}

	*t_counter = *t_counter + 1;

	countNode(nodeRef->next, t_counter);
}

#pragma endregion
