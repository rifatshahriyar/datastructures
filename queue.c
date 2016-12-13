#include<stdio.h>
#define MAXSIZE 100

int q[MAXSIZE]; // array to store the queue elements
int f; 			// index for the front element
int r; 			// index for immediately past the rear element

void enqueue(int e) {
	q[r++] = e;
}

int dequeue() {
	return q[f++];	
}

int isEmpty() {
	return r == f;
}

int front() {
	return q[f];
}

int size() {
	return r - f;
}

int main() {
	int n,d,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &d);
		enqueue(d);
	}
	printf("Size : %d\n", size());
	while (!isEmpty()) {
		printf("%d ", dequeue());
		printf("	Size : %d\n", size());

	}
	return 0;
}
