#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;

const int INF = 2e9;

void Dijkstra(int start_V, vi& dist, vi& path, const vvii& g) {
    
    /*
     * Dijkstra's algorithm
     *
     * Finds all the shortest distances from the starting
     * vertex to the others (or INF if there is no path) and
     * paths (previous vertices or -1 if there is no path to)
     * 
     * g - adjacency lists - g[Ui] = {{Vij, Wij}, ...}, 
     * Wij >= 0, Ui >= 0
     * 
     * Time Complexity:   O(N + MlogM)
     * Memory Complexity: O(N + M)
    */

    int N = g.size();
    dist.assign(N, INF);
    path.assign(N, -1);

    dist[start_V] = 0;

    priority_queue<ii, vii, greater<ii>> q; q.push({0, start_V});

    while (!q.empty()) {
        auto [d, curr_V] = q.top(); q.pop();

        if (d > dist[curr_V]) {
            continue;
        }

        for (auto [next_V, w]: g[curr_V]) {
            if (dist[next_V] > dist[curr_V] + w) {
                dist[next_V] = dist[curr_V] + w;
                q.push({dist[curr_V] + w, next_V});

                path[next_V] = curr_V;
            }
        }
    }
}

void naiveDijkstra(int start_V, vi& dist, vi& path, const vvii& g) {
    
    /*
     * Naive Dijkstra's algorithm
     *
     * Finds all the shortest distances from the starting
     * vertex to the others (or INF if there is no path) and
     * paths (previous vertices or -1 if there is no path to)
     * 
     * g - adjacency lists - g[Ui] = {{Vij, Wij}, ...},
     * Wij >= 0, Ui >= 0
     * 
     * Time Complexity:   O(N^2)
     * Memory Complexity: O(N)
    */

    int N = g.size();
    dist.assign(N, INF);
    path.assign(N, -1);

    dist[start_V] = 0;

    vb marked(N, false);

    for (int i = 0; i < N - 1; i++) {
        int curr_V = -1;
        
        for (int u = 0; u < N; u++) {
            if (!marked[u] && (curr_V == -1 || dist[curr_V] > dist[u])) {
                curr_V = u;
            }
        }

        if (dist[curr_V] == INF) {
            break;
        }

        marked[curr_V] = true;
        for (auto [next_V, w]: g[curr_V]) {
            if (dist[next_V] > dist[curr_V] + w) {
                dist[next_V] = dist[curr_V] + w;
                path[next_V] = curr_V;
            }
        }
    }
}