#include <bits/stdc++.h>

using namespace std;

template<typename TreeType> struct PowerfullFenwickTree {

	// 1-indexing!

	int N;
	vector<TreeType> tree;

	const int log2 = 23;

	PowerfullFenwickTree(int size) {
		N = size;
		tree.resize(N + 1, 0);
	}

	PowerfullFenwickTree(const vector<TreeType>& arr) { // arr in 0-indexing!
		N = arr.size();
		tree.resize(N + 1, 0);
		for (int i = 0; i < N; i++) {
			add(arr[i], i + 1);
		}
	}

	// k & -k   is the first 1 in the binary of k
	void add(TreeType V, int x) {
		while (x <= N) {
			tree[x] += V;
			x += (x & -x);
		}
	}

	TreeType sum(int x) {
		TreeType res = 0;
		while (x > 0) {
			res += tree[x];
			x -= (x & -x);
		}
		return res;
	}

	TreeType sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	int lower_bound(TreeType sum) { // return the first index such as prefs[index] >= sum
		int pos = 0;
		for (int k = log2; k >= 0; --k) {
			int next_pos = pos | (1ll << k);
			if (next_pos <= N && tree[next_pos] < sum) {
				sum -= tree[next_pos];
				pos = next_pos;
			}
		}
		return pos + 1;
	}

	int upper_bound(TreeType sum) { // return the last index such as prefs[index] >= sum
		int pos = 0;
		for (int k = log2; k >= 0; --k) {
			int next_pos = pos | (1ll << k);
			if (next_pos <= N && tree[next_pos] <= sum) {
				sum -= tree[next_pos];
				pos = next_pos;
			}
		}
		return pos + 1;
	}
};