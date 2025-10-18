#include <bits/stdc++.h>

using namespace std;

template<typename TreeType> struct SegmentTree {

	TreeType func(const TreeType& V1, const TreeType& V2) const {
		return min(V1, V2);
	}

	const TreeType FILLER = 2e9;

	int N;
	vector<TreeType> tree;

	void init(int sz) {
		N = sz;
		tree.resize(4 * N, FILLER);
	}

	void build(const vector<TreeType>& arr) {
		build(arr, 0, N, 0);
	}

	void build(const vector<TreeType>& arr, int lx, int rx, int x) {
		if (rx - lx == 1) {
			if (lx < arr.size()) {
				tree[x] = arr[lx];
			}
			return;
		}
		int mx = (lx + rx) / 2;
		build(arr, lx, mx, x * 2 + 1);
		build(arr, mx, rx, x * 2 + 2);
		tree[x] = func(tree[x * 2 + 1], tree[x * 2 + 2]);
	}

	void add(const TreeType& V, int i) {
		add(V, i, 0, N, 0);
	}

	void add(const TreeType& V, int i, int lx, int rx, int x) {
		if (rx - lx == 1) {
			tree[x] += V;
			return;
		}
		int mx = (lx + rx) / 2;
		if (i < mx) {
			add(V, i, lx, mx, x * 2 + 1);
		}
		else {
			add(V, i, mx, rx, x * 2 + 2);
		}
		tree[x] = func(tree[x * 2 + 1], tree[x * 2 + 2]);
	}

	void set(const TreeType& V, int i) {
		set(V, i, 0, N, 0);
	}

	void set(const TreeType& V, int i, int lx, int rx, int x) {
		if (rx - lx == 1) {
			tree[x] = V;
			return;
		}
		int mx = (lx + rx) / 2;
		if (i < mx) {
			set(V, i, lx, mx, x * 2 + 1);
		}
		else {
			set(V, i, mx, rx, x * 2 + 2);
		}
		tree[x] = func(tree[x * 2 + 1], tree[x * 2 + 2]);
	}

	TreeType get(int l, int r) const {
		return get(l, r, 0, N, 0);
	}

	TreeType get(int l, int r, int lx, int rx, int x) const {
		if (l <= lx && rx <= r) {
			return tree[x];
		}
		if (r <= lx || rx <= l) {
			return FILLER;
		}
		int mx = (lx + rx) / 2;
		return func(get(l, r, lx, mx, x * 2 + 1), get(l, r, mx, rx, x * 2 + 2));
	}

	// returns lowest p >= l: arr[p] <= V or -1 if there no such position
	int lower_bound(const TreeType& V, int l) const {
		return lower_bound(V, l, 0, N, 0);
	}

	int lower_bound(const TreeType& V, int l, int lx, int rx, int x) const {
		if (tree[x] > V || rx <= l) return -1;
		if (rx - lx == 1) {
			return lx;
		}
		int mx = (lx + rx) / 2;
		int p = lower_bound(V, l, lx, mx, x * 2 + 1);
		if (p == -1) {
			p = lower_bound(V, l, mx, rx, x * 2 + 2);
		}
		return p;
	}
};