#include<iostream>
using namespace std;
#define SIZE 100

struct Graph {
	int a[SIZE][SIZE];
	int n;

	Graph() {
		n = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				a[i][j] = 0;
			}
		}
	}

	int totalVertices() {
		return n;
	}

	int addVertex() {
		n++;
	}

	int addEdge(int i, int j) {
		a[i][j] = 1;
		a[j][i] = 1;
	}

	int addDirectEdge(int i, int j) {
		a[i][j] = 1;
	}

	int isNeighbour(int i, int j) {
		return a[i][j] == 1;
	}

	int * neighbours(int i) {
		int *b = new int[n+1];
		for (int j = 0; j <= n; j++) {
			b[j] = 0;
		}
		int k = 0;
		for (int j = 1; j < n; j++) {
			if (a[i][j] == 1) b[k++] = j;
		} 
		return b;
	}

	void printGraph() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main(){
	Graph  graph;

	graph.addVertex();
	graph.addVertex();
	graph.addVertex();
	graph.addVertex();

	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 3);
	graph.addEdge(2, 4);


	graph.printGraph();

	int * x  = graph.neighbours(4);
	int i = 0;
	while(1) {
		int y = x[i++];
		if (y == 0) break;
		cout << y << "\t";
	}
	cout << endl;

	return 0;
}
