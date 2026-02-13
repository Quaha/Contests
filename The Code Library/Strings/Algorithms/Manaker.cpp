#include <bits/stdc++.h>

using namespace std;

void ManakerOdd(vector<int>& m, const string& s) {

    // O(n)

    // a b a c a b a
    // 1 2 1 4 1 2 1

    int n = s.size();

    m.clear();
    m.resize(n, 1);
    for (int l = 0, r = 1, i = 1; i < n; i++) {
        if (i < r) {
            int len = i - l;
            m[i] = min(m[l - len], r - i);
        }
        while (i - m[i] >= 0 && i + m[i] < n && s[i - m[i]] == s[i + m[i]]) {
            m[i]++;
        }
        if (r < i + m[i]) {
            l = i;
            r = i + m[i];
        }
    }
}

void ManakerEven(vector<int>& m, const string& s) {

    // O(n)

    // a b b a c a a
    // 0 0 2 0 0 0 1

    int n = s.size();

    m.clear();
    m.resize(n, 0);

    for (int l = 0, r = 1, i = 1; i < n; i++) {
        if (i < r) {
            int len = i - l;
            m[i] = min(m[l - len], r - i);
        }
        while (i - m[i] - 1 >= 0 && i + m[i] < n && s[i - 1 - m[i]] == s[i + m[i]]) {
            m[i]++;
        }
        if (r < i + m[i]) {
            l = i;
            r = i + m[i];
        }
    }
}