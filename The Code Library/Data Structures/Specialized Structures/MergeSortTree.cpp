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

	void __mergeSort(vector<TreeType>& arr, int __i) {
		if (arr.size() == 1) {
			tree[__i] = arr;
			return;
		}
		int m = arr.size() / 2;

		std::vector<TreeType> lefts(m);
		for (int i = 0; i < m; i++) {
			lefts[i] = arr[i];
		}

		__mergeSort(lefts, __i * 2 + 1);

		std::vector<TreeType> right(arr.size() - m);
		for (int i = m; i < arr.size(); i++) {
			right[i - m] = arr[i];
		}

		__mergeSort(right, __i * 2 + 2);

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

		tree[__i] = arr;
	}

	int __get(const TreeType& V, int l, int r, int __l, int __r, int __i) { // [l, r), 0-ind
		if (l <= __l && __r <= r) {
			return func(tree[__i], V);
		}
		if (__r <= l || r <= __l) {
			return 0;
		}
		int __m = (__l + __r) / 2;
		int V1 = __get(V, l, r, __l, __m, __i * 2 + 1);
		int V2 = __get(V, l, r, __m, __r, __i * 2 + 2);
		return V1 + V2;
	}

	MergeSortTree(vector<TreeType> arr) {
		size = arr.size();
		tree.resize(4 * size);
		__mergeSort(arr, 0);
	}

	int sum(const TreeType& V, int l, int r) { // [l, r], 0-ind
		return __get(V, l, r + 1, 0, size, 0);
	}
};