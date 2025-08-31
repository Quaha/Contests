#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kmpAut(const string& S, char start_letter, char end_letter) {
	int N = S.size();

	vector<int> pf(N, 0); // prefix function
	for (int i = 1; i < N; i++) {
		int j = pf[i - 1];
		while (j > 0 && S[i] != S[j]) {
			j = pf[j - 1];
		}
		if (S[i] == S[j]) {
			j++;
		}
		pf[i] = j;
	}

	int alphabet_sz = end_letter - start_letter + 1;

	vector<vector<int>> aut(N + 1, vector<int>(alphabet_sz, -1)); // aut[match length][new char] = new match length

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < alphabet_sz; j++) {

			int C = start_letter + j;

			if (i < N && S[i] == C) {
				aut[i][j] = i + 1;
			}
			else if (i == 0) {
				aut[i][j] = 0;
			}
			else {
				aut[i][j] = aut[pf[i - 1]][j];
			}
		}
	}
	return aut;
}