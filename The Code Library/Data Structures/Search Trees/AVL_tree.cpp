#include <bits/stdc++.h>

using namespace std;

template<typename TreeType> struct AVL_Tree {

	struct Node {

		TreeType key = 0;
		int height = 0;

		Node* lefts = nullptr;
		Node* right = nullptr;

	};

	Node* head = nullptr;
	unsigned int tree_size = 0;

	void __initNode(Node* current_node, TreeType key) {
		tree_size++;

		current_node->key = key;
		current_node->height = 1;

		current_node->lefts = new Node;
		current_node->right = new Node;
	}

	bool __isInit(Node* current_node) const {
		return (current_node->lefts != nullptr) && (current_node->right != nullptr);
	}

	void __destroyTree(Node* current_node) {
		if (__isInit(current_node)) {
			__destroyTree(current_node->lefts);
			__destroyTree(current_node->right);
		}
		delete current_node;
	}

	void __smallLeftRotation(Node* current_node, Node* last_node) { // Left left node rotation
		Node* left_node = current_node->lefts;

		if (last_node != nullptr) {
			if (last_node->lefts == current_node) {
				last_node->lefts = left_node;
			}
			else {
				last_node->right = left_node;
			}
		}
		else {
			head = left_node;
		}

		current_node->lefts = left_node->right;
		left_node->right = current_node;

		current_node->height = max(current_node->lefts->height, current_node->right->height) + 1;
		left_node->height = max(left_node->lefts->height, left_node->right->height) + 1;
	}
	void __smallRightRotation(Node* current_node, Node* last_node) { // Right right node rotation
		Node* right_node = current_node->right;

		if (last_node != nullptr) {
			if (last_node->lefts == current_node) {
				last_node->lefts = right_node;
			}
			else {
				last_node->right = right_node;
			}
		}
		else {
			head = right_node;
		}

		current_node->right = right_node->lefts;
		right_node->lefts = current_node;

		current_node->height = max(current_node->lefts->height, current_node->right->height) + 1;
		right_node->height = max(right_node->lefts->height, right_node->right->height) + 1;
	}
	void __bigLeftRotation(Node* current_node, Node* last_node) { // Left right node rotation
		__smallRightRotation(current_node->lefts, current_node);
		__smallLeftRotation(current_node, last_node);
	}
	void __bigRightRotation(Node* current_node, Node* last_node) { // Right left node rotation
		__smallLeftRotation(current_node->right, current_node);
		__smallRightRotation(current_node, last_node);
	}

	void __insert(TreeType key, Node* current_node, Node* last_node) {
		if (!__isInit(current_node)) {
			__initNode(current_node, key);
			return;
		}
		if (key < current_node->key) {
			__insert(key, current_node->lefts, current_node);
		}
		if (key > current_node->key) {
			__insert(key, current_node->right, current_node);
		}

		int Hl = current_node->lefts->height;
		int Hr = current_node->right->height;

		if (abs(Hl - Hr) == 0) {
			return;
		}
		if (abs(Hl - Hr) == 1) {
			current_node->height++;
			return;
		}

		if (Hl > Hr) {
			int Hll = current_node->lefts->lefts->height;
			int Hlr = current_node->lefts->right->height;
			if (Hll > Hlr) {
				__smallLeftRotation(current_node, last_node);
			}
			else {
				__bigLeftRotation(current_node, last_node);
			}
		}
		else {
			int Hrl = current_node->right->lefts->height;
			int Hrr = current_node->right->right->height;
			if (Hrl > Hrr) {
				__bigRightRotation(current_node, last_node);
			}
			else {
				__smallRightRotation(current_node, last_node);
			}
		}
	}

	void __getAllElements(TreeType* ans, int& i, Node* current_node) const {
		if (!__isInit(current_node)) {
			return;
		}

		__getAllElements(ans, i, current_node->lefts);
		ans[i++] = current_node->key;
		__getAllElements(ans, i, current_node->right);
	}

	Node* __find(TreeType key) const {
		Node* current_node = head;
		while (__isInit(current_node) && current_node->key != key) {
			if (key < current_node->key) {
				current_node = current_node->lefts;
			}
			else if (key > current_node->key) {
				current_node = current_node->right;
			}
		}
		return current_node;
	}
	Node* __lower_bound(TreeType key) const {
		Node* ans = nullptr;
		Node* current_node = head;
		while (__isInit(current_node)) {
			if (current_node->key < key) {
				current_node = current_node->right;
			}
			else {
				ans = current_node;
				current_node = current_node->lefts;
			}
		}
		return ans;
	}

	AVL_Tree() {
		head = new Node;
	}
	AVL_Tree(const AVL_Tree& T) = delete;
	~AVL_Tree() {
		__destroyTree(head);
	}

	AVL_Tree& operator=(const AVL_Tree& T) = delete;

	bool isExists(TreeType key) const {
		return __isInit(__find(key));
	}

	void insert(TreeType key) { // Adds an element to the tree, if it is already there, then nothing will happen
		__insert(key, head, nullptr);
	}

	TreeType lower_bound(TreeType key) const { // Returns V >= key or nullptr if there is no suitable value
		Node* ans = __lower_bound(key);
		if (ans == nullptr) return nullptr;
		return ans->key;
	}

	unsigned int size() const {
		return tree_size;
	}
	bool empty() const {
		return tree_size == 0;
	}

	TreeType* getAllElements() { // Returns an allocated array with all elements in sorted order
		TreeType* ans = new int[tree_size];
		int i = 0;
		__getAllElements(ans, i, head);
		return ans;
	}
};