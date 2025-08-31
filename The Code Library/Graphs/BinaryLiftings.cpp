#include <bits/stdc++.h>

using namespace std;

struct BinaryLifting {

	/*
	This structure allows you to find the smallest common ancestor (LCA)
	of two vertices in an oriented tree in log(N). Also allows you to find any
	commutative function on the path in the tree.
	*/

	int N = 0; // Number of vertices in the graph
	int deg = 0;
	int root = 0;
	vector<int> dist; // Dists from root to others
	vector<vector<int>> jmp; // jmp[vertex][number] = the 2^number ancerstor of the vertex

	BinaryLifting(const vector<vector<int>>& g, int root = 0) {
		N = g.size();
		this->root = root;
		dist.resize(N, 0);
		__getDist(root, 0, g);

		deg = 3 + log2(N);
		jmp.resize(N, vector<int>(deg, -1));


		// jumps at 1
		for (int i = 0; i < N; i++) {
			for (int j : g[i]) {
				jmp[j][0] = i;
			}
		}
		jmp[root][0] = root;

		// other jumps
		for (int k = 1; k < deg; k++) {
			for (int i = 0; i < N; i++) {
				jmp[i][k] = jmp[jmp[i][k - 1]][k - 1];
			}
		}
	}

	void __getDist(int curr_V, int curr_dist, const vector<vector<int>>& g) {
		dist[curr_V] = curr_dist;
		for (int next_V : g[curr_V]) {
			__getDist(next_V, curr_dist + 1, g);
		}
	}

	int getLCA(int u, int v) {
		if (dist[u] < dist[v]) {
			swap(u, v);
		}
		int d = dist[u] - dist[v];
		for (int i = deg - 1; i >= 0; i--) {
			if (d >= (1 << i)) {
				d -= (1 << i);
				u = jmp[u][i];
			}
		}

		if (u == v) {
			return u;
		}

		for (int i = deg - 1; i >= 0; i--) {
			if (jmp[u][i] != jmp[v][i]) {
				u = jmp[u][i];
				v = jmp[v][i];
			}
		}
		return jmp[u][0];
	}
};