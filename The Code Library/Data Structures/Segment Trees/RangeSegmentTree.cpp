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

	void propagate(int x, int lx, int rx) {
		if (tree[x].operation.type == 0) {
			tree[x].data.value += tree[x].operation.value;
		}

		if (rx - lx > 1) {
			if (tree[x].operation.type == 0) {
				tree[x * 2 + 1].operation.value += tree[x].operation.value;
				tree[x * 2 + 2].operation.value += tree[x].operation.value;
			}
		}

		tree[x].operation.type = 0;
		tree[x].operation.value = 0;
	}

	void init(int x, int lx, int rx) {
		tree[x].data.id = lx;
		if (rx - lx > 1) {
			int __m = (lx + rx) / 2;
			init(x * 2 + 1, lx, __m);
			init(x * 2 + 2, __m, rx);
		}
	}

	void update(const TreeType& value, int l, int r, int type, int x, int lx, int rx) {
		propagate(x, lx, rx);
		if (rx <= l || r <= lx) {
			return;
		}
		if (l <= lx && rx <= r) {
			tree[x].operation.value = value;
			tree[x].operation.type = type;
			propagate(x, lx, rx);
			return;
		}
		int __m = (lx + rx) / 2;
		update(value, l, r, type, x * 2 + 1, lx, __m);
		update(value, l, r, type, x * 2 + 2, __m, rx);
		tree[x].data = func(tree[x * 2 + 1].data, tree[x * 2 + 2].data);
	}

	Data get(int l, int r, int x, int lx, int rx) {
		propagate(x, lx, rx);
		if (rx <= l || r <= lx) {
			return { FILLER, 0 };
		}
		if (l <= lx && rx <= r) {
			return tree[x].data;
		}
		int __m = (lx + rx) / 2;
		Data V1 = get(l, r, x * 2 + 1, lx, __m);
		Data V2 = get(l, r, x * 2 + 2, __m, rx);
		return func(V1, V2);
	}

	RangeSegmentTree(int N) {
		size = N;
		tree.resize(4 * N, FILLER_NODE);
		init(0, 0, size);
	}

	void add(const TreeType& value, int l, int r) {
		update(value, l, r + 1, 0, 0, 0, size);
	}

	Data sum(int l, int r) {
		return get(l, r + 1, 0, 0, size);
	}
};