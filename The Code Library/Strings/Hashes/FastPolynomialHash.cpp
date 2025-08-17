#include <bits/stdc++.h>

using namespace std;

struct FastPolynomialHash {

	const static inline long long MODS[2] = { 999999937, 999999929 }; // should be < 1e9 !
	const static inline long long p = 239;
	static inline vector<vector<long long>> ps;

	static void init(int SZ) { // !!!!!!!!!!!!!!!!

		ps.resize(2);

		ps[0].resize(SZ + 1);
		ps[0][0] = 1;
		for (int i = 1; i <= SZ; i++) {
			ps[0][i] = ps[0][i - 1] * p;
			if (ps[0][i] >= MODS[0]) {
				ps[0][i] %= MODS[0];
			}
		}

		ps[1].resize(SZ + 1);
		ps[1][0] = 1;
		for (int i = 1; i <= SZ; i++) {
			ps[1][i] = ps[1][i - 1] * p;
			if (ps[1][i] >= MODS[1]) {
				ps[1][i] %= MODS[1];
			}
		}
	}

	static int getAllHash(const string& S) {
		long long part1 = 0;
		for (int i = (int)S.size() - 1; i >= 0; i--) {
			part1 = S[i] + part1 * p;
			if (part1 >= MODS[0]) {
				part1 %= MODS[0];
			}
		}

		long long part2 = 0;
		for (int i = (int)S.size() - 1; i >= 0; i--) {
			part2 = S[i] + part2 * p;
			if (part2 >= MODS[1]) {
				part2 %= MODS[1];
			}
		}

		return part1 * (long long)1000000000 + part2;
	}

	vector<vector<long long>> hash;


	FastPolynomialHash(const string& S) {
		hash.resize(2);
		for (int i = 0; i < 2; i++) {
			hash[i].resize(S.size() + 1, 0);
			for (int j = (int)S.size() - 1; j >= 0; j--) {
				hash[i][j] = (S[j] + hash[i][j + 1] * p) % MODS[i];
			}
		}
	}

	long long getHash(int l, int r) const { // [l, r], 0-ind
		long long ans;

		ans = (hash[0][l] - (hash[0][r + 1] * ps[0][r - l + 1]) % MODS[0] + MODS[0]) % MODS[0];
		ans *= (long long)1000000000;
		ans += (hash[1][l] - (hash[1][r + 1] * ps[1][r - l + 1]) % MODS[1] + MODS[1]) % MODS[1];

		return ans;
	}
};