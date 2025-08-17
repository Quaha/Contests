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

template<typename QueueType> struct Queue {

	QueueType func(const QueueType& A, const QueueType& B) {
		return std::min(A, B);
	}

	Stack<QueueType> front_part;
	Stack<QueueType> back_part;

	void push(const QueueType& value) {
		back_part.push(value);
	}

	void pop() {
		if (front_part.empty()) {
			while (!back_part.empty()) {
				front_part.push(back_part.back());
				back_part.pop();
			}
		}
		front_part.pop();
	}

	int size() {
		return front_part.size() + back_part.size();
	}

	bool empty() {
		return (front_part.size() + back_part.size() == 0);
	}

	QueueType front() {
		if (front_part.isEmpty()) {
			while (!back_part.isEmpty()) {
				front_part.push(back_part.back());
				back_part.pop();
			}
		}
		return front_part.back();
	}

	QueueType getFuncValue() {
		if (front_part.empty()) {
			return back_part.getFuncValue();
		}
		if (back_part.empty()) {
			return front_part.getFuncValue();
		}
		return func(front_part.getFuncValue(), back_part.getFuncValue());
	}
};