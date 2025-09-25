#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;

const int INF = 2e9;

void Dijkstra(int start_V, vi& dists, vi& paths, const vvii& g) {
    
    /*
     * Dijkstra's algorithm
     *
     * Finds all the shortest distances from the starting
     * vertex to the others (or INF if there is no path) and
     * paths (previous vertices or -1 if there is no path to)
     * 
     * g - adjacency lists - g[Ui] = {{Vij, Wij}, ...} 
     *
     * | Multiple Edges |   Loops   |  D/UD |  u   |  w   |
	 * +----------------+-----------+-------+------+------+
	 * |      V         |     V     | V / V | >= 0 | >= 0 |
     * 
     * Time Complexity:   O(N + MlogM)
     * Memory Complexity: O(N + M)
    */

    int N = g.size();
    dists.assign(N, INF);
    paths.assign(N, -1);

    dists[start_V] = 0;

    priority_queue<ii, vii, greater<ii>> q; q.push({0, start_V});

    while (!q.empty()) {
        auto [d, curr_V] = q.top(); q.pop();

        if (d > dists[curr_V]) {
            continue;
        }

        for (auto [next_V, w]: g[curr_V]) {
            if (dists[next_V] > dists[curr_V] + w) {
                dists[next_V] = dists[curr_V] + w;
                q.push({dists[curr_V] + w, next_V});

                paths[next_V] = curr_V;
            }
        }
    }
}

void naiveDijkstra(int start_V, vi& dists, vi& paths, const vvii& g) {
    
    /*
     * Naive Dijkstra's algorithm
     *
     * Finds all the shortest distances from the starting
     * vertex to the others (or INF if there is no path) and
     * paths (previous vertices or -1 if there is no path to)
     * 
     * g - adjacency lists - g[Ui] = {{Vij, Wij}, ...}
     *
     * | Multiple Edges |   Loops   |  D/UD |  u   |  w   |
	 * +----------------+-----------+-------+------+------+
	 * |      V         |     V     | V / V | >= 0 | >= 0 |
     * 
     * Time Complexity:   O(N^2)
     * Memory Complexity: O(N)
    */

    int N = g.size();
    dists.assign(N, INF);
    paths.assign(N, -1);

    dists[start_V] = 0;

    vb marked(N, false);

    for (int i = 0; i < N - 1; i++) {
        int curr_V = -1;
        
        for (int u = 0; u < N; u++) {
            if (!marked[u] && (curr_V == -1 || dists[curr_V] > dists[u])) {
                curr_V = u;
            }
        }

        if (dists[curr_V] == INF) {
            break;
        }

        marked[curr_V] = true;
        for (auto [next_V, w]: g[curr_V]) {
            if (dists[next_V] > dists[curr_V] + w) {
                dists[next_V] = dists[curr_V] + w;
                paths[next_V] = curr_V;
            }
        }
    }
}