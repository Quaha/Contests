#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

struct DetectDirectedCycle {

    /*
     * Directed cycle detection algorithm (based on Ford-Bellman algorithm)
     *
     * Checks if there is at least one negative cycle in the
	 * graph and returns the sequence of vertices of the cycle,
	 * if there is one (cycle = {u1, u2, ..., un, u1} or empty)
     * 
     * g - adjacency lists - g[Ui] = {Vij, ...}
	 * 
	 * | Multiple Edges |   Loops   |  D/UD |  Ui  |
	 * +----------------+-----------+-------+------+
	 * |      V         | V (cycle) | V / X | >= 0 |
     * 
     * Time Complexity:   O(N + M)
     * Memory Complexity: O(N)
    */

	static void detectDirectedCycle(vi& cycle, const vvi& g) {
		cycle.clear();

		int N = g.size();
		vi colors(N, 0);
		vi path(N, -1);

		for (int start_V = 0; start_V < N; start_V++) {
			if (colors[start_V] == 0) {
				dfs(start_V, colors, cycle, path, g);
				if (!cycle.empty()) {
					break;
				}
			}
		}

		reverse(cycle.begin(), cycle.end());
	}

	static void dfs(int curr_V, vi& colors, vi& cycle, vi& path, const vvi& g) {
		colors[curr_V] = 1;

		for (int next_V: g[curr_V]) {
			if (colors[next_V] == 1) {
				
				cycle.push_back(next_V);

				int u = curr_V;

				while (u != next_V) {
					cycle.push_back(u);
					u = path[u];
				}
				cycle.push_back(u);

				break;
			}
			if (colors[next_V] == 0) {
				path[next_V] = curr_V;
				dfs(next_V, colors, cycle, path, g);
			}
			if (!cycle.empty()) {
				return;
			}
		}

		colors[curr_V] = 2;
	}
};