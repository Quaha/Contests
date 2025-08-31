#include <bits/stdc++.h>

using namespace std;

template<typename TreeType> struct RangeSegmentTree {

	const static inline TreeType FILLER = 0;

	struct Data {
		TreeType value = FILLER;
		int id = 0;
	};

	struct Operation {
		int type = 0;
		int value = 0;
	};

	struct Node {
		Data data;
		Operation operation;
	};

	const static inline Node FILLER_NODE = { FILLER, 0 };

	int size = 0;
	vector<Node> tree;

	Data func(const Data& A, const Data& B) {
		if (A.value > B.value) {
			return A;
		}
		return B;
	}

	void __propagate(int __i, int __l, int __r) {
		if (tree[__i].operation.type == 0) {
			tree[__i].data.value += tree[__i].operation.value;
		}

		if (__r - __l > 1) {
			if (tree[__i].operation.type == 0) {
				tree[__i * 2 + 1].operation.value += tree[__i].operation.value;
				tree[__i * 2 + 2].operation.value += tree[__i].operation.value;
			}
		}

		tree[__i].operation.type = 0;
		tree[__i].operation.value = 0;
	}

	void __init(int __i, int __l, int __r) {
		tree[__i].data.id = __l;
		if (__r - __l > 1) {
			int __m = (__l + __r) / 2;
			__init(__i * 2 + 1, __l, __m);
			__init(__i * 2 + 2, __m, __r);
		}
	}

	void __update(const TreeType& value, int l, int r, int type, int __i, int __l, int __r) {
		__propagate(__i, __l, __r);
		if (__r <= l || r <= __l) {
			return;
		}
		if (l <= __l && __r <= r) {
			tree[__i].operation.value = value;
			tree[__i].operation.type = type;
			__propagate(__i, __l, __r);
			return;
		}
		int __m = (__l + __r) / 2;
		__update(value, l, r, type, __i * 2 + 1, __l, __m);
		__update(value, l, r, type, __i * 2 + 2, __m, __r);
		tree[__i].data = func(tree[__i * 2 + 1].data, tree[__i * 2 + 2].data);
	}

	Data __get(int l, int r, int __i, int __l, int __r) {
		__propagate(__i, __l, __r);
		if (__r <= l || r <= __l) {
			return { FILLER, 0 };
		}
		if (l <= __l && __r <= r) {
			return tree[__i].data;
		}
		int __m = (__l + __r) / 2;
		Data V1 = __get(l, r, __i * 2 + 1, __l, __m);
		Data V2 = __get(l, r, __i * 2 + 2, __m, __r);
		return func(V1, V2);
	}

	RangeSegmentTree(int N) {
		size = N;
		tree.resize(4 * N, FILLER_NODE);
		__init(0, 0, size);
	}

	void add(const TreeType& value, int l, int r) {
		__update(value, l, r + 1, 0, 0, 0, size);
	}

	Data sum(int l, int r) {
		return __get(l, r + 1, 0, 0, size);
	}

};