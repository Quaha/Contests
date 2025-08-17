#include <bits/stdc++.h>

using namespace std;

template<typename TreeType> struct SparseRangeSegmentTree {

	const static inline TreeType FILLER = 0;

	struct Data {
		TreeType value = FILLER;
	};

	Data DATA_FILLER = { FILLER };

	struct Operation {
		int type = 0; // 0 - addition, 1 - setting
		TreeType value = 0;
	};

	struct Node {
		Data data;
		Operation operation;
		int left_id = -1;
		int right_id = -1;
	};

	int size = 0;
	vector<Node> tree;
	int free_node = 1;

	void __initNode(int __i) {
		tree[__i].left_id = free_node;
		tree[__i].right_id = free_node + 1;
		free_node += 2;
	}

	bool __isInit(int __i) {
		if (tree[__i].left_id == -1) {
			return false;
		}
		return true;
	}

	Data func(const Data& A, const Data& B) {
		Data ans;
		ans.value = A.value + B.value;
		return ans;
	}

	void __propagate(int __i, int __l, int __r) {
		if (tree[__i].operation.type == 0) {
			tree[__i].data.value += tree[__i].operation.value * (__r - __l);
		}
		if (tree[__i].operation.type == 1) {
			tree[__i].data.value = tree[__i].operation.value * (__r - __l);
		}

		if (__r - __l > 1) {
			if (tree[__i].operation.type == 0) {
				tree[tree[__i].left_id].operation.value += tree[__i].operation.value;
				tree[tree[__i].right_id].operation.value += tree[__i].operation.value;
			}
			if (tree[__i].operation.type == 1) {
				tree[tree[__i].left_id].operation.value = tree[__i].operation.value;
				tree[tree[__i].right_id].operation.value = tree[__i].operation.value;
				tree[tree[__i].left_id].operation.type = 1;
				tree[tree[__i].right_id].operation.type = 1;
			}
		}

		tree[__i].operation.value = 0;
		tree[__i].operation.type = 0;

	}

	void __update(const TreeType& value, int l, int r, int type, int __i, int __l, int __r) {
		if (__r - __l > 1 && !__isInit(__i)) {
			__initNode(__i);
		}
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
		__update(value, l, r, type, tree[__i].left_id, __l, __m);
		__update(value, l, r, type, tree[__i].right_id, __m, __r);
		tree[__i].data = func(tree[tree[__i].left_id].data, tree[tree[__i].right_id].data);
	}

	Data __get(int l, int r, int __i, int __l, int __r) {
		if (__r - __l > 1 && !__isInit(__i)) {
			__initNode(__i);
		}
		__propagate(__i, __l, __r);
		if (__r <= l || r <= __l) {
			return DATA_FILLER;
		}
		if (l <= __l && __r <= r) {
			return tree[__i].data;
		}
		int __m = (__l + __r) / 2;
		Data V1 = __get(l, r, tree[__i].left_id, __l, __m);
		Data V2 = __get(l, r, tree[__i].right_id, __m, __r);
		return func(V1, V2);
	}

	SparseRangeSegmentTree(int N) {
		size = N;
		tree.resize(10 * N);
	}

	void add(const TreeType& value, int l, int r) {
		__update(value, l, r + 1, 0, 0, 0, size);
	}

	void set(const TreeType& value, int l, int r) {
		__update(value, l, r + 1, 1, 0, 0, size);
	}

	Data sum(int l, int r) {
		return __get(l, r + 1, 0, 0, size);
	}

};