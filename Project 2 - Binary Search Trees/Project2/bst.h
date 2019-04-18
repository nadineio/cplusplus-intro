#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class BST {

	struct node {
		T		item;
		node*	left;
		node*	right;
	};

	node* root;

	node* empty(node* t) {
		if (t != NULL) {
			empty(t->left);
			empty(t->right);
			delete t;
		}
		else {
			return NULL;
		}
	}

	node* insert(T x, node* t) {
		if (t == NULL) {
			t = new node;
			t->item = x;
			t->left = t->right = NULL;
		} 
		else if (x.getKey() < t->item.getKey()) {
			t->left = insert(x, t->left);
		}
		else if (x.getKey() > t->item.getKey()) {
			t->right = insert(x, t->right);
		}

		return t;
	}

	node* findMin(node* t) {
		if (t == NULL) {
			return NULL;
		}
		else if (t->left == NULL) {
			return t;
		}
		else {
			return findMin(t->left);
		}
	}

	node* findMax(node* t) {
		if (t == NULL) {
			return NULL;
		}
		else if (t->right == NULL) {
			return t;
		}
		else {
			return findMax(t->right);
		}
	}

	node* remove(T x, node* t) {
		node* temp;
		if (t == NULL) {
			return NULL;
		}
		else if (x.getKey() < t->item.getKey()) {
			t->left = remove(x, t->left);
		}
		else if (x.getKey() > t->item.getKey()) {
			t->right = remove(x, t->right);
		}
		else if (t->left && t->right) {
			temp = findMin(t->right);
			t->item = temp->item;
			t->right = remove(t->item, t->right);
		}
		else {
			temp = t;
			if (t->left == NULL) {
				t = t->right;
			}
			else if (t->right == NULL) {
				t = t->left;
			}
			delete temp;
		}

		return t;
	}

	void inorder(node* t, ostream &ostr) {
		if (t == NULL) {
			return;
		}
		inorder(t->left, ostr);
		t->item.print(ostr);
		inorder(t->right, ostr);
	}

	node* find(node* t, T x) {
		if (t == NULL) {
			return NULL;
		}
		else if (x.getKey() < t->item.getKey()) {
			return find(t->left, x);
		}
		else if (x.getKey() > t->item.getKey()) {
			return find(t->right, x);
		}
		else {
			return t;
		}
	}
	

public:
	BST() {
		root = NULL;
	}

	~BST() {
		root = empty(root);
	}

	void insert(T x) {
		root = insert(x, root);
	}

	void remove(T x) {
		root = remove(x, root);
	}

	void display(ostream &ostr) {
		inorder(root, ostr);
		cout << endl;
	}

	void search(T x) {
		root = find(root, x);
		root->item.print(cout);
	}

};