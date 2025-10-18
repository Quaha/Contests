#include <bits/stdc++.h>

using namespace std;

template<typename TreeType> struct MergeSortTree {

	/* This structure allows you to quickly calculate some
	function from elements from an array segment from l to r
	if it works quickly on a sorted segment from l to r. */

	int func(const vector<TreeType>& arr, const TreeType& V) {
		int l = 0;
		int r = arr.size() - 1;
		if (V < arr[0]) {
			return arr.size();
		}
		if (arr.back() <= V) {
			return 0;
		}
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (arr[m] <= V) {
				l = m;
			}
			else {
				r = m;
			}
		}
		return arr.size() - r;
	}

	int size = 0;
	vector<vector<TreeType>> tree;

	MergeSortTree(vector<TreeType> arr) {
		size = arr.size();
		tree.resize(4 * size);
		build(arr, 0);
	}

	void build(vector<TreeType>& arr) {
		build(arr, 0);
	}

	void build(vector<TreeType>& arr, int x) {
		if (arr.size() == 1) {
			tree[x] = arr;
			return;
		}
		int m = arr.size() / 2;

		std::vector<TreeType> lefts(m);
		for (int i = 0; i < m; i++) {
			lefts[i] = arr[i];
		}

		build(lefts, x * 2 + 1);

		std::vector<TreeType> right(arr.size() - m);
		for (int i = m; i < arr.size(); i++) {
			right[i - m] = arr[i];
		}

		build(right, x * 2 + 2);

		for (int i = 0, l = 0, r = 0; i < arr.size(); i++) {
			if (l < lefts.size() && r < right.size()) {
				if (lefts[l] < right[r]) {
					arr[i] = lefts[l++];
				}
				else {
					arr[i] = right[r++];
				}
			}
			else if (l < lefts.size()) {
				arr[i] = lefts[l++];
			}
			else if (r < right.size()) {
				arr[i] = right[r++];
			}
		}

		tree[x] = arr;
	}

	int get(const TreeType& V, int l, int r, int lx, int rx, int x) { // [l, r), 0-ind
		if (l <= lx && rx <= r) {
			return func(tree[x], V);
		}
		if (rx <= l || r <= lx) {
			return 0;
		}
		int mx = (lx + rx) / 2;
		return get(V, l, r, lx, mx, x * 2 + 1) + get(V, l, r, mx, rx, x * 2 + 2);
	}

	int get(const TreeType& V, int l, int r) { // [l, r], 0-ind
		return get(V, l, r + 1, 0, size, 0);
	}
};