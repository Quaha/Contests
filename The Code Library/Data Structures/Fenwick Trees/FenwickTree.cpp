#include <bits/stdc++.h>

using namespace std;

template<typename TreeType> struct FenwickTree {

	// 0-indexing

	int N;
	vector<TreeType> tree;

	FenwickTree(int size) {
		N = size;
		tree.resize(N, 0);
	}

	FenwickTree(const vector<TreeType>& arr) {
		N = arr.size();
		tree.resize(N, 0);
		for (int i = 0; i < N; i++) {
			add(arr[i], i);
		}
	}

	void add(TreeType V, int x) { // data[x] += V
		while (x < N) {
			tree[x] += V;
			x = (x | (x + 1));
		}
	}

	TreeType sum(int x) const {
		TreeType res = 0;
		while (x >= 0) {
			res += tree[x];
			x = (x & (x + 1)) - 1;
		}
		return res;
	}

	TreeType sum(int l, int r) const {
		return sum(r) - sum(l - 1);
	}
};