#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#define int ll

struct XORBasis {

	static constexpr int M = 64;
	vector<ull> b = vector<ull>(M);
	vector<int> ids = vector<int>(M);
	vector<ull> masks = vector<ull>(M);

	bool add(ull x, int id = 0) {
		ull mask = 0;
		for (int i = M - 1; i >= 0; i--) {
			if (x & (1ull << i)) {
				if (b[i] == 0) {
					b[i] = x;
					masks[i] = mask ^ (1ull << i);
					ids[i] = id;
					return true;
				}
				x ^= b[i];
				mask ^= masks[i];
			}
		}
		return false;
	}

	ull reduce(ull x) {
		for (int i = M - 1; i >= 0; i--) {
			if (x & (1ull << i)) {
				x ^= b[i];
			}
		}
		return x;		
	}

	bool check(ull x) {
		return reduce(x) == 0ull;
	}

	vector<int> getPresentation(ull x) {
		ull mask = 0;
		for (int i = M - 1; i >= 0; i--) {
			if (x & (1ull << i)) {
				x ^= b[i];
				mask ^= masks[i];
			}
		}
		vector<int> result(0);
		for (int i = 0; i < M; i++) {
			if (mask & (1ull << i)) {
				result.push_back(ids[i]);
			}
		}
		return result;
	}
};