#include <bits/stdc++.h>

using namespace std;

vector<int> pFunction(const string& S) {
	int N = S.size();
	vector<int> pf(N, 0);
	for (int i = 1; i < N; i++) {
		int j = pf[i - 1];
		while (j > 0 && S[i] != S[j]) {
			j = pf[j - 1];
		}
		if (S[i] == S[j]) ++j;
		pf[i] = j;
	}
	return pf;
}