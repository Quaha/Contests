#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

using vvii = vector<vector<pair<int, int>>>;

const int INF = 2e9;

void FloydWarshall(vvi& dists, vvi& paths, const vvii& g) {
    
    /*
     * Floyd-Warshall algorithm
     *
     * Finds all the shortest distances between all pairs of
     * vertices (or INF if there is no path) and paths (previous
	 * vertices on path from u to v or -1 if there is no path to)
     * 
     * g - adjacency lists - g[Ui] = {{Vij, Wij}, ...}
     *
	 * | Multiple Edges |   Loops   |  D/UD |  u   |  w  |
	 * +----------------+-----------+-------+------+-----+
	 * |      V         |     V     | V / V | >= 0 | any |
     *
     * DON'T WORK WITH NEGATIVE CYCLES, BUT DETECT THEM! (dists[u][u] < 0)
     * 
     * Time Complexity:   O(N^3)
     * Memory Complexity: O(N^2)
    */
 
    int N = g.size();

    dists.assign(N, vi(N, INF));
    paths.assign(N, vi(N, -1));

    for (int u = 0; u < N; u++) {
        dists[u][u] = 0;
    }

    for (int u = 0; u < N; u++) {
        for (auto [v, w]: g[u]) {
            if (dists[u][v] > w) {
                dists[u][v] = w;
                paths[u][v] = u;
            }
        }
    }

    for (int q = 0; q < N; q++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (dists[u][q] + dists[q][v] < dists[u][v]) {
                    dists[u][v] = max(dists[u][q] + dists[q][v], -INF);
                    paths[u][v] = paths[q][v];
                }
            }
        }
    }
}
