#include<iostream>
using namespace std;

struct Node {
	int value;
	struct Node * next;
};

struct SingleLinkedList {

	struct Node * head;
	
	SingleLinkedList() {
		head = new Node();
		head->next = NULL;
	}

	void insertFirst(int d) {
		struct Node * p = new Node();
		p->value = d;
		p->next = head->next;
		head->next = p;
	}

	void insertLast(int d) {
		struct Node * p = new Node();
		p->value = d;
		struct Node *cur = head;
		while(cur->next!= NULL) {
			cur = cur->next;
		}
		p->next = NULL;
		cur->next=p;
	}

	void insertSort(int d) {
		struct Node * p = new Node();
		p->value = d;
		struct Node *cur = head;
		while(cur->next!= NULL) {
			if (cur->next->value > d) break;
			cur = cur->next;
		}
		p->next = cur->next;
		cur->next=p;
	}

	int deleteFirst() {
		struct Node * cur = head->next;
		if (cur == NULL) {
			printf("List is Empty\n");
			return -1;
		}
		int ret = cur->value;
		head->next = cur->next;
		delete cur;
		return ret;
	}

	int deleteLast() {
		struct Node * cur1 = head;
		struct Node * cur2 = head->next;
		if (cur2 == NULL) {
			printf("List is Empty\n");
			return -1;
		}
		while (cur2->next != NULL) {
			cur1 = cur2;
			cur2 = cur2->next;
		}
		int ret = cur2->value;
		cur1->next = NULL;
		delete cur2;
		return ret;
	}

	void push(int d) {
		insertFirst(d);
	}

	int pop() {
		return deleteFirst();
	}

	void enqueue(int d) {
		insertLast(d);
	}

	int dequeue() {
		return deleteFirst();
	}

	void print() {
		struct Node * cur = head->next;
		while(cur!=NULL) {
			printf("%d\t", cur->value);
			cur = cur->next;
		}
		printf("\n");
	}

	int isEmpty() {
		return (head->next==NULL);

	}
};

int main() {
	SingleLinkedList list;
	list.push(10);
	list.push(20);
	list.push(30);
	list.push(40);
	list.push(50);
	list.print();
	while(!list.isEmpty()) {
		printf("%d\n", list.pop());
		//list.print();
	}
	return 0;
}
