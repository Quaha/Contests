#include <bits/stdc++.h>

using namespace std;

struct DSU {

	int cnt;
	vector<int> parent;
	vector<int> sizes;

	DSU(int N) {
		cnt = N;
		parent.resize(N, 0);
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
		sizes.resize(N, 1);
	}

	int getParent(int x) {
		if (x == parent[x]) return x;
		return parent[x] = getParent(parent[x]);
	}

	void merge(int x, int y) {
		x = getParent(x);
		y = getParent(y);
		if (x == y) return;
		if (sizes[x] < sizes[y]) {
			swap(x, y);
		}
		sizes[x] += sizes[y];
		parent[y] = x;
		cnt--;
	}

	bool inAdjacent(int x, int y) {
		return getParent(x) == getParent(y);
	}

	int getComponentsCnt() {
		return cnt;
	}

	int getComponentSize(int x) {
		return sizes[getParent(x)];
	}

};