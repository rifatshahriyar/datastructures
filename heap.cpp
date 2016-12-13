#include<iostream>
using namespace std;
#define BSIZE 100
#define BNULL -99

struct Heap {
	int root;
	int count;
	int a[BSIZE];

	Heap(int rootValue) {
		root = 1;
		a[root] = rootValue;
		count = 1;
		for (int i = 2; i < BSIZE; i++) {
			a[i] = BNULL;
		}
	}

	int left(int i) {
		return 2*i;
	}

	int right(int i) {
		return 2*i + 1;
	}

	int parent(int i) {
		return i/2;
	}

	void insertElement(int x) {
		a[++count] = x;	
		int v = count;
		while (v != root) { 
			int u = parent(v);
			if (a[u] < a[v]) break;
			swap(v, u); 
			v = u;
		}
	}

	int deleteElement() {
		int ret = a[root];
		int u = root; 
		swap(u, count); 
		a[count--] = BNULL;
		while (a[left(u)]!= BNULL) { 
			int v = left(u);
			int w = right(u);
			if (a[w]!= BNULL && a[w] < a[v])
				v = w;
			if (a[v] < a[u]) { 
				swap(u, v); 
				u = v;
			} else {
				break;
			} 
		}
		return ret;
	}

	void swap(int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	void preorder() {
		preorder(root);
		cout << endl;
	}

	void preorder(int node){
		if(a[node] == BNULL) return;
		cout << " " << a[node] << " ";
		preorder(left(node));
		preorder(right(node));
	}

	void postorder() {
		postorder(root);
		cout << endl;
	}

	void postorder(int node){
		if(a[node] == BNULL) return;
		postorder(left(node));
		postorder(right(node));
		cout << " " << a[node] << " ";
	}

	int isEmpty() {
		return count == 0;
	}
};

int main(){
	Heap heap(11);	 
	heap.insertElement(15);
	heap.insertElement(13);
	heap.insertElement(5);
	heap.insertElement(7);
	heap.insertElement(9);
	heap.insertElement(17);
	heap.insertElement(1);
	heap.insertElement(3);

	while (!heap.isEmpty()) {
		cout << heap.deleteElement() << endl;
	}

	return 0;
}
