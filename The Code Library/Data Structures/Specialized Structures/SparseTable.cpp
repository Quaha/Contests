#include <bits/stdc++.h>

using namespace std;

template<typename TableType> struct SparseTable {

	TableType func(TableType A, TableType B) {
		return min(A, B);
	}

	vector<int> degrees;
	vector<int> pows = { 1 };
	vector<vector<TableType>> table;

	int N, M; // N - array size, M - log2(N)

	SparseTable(const vector<TableType>& arr) {
		N = arr.size();
		degrees.resize(N + 1, 0);

		int p = 0;
		int V = 1;
		for (int i = 0; i <= N; i++) {
			if (V * 2 <= i) {
				V *= 2;
				pows.push_back(V);
				p++;
			}
			degrees[i] = p;
		}

		M = degrees.back() + 1;

		table.resize(M, vector<TableType>(N));

		for (int i = 0; i < N; i++) {
			table[0][i] = arr[i];
		}

		for (int j = 1, deg = 0; j < M; j++, deg++) {
			for (int i = 0; i + 2 * pows[deg] - 1 < N; i++) {
				table[j][i] = func(table[j - 1][i], table[j - 1][i + pows[deg]]);
			}
		}
	}

	TableType get(int l, int r) { // [l, r], 0-ind
		int deg = degrees[r - l + 1];
		return func(table[deg][l], table[deg][r - pows[deg] + 1]);
	}
};