#include<stdio.h>
#define MAXSIZE 100

int s[MAXSIZE]; // array to store the stack elements
int t = 0; 		// index for the top element

void push(int e) {
	s[t++] = e;
}

int pop() {
	return s[--t];
}

int isEmpty() {
	return t <= 0;
}

int top() {
	return s[t-1];
}

int size() {
	return t;
}

int main() {
	int n,d,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &d);
		push(d);
	}
	printf("Size : %d\n", size());
	while (!isEmpty()) {
		printf("%d ", pop());
		printf("	Size : %d\n", size());

	}
	return 0;
}
