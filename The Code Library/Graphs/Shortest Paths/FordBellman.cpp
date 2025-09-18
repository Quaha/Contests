#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

using vvii = vector<vector<pair<int, int>>>;

const int INF = 2e9;

void FordBellman(int start_V, vi& dist, vi& path, const vvii& g) {
    
    /*
     * Ford-Bellman algorithm
     *
     * Finds all the shortest distances from the starting
     * vertex to the others (or INF if there is no path, or -INF
	 * there is no shortest path [negative cycle]) and paths
	 * (previous vertices or -1 if there is no path to)
     * 
     * g - adjacency lists - g[Ui] = {{Vij, Wij}, ...}, Wij - any, Ui >= 0
     * 
     * Time Complexity:   O(N*M)
     * Memory Complexity: O(N + M)
    */

    int N = g.size();
	int M = 0;

	for (int u = 0; u < N; u++) {
		M += g[u].size();
	}

	vvi edges(M, vi(3, 0));
	for (int u = 0, i = 0; u < N; u++) {
		for (auto [v, w]: g[u]) {
			edges[i][0] = u;
			edges[i][1] = v;
			edges[i][2] = w;
			++i;
		}
	}

	dist.assign(N, INF);
	path.assign(N, -1);

	dist[start_V] = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			int u = edges[j][0];
			int v = edges[j][1];
			int w = edges[j][2];

			if (dist[u] != INF && dist[v] > dist[u] + w) {
				dist[v] = max(dist[u] + w, -INF);
				path[v] = u;
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			int u = edges[j][0];
			int v = edges[j][1];
			int w = edges[j][2];

			if (dist[u] != INF && dist[v] > dist[u] + w) {
				dist[v] = -INF;
				path[v] = u;
			}
		}
	}	
}