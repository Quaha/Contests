#include <bits/stdc++.h>

using namespace std;

struct PolynomialHash {

	inline static vector<int> MODS = { (int)1e9 + 7, (int)1e9 + 9 };
	inline static const int p = 239;
	inline static vector<vector<int>> ps;

	static void init(int N) {
		ps.resize(MODS.size());
		for (int i = 0; i < MODS.size(); i++) {
			ps[i].resize(N);
			ps[i][0] = 1;
			for (int j = 1; j < N; j++) {
				ps[i][j] = (ps[i][j - 1] * p) % MODS[i];
			}
		}
	}

	vector<vector<int>> hash;

	PolynomialHash(const string& S) {
		hash.resize(MODS.size());
		for (int i = 0; i < MODS.size(); i++) {
			hash[i].resize(S.size() + 1, 0);
			for (int j = (int)S.size() - 1; j >= 0; j--) {
				hash[i][j] = (S[j] + hash[i][j + 1] * p) % MODS[i];
			}
		}
	}

	vector<int> getHash(int l, int r) const { // [l, r], 0-ind
		vector<int> ans(MODS.size());
		for (int i = 0; i < MODS.size(); i++) {
			ans[i] = (hash[i][l] - (hash[i][r + 1] * ps[i][r - l + 1]) % MODS[i] + MODS[i]) % MODS[i];
		}
		return ans;
	}
};