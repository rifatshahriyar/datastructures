#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node * left;
	struct Node * right;
};

struct BST {

	Node * root;

	BST(int rootValue) {
		root = createNode(rootValue);
	}

	Node * createNode(int x){
		Node * tmp = new Node();
		tmp->data = x;
		tmp->left = NULL;
		tmp->right = NULL;
		return tmp;
	}

	void insertElement(int x) {
		insertElement(root, x);	
	}

	Node * insertElement(Node * node, int x){
		if(node == NULL){
			return createNode(x);
		}
		else {
			if(x < node->data){
				node->left = insertElement(node->left, x);
				return node; 
			}
			else if(x > node->data){
				node->right =  insertElement(node->right, x);
				return node; 
			}
			else if(x == node->data){
				cout << "The element is already present in the tree." << endl;
				return node;
			}
		}
	}

	Node * insertElement2(Node *node, int x) {
		Node * newNode = createNode(x);

		while(node != NULL) {
			if(x < node->data) {
				if(node->left == NULL)
				{
					node->left = newNode;
					return newNode;
				}
				else {
					node = node->left;
				}
			}
			else if(x > node->data) {
				if(node->right == NULL)
				{	
					node->right = newNode;
					return newNode;
				}
				else {
					node = node->right;
				}
			}
			else if(x == node->data) {
				cout << "The element is already present in the tree." << endl;
				return newNode;
			}
		}
		return newNode;
	}

	void findElement(int x) {
		Node * find = findElement(root, x);
		if (find != NULL) cout << "Found: " << find->data << endl;	
		else cout << "Not Found: " << x << endl;	
	}


	Node * findElement(Node *node, int x){
		if (node == NULL || node->data == x) {
			return node;
		}
		if(x < node->data){
			return findElement(node->left, x);	 
		}
		else {
			return findElement(node->right, x);	     
		}
	}

	Node * findElement2(Node *node, int x){
		while (node != NULL && node->data != x) {
			if(x < node->data){
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		return node;
	}

	void inorder() {
		inorder(root);
		cout << endl;
	}

	void inorder(Node *node){
		if(node == NULL) return;
		inorder(node->left);
		cout << " " << node->data << " ";
		inorder(node->right);
	}

	void preorder() {
		preorder(root);
		cout << endl;
	}

	void preorder(Node *node){
		if(node == NULL) return;
		cout << " " << node->data << " ";
		preorder(node->left);
		preorder(node->right);
	}

	void postorder() {
		postorder(root);
		cout << endl;
	}

	void postorder(Node *node){
		if(node==NULL) return;
		postorder(node->left);
		postorder(node->right);
		cout << " " << node->data << " ";
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
