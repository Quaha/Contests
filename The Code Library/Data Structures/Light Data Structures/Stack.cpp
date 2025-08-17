#include <bits/stdc++.h>

using namespace std;

template<typename StackType> struct Stack {

	StackType func(const StackType& A, const StackType& B) {
		return min(A, B);
	}

	vector<StackType> main_stack;
	vector<StackType> func_stack;

	void push(const StackType& value) {
		main_stack.push_back(value);
		if (func_stack.empty()) {
			func_stack.push_back(value);
		}
		else {
			func_stack.push_back(func(func_stack.back(), main_stack.back()));
		}
	}

	void pop() {
		main_stack.pop_back();
		func_stack.pop_back();
	}

	int size() {
		return main_stack.size();
	}

	bool empty() {
		return main_stack.size() == 0;
	}

	StackType back() {
		return main_stack.back();
	}

	StackType getFuncValue() {
		return func_stack.back();
	}
};