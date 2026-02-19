#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;

struct Kuhn {

	int n, m;

	vi used;
	int tmr = 1;

	vi match1; // left part
	vi match2; // right part

	vvi g;

	int MaxMatchSize = 0;

	Kuhn(int n, int m) {
		this->n = n;
		this->m = m;
		used.resize(n + 1, 0);
		match1.resize(n + 1, -1);
		match2.resize(m + 1, -1);
		g.resize(n + 1);
	}

	void addEdge(int u1, int u2) {
		g[u1].push_back(u2);
	}

	bool dfs(int curr_V) {
		if (used[curr_V] == tmr) {
			return false;
		}
		used[curr_V] = tmr;
		for (int next_V: g[curr_V]) {
			if (match2[next_V] == -1 || dfs(match2[next_V])) {
				match2[next_V] = curr_V;
				match1[curr_V] = next_V;
				return true;
			}
		}
		return false;
	}

	void computeMaxMatching() {
		for (int u = 0; u <= n; u++) {
			for (int v: g[u]) {
				if (match2[v] == -1) {
					match2[v] = u;
					match1[u] = v;
					MaxMatchSize++;
					break;
				}
			}
		}
		for (int u = 0; u <= n; u++) {
			if (match1[u] == -1) {
				if (dfs(u)) {
					tmr++;
					MaxMatchSize++;
				}
			}
		}
	}

	int getMaxMatchingSize() {
		return MaxMatchSize;
	}

	vii getEdgesInMaxMatching() {
		vii res;
		for (int i = 0; i <= n; i++) {
			if (match1[i] != -1) {
				res.push_back({i, match1[i]});
			}
		}
		return res;
	}
};