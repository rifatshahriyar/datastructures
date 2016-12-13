#include<iostream>
using namespace std;

struct Node {
	int value;
	struct Node * prev;
	struct Node * next;
};

struct DoubleLinkedList {

	struct Node * head, * tail;

	DoubleLinkedList() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;	
	}

	void insertFirst(int d) {
		struct Node * p = new Node();
		p->value = d;
		p->next = head->next;
		p->prev = head;
		head->next->prev = p;
		head->next = p;
	}

	void insertLast(int d) {
		struct Node * p = new Node();
		p->value = d;
		p->prev = tail->prev;
		p->next = tail;
		tail->prev->next = p;		
		tail->prev = p;
	}

	int deleteFirst() {
		struct Node * cur = head->next;
		if (cur == NULL) {
			printf("List is Empty\n");
			return -1;
		}
		int ret = cur->value;
		head->next = cur->next;
		cur->next->prev = head;
		delete cur;
		return ret;
	}

	int deleteLast() {
		struct Node * cur = tail->prev;
		if (cur == NULL) {
			printf("List is Empty\n");
			return -1;
		}
		int ret = cur->value;
		cur->prev->next = tail;
		tail->prev = cur->prev;
		delete cur;
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
		while(cur!=tail) {
			printf("%d\t", cur->value);
			cur = cur->next;
		}
		printf("\n");
	}

	void print2() {
		struct Node * cur = tail->prev;
		while(cur!=head) {
			printf("%d\t", cur->value);
			cur = cur->prev;
		}
		printf("\n");
	}


	int isEmpty() {
		return (head->next == tail) && (tail->prev == head);
	}
};

int main() {
	DoubleLinkedList list;
	list.enqueue(10);
	list.enqueue(20);
	list.enqueue(30);
	list.enqueue(40);
	list.enqueue(50);
	list.print();
	list.print2();
	while(!list.isEmpty()) {
		printf("%d\n", list.dequeue());
		list.print2();
	}
	return 0;
}
