#include <bits/stdc++.h>

using namespace std;

template<typename HashType> struct AmountHash {
	/*
	This class allows you to get a hash of a multiset
	of elements from an array segment from l to r
	*/

	inline static vector<int> MODS = { (int)1e9 + 7, (int)1e9 + 9 };

	int rand() {
		//return mt_rand();
	}

	inline static vector<unordered_map<HashType, int>> mapping;

	vector<vector<int>> hash;

	AmountHash(const vector<HashType>& arr) {

		if (mapping.empty()) {
			mapping.resize(MODS.size());
		}

		for (int i = 0; i < MODS.size(); i++) {
			for (const HashType& V : arr) {
				if (!mapping[i].count(V)) {
					mapping[i][V] = rand() % MODS[i];
				}
			}
		}
		hash.resize(MODS.size());
		for (int i = 0; i < (int)MODS.size(); i++) {
			hash[i].resize(arr.size() + 1, 0);
			for (int j = (int)arr.size() - 1; j >= 0; j--) {
				hash[i][j] = (hash[i][j + 1] + mapping[i][arr[j]]) % MODS[i];
			}
		}
	}

	vector<int> getHash(int l, int r) const { // [l, r], 0-ind
		vector<int> ans(MODS.size());
		for (int i = 0; i < MODS.size(); i++) {
			ans[i] = (hash[i][l] - hash[i][r + 1] + MODS[i]) % MODS[i];
		}
		return ans;
	}
};