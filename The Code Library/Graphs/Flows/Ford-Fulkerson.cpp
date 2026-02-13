#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;

#define all(x) x.begin(), x.end()

const int INF = 2e9;

struct FordFulkerson {

	int n;
	int s, t;
	int maxF = -1;

	vector<unordered_map<int, int>> c, f;

	int tmr = 1;
	vi was;

	FordFulkerson(int n, int s, int t) {
		// O(maxF * m)

		this->n = n;
		this->s = s;
		this->t = t;

		c.resize(n);
		f.resize(n);
		was.resize(n, 0);
	}

	FordFulkerson(int n, int s, int t, int maxF) {
		// O(log(maxF) * m * m) or O(maxF * log(maxF) * m)

		this->n = n;
		this->s = s;
		this->t = t;
		this->maxF = maxF;

		c.resize(n);
		f.resize(n);
		was.resize(n, 0);
	}

	void addDirectedEdges(int u, int v, int w) {
		c[u][v] += w;
		c[v][u];
	}

	int dfs(int curr_V, int min_delta, int lowest_cap = 0) {
		if (curr_V == t) {
			return min_delta;
		}
		if (was[curr_V] == tmr) {
			return 0;
		}
		was[curr_V] = tmr;
		for (auto [next_V, cap]: c[curr_V]) {
			if (cap - f[curr_V][next_V] > lowest_cap) {
				int delta = dfs(next_V, min(min_delta, cap - f[curr_V][next_V]), lowest_cap);
				if (delta > 0) {
					f[curr_V][next_V] += delta;
					f[next_V][curr_V] -= delta;
					return delta;
				}
			}
		}
		return 0;
	}

	int getMaxFlow() {
		int F = 0;
		int k = 1;
		while (k <= maxF) {
			k *= 2;
		}
		do {
			k /= 2;
			while (true) {
				tmr++;
				int delta = dfs(s, INF, k);
				if (delta > 0) {
					F += delta;
				}
				else {
					break;
				}
			}
		} while (k > 0);
		return F;
	}
};