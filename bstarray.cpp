#include<iostream>
using namespace std;
#define BSIZE 100
#define BNULL -99

struct BST {
	int root;
	int a[BSIZE];

	BST(int rootValue) {
		root = 0;
		a[root] = rootValue;
		for (int i = 1; i < BSIZE; i++) {
			a[i] = BNULL;
		}
    }
    
    int left(int i) {
    	return 2*i + 1;
    }
    
    int right(int i) {
    	return 2*i + 2;
    }
    
	void insertElement(int x) {
		insertElement(root, x);	
	}

	void insertElement(int node, int x){
	    if(a[node] == BNULL){
	    	a[node] = x;
	    	return;
	    }
	    else {
			if(x < a[node]){
				insertElement(left(node), x);
			}
			else if(x > a[node]){
		    	insertElement(right(node), x);
			}
        	else if(x == a[node]){
        	    cout << "The element is already present in the tree." << endl;
        	    return;
        	}
    	}
	}

	void findElement(int x) {
		int find = findElement(root, x);
		if (find != BNULL) cout << "Found: " << find << endl;	
		else cout << "Not Found: " << x << endl;	
	}


	int findElement(int node, int x){
    	if (a[node] == BNULL || a[node] == x) {
       		return a[node];
    	}
    	if(x < a[node]){
			return findElement(left(node), x);	 
    	}
   		else {
			return findElement(right(node), x);	     
    	}
	}
	
	void inorder() {
    	inorder(root);
    	cout << endl;
    }

	void inorder(int node){
    	if(a[node] == BNULL) return;
    	inorder(left(node));
    	cout << " " << a[node] << " ";
    	inorder(right(node));
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

};

int main(){
	BST tree(11);
    tree.insertElement(15);
    tree.insertElement(13);
    tree.insertElement(5);
    tree.insertElement(7);
    tree.insertElement(9);
    tree.insertElement(17);
    tree.insertElement(1);
    tree.insertElement(3);

    tree.preorder(); 
    tree.inorder();  
    tree.postorder(); 	

    tree.findElement(5);
    tree.findElement(1);
    tree.findElement(19);
    
	return 0;
}
