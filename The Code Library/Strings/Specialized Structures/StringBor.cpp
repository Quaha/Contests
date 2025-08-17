#include <bits/stdc++.h>

using namespace std;

struct StringBor {

	int N = 0; // count_of_strings
	int M = 1; // count_of_nodes

	vector<map<char, int>> go;
	vector<vector<int>> terms;

	int getNextNode() {
		if (M == go.size()) {
			go.push_back(map<char, int>());
			terms.push_back({});
		}
		return M++;
	}

	void add_string(const string& S, int i) {
		int curr_state = 0;
		for (char C : S) {
			if (go[curr_state].count(C) == 0) {
				go[curr_state][C] = getNextNode();
			}
			curr_state = go[curr_state][C];
		}
		terms[curr_state].push_back(i);
	}

	StringBor(const vector<string>& strings) {
		N = strings.size();
		int start_nodes_size = 0;
		for (int i = 0; i < N; i++) {
			start_nodes_size += strings[i].size();
		}
		go.resize(start_nodes_size);
		terms.resize(start_nodes_size);
		for (int i = 0; i < N; i++) {
			add_string(strings[i], i);
		}
	}
};