#include <bits/stdc++.h>

using namespace std;

vector<int> zFunction(const string& S) {
	int N = S.size();
	vector<int> zf(N, 0);
	for (int i = 1, l = 0, r = 1; i < N; ++i) {
		if (i < r) {
			zf[i] = std::min(r - i, zf[i - l]);
		}
		while (i + zf[i] < N && S[zf[i]] == S[i + zf[i]])
			++zf[i];
		if (i + zf[i] > r) {
			l = i;
			r = i + zf[i];
		}
	}
	return zf;
}