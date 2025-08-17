#include <bits/stdc++.h>

using namespace std;

struct BitBor {

	/*
	This structure allows you to find among a set of numbers such that x^ value is the maximum
	*/

	struct Node {

		Node* left_node = nullptr; // 0
		Node* right_node = nullptr; // 1

		int cnt = 0;
	};

	const int number_of_bits = 32;
	Node* head = nullptr;

	BitBor(int number_of_bits) : number_of_bits(number_of_bits) {
		head = new Node;
		head->cnt = 2e15 + 14;
	}

	void __add(int x, int current_bit, Node* current_node) {
		if (current_bit == 0) {
			return;
		}
		int next_bit = current_bit - 1;

		if (((1ll << next_bit) & x) == 0) {
			if (current_node->left_node == nullptr) {
				current_node->left_node = new Node;
			}
			current_node->left_node->cnt++;
			__add(x, next_bit, current_node->left_node);
		}
		else {
			if (current_node->right_node == nullptr) {
				current_node->right_node = new Node;
			}
			current_node->right_node->cnt++;
			__add(x, next_bit, current_node->right_node);
		}
	}

	void add(int x) {
		__add(x, number_of_bits, head);
	}

	int __get(int x, int current_bit, Node* current_node) const {
		if (current_bit == 0) {
			return x;
		}
		int next_bit = current_bit - 1;

		if (((1ll << next_bit) & x) == 0) {
			if (current_node->right_node == nullptr) {
				return __get(x, next_bit, current_node->left_node);
			}
			return __get(x ^ (1ll << next_bit), next_bit, current_node->right_node);
		}
		else {
			if (current_node->left_node == nullptr) {
				return __get(x ^ (1ll << next_bit), next_bit, current_node->right_node);
			}
			return __get(x, next_bit, current_node->left_node);
		}
	}

	int sum(int x) {
		if (head->left_node == nullptr && head->right_node == nullptr) {
			return 0;
		}
		return __get(x, number_of_bits, head);
	}

	void __erase(int x, int current_bit, Node* current_node) {
		if (current_bit == 0) {
			return;
		}
		int next_bit = current_bit - 1;

		if (((1ll << next_bit) & x) == 0) {
			__erase(x, next_bit, current_node->left_node);
			current_node->left_node->cnt--;
			if (current_node->left_node->cnt == 0) {
				delete current_node->left_node;
				current_node->left_node = nullptr;
			}
		}
		else {
			__erase(x, next_bit, current_node->right_node);
			current_node->right_node->cnt--;
			if (current_node->right_node->cnt == 0) {
				delete current_node->right_node;
				current_node->right_node = nullptr;
			}
		}
	}

	void erase(int x) { // dont erase elements which wasn't added
		__erase(x, number_of_bits, head);
	}
};