#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

struct TopologicalSort {

    /*
     * Topological-Sort algorithm
     *
     * Finds the topological sorting of the graph (or doesn't
	 * fill the order array if there is a cycle in the graph)
     * 
     * g - adjacency lists - g[Ui] = {Vij, ...}
	 * 
	 * | Multiple Edges |   Loops   |  D/UD |  u   |
	 * +----------------+-----------+-------+------+
	 * |      V         | V (cycle) | V / X | >= 0 |
     * 
     * Time Complexity:   O(N + M)
     * Memory Complexity: O(N)
    */

	static void topologicalSort(vi& order, const vvi& g) {
		order.clear();

		int N = g.size();
		vi colors(N, 0);

		bool any_cycle = false;

		for (int start_V = 0; start_V < N; start_V++) {
			if (colors[start_V] == 0) {
				dfs(start_V, colors, order, any_cycle, g);
			}
		}

		reverse(order.begin(), order.end());

		if (any_cycle) {
			order.clear();
		}
	}

	static void dfs(int curr_V, vi& colors, vi& order, bool &any_cycle, const vvi& g) {
		colors[curr_V] = 1;

		for (int next_V: g[curr_V]) {
			if (colors[next_V] == 1) {
				any_cycle = true;
			}
			if (colors[next_V] == 0) {
				dfs(next_V, colors, order, any_cycle, g);
			}
		}

		order.push_back(curr_V);
		colors[curr_V] = 2;
	}
};
