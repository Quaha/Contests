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

struct Aho_Corasick_Lazy {

	int N; // count_of_strings
	int M; // count_of_nodes

	vector<int> par;
	vector<char> pchar;

	vector<int> suflink;
	vector<map<char, int>> go;

	vector<vector<int>> terms;

	vector<int> bfs_order;

	Aho_Corasick_Lazy(const StringBor& bor) {

		N = bor.N;
		M = bor.M;

		par.resize(M);
		pchar.resize(M);

		suflink.resize(M, -1);
		go.resize(M);
		for (int curr_V = 0; curr_V < M; curr_V++) {
			for (const auto& [next_C, next_V] : bor.go[curr_V]) {
				go[curr_V][next_C] = next_V;
				par[next_V] = curr_V;
				pchar[next_V] = next_C;
			}
		}

		terms.resize(M);
		for (int curr_V = 0; curr_V < M; curr_V++) {
			terms[curr_V] = bor.terms[curr_V];
		}

		bfs_order.resize(M);
		int p = 0;

		queue<int> q;
		q.push(0);

		while (!q.empty()) {
			int curr_V = q.front();
			q.pop();

			bfs_order[p++] = curr_V;

			for (auto [next_C, next_V] : go[curr_V]) {
				q.push(next_V);
			}
		}
	}

	int get_suflink(int curr_V) {
		if (suflink[curr_V] == -1) {
			if (curr_V == 0 || par[curr_V] == 0) {
				suflink[curr_V] = 0;
			}
			else {
				suflink[curr_V] = get_go(get_suflink(par[curr_V]), pchar[curr_V]);
			}
		}
		return suflink[curr_V];
	}

	int get_go(int curr_V, char C) {
		if (go[curr_V].count(C) == 0) {
			if (curr_V == 0) {
				go[curr_V][C] = 0;
			}
			else {
				go[curr_V][C] = get_go(get_suflink(curr_V), C);
			}
		}
		return go[curr_V][C];
	}

	vector<int> get_states_status(const string& S) {
		vector<int> status(M, 0);
		int curr_state = 0;
		for (char C : S) {
			curr_state = get_go(curr_state, C);
			status[curr_state]++;
		}
		return status;
	}

	vector<int> get_entry_status(const string& S) { // Count of entries by all string
		vector<int> status = get_states_status(S);

		vector<int> ans(N, 0);

		for (int i = bfs_order.size() - 1; i >= 0; i--) {
			int curr_V = bfs_order[i];
			for (int id : terms[curr_V]) {
				ans[id] = status[curr_V];
			}
			status[get_suflink(curr_V)] += status[curr_V];
		}
		return ans;
	}
};