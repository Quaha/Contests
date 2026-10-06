#ifndef FILEIO
#pragma GCC optimize("O3")
#endif

//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string_view>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <random>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <numeric>
#include <cassert>
#include <cstring>
#include <climits>
#include <ctime>

#ifdef _MSC_VER
#pragma comment(linker, "/STACK:1073741824") // 1024 MB, only MSVC
#endif

using namespace std;

// ============================== DEFINES ==============================

// PBDS ordered set
#if __has_include(<ext/pb_ds/assoc_container.hpp>)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define int ll

template<typename T1, typename T2, typename T3> struct triple {
	T1 first;
	T2 second;
	T3 third;
};

template<typename T> using v1 = vector<T>;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> using v3 = vector<vector<vector<T>>>;
template<typename T> using v4 = vector<vector<vector<vector<T>>>>;
template<typename T> using v5 = vector<vector<vector<vector<vector<T>>>>>;

using vi = vector<int>;
using vvi = v2<int>;
using vvvi = v3<int>;
using vvvvi = v4<int>;
using vvvvvi = v5<int>;

using vl = vector<long long>;
using vvl = v2<ll>;
using vvvl = v3<ll>;
using vvvvl = v4<ll>;
using vvvvvl = v5<ll>;

using vll = vector<long long>;
using vvll = v2<ll>;
using vvvll = v3<ll>;
using vvvvll = v4<ll>;
using vvvvvll = v5<ll>;

using ii = pair<int, int>;
using vii = v1<ii>;
using vvii = v2<ii>;
using vvvii = v3<ii>;
using vvvvii = v4<ii>;
using vvvvvii = v5<ii>;

using pll = pair<long long, long long>;
using vpll = v1<pll>;
using vvpll = v2<pll>;
using vvvpll = v3<pll>;
using vvvvpll = v4<pll>;
using vvvvvpll = v5<pll>;

using vb = vector<bool>;
using vvb = v2<bool>;
using vvvb = v3<bool>;
using vvvvb = v4<bool>;
using vvvvvb = v5<bool>;

using vc = vector<char>;
using vvc = v2<char>;
using vvvc = v3<char>;
using vvvvc = v4<char>;
using vvvvvc = v5<char>;

using vs = vector<string>;
using vvs = v2<string>;
using vvvs = v3<string>;
using vvvvs = v4<string>;
using vvvvvs = v5<string>;

using vld = vector<ld>;
using vvld = v2<ld>;
using vvvld = v3<ld>;
using vvvvld = v4<ld>;
using vvvvvld = v5<ld>;

#define y1 __y1_y1_y1__
#define fi first
#define se second
#define pb push_back
#define co continue
#define con continue
#define re return
#define ret return

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define fori(N) for (int i = 0; i < (N); ++i)
#define forj(N) for (int j = 0; j < (N); ++j)
#define fork(N) for (int k = 0; k < (N); ++k)
#define fori1(N) for (int i = 1; i < (N); ++i)
#define forj1(N) for (int j = 1; j < (N); ++j)
#define fork1(N) for (int k = 1; k < (N); ++k)

template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(declval<T&>().begin())>> : true_type {};
template<typename T> constexpr bool is_range_v = is_iterable<T>::value && !is_convertible_v<T, string_view>;

template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p);
template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& p);
template<typename C> auto operator>>(istream& in, C& c) -> enable_if_t<is_range_v<C>, istream&>;
template<typename C> auto operator<<(ostream& out, const C& c) -> enable_if_t<is_range_v<C>, ostream&>;

template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& p) {
	return in >> p.first >> p.second;
}

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
	return out << p.first << ' ' << p.second;
}

template<typename C> auto operator>>(istream& in, C& c) -> enable_if_t<is_range_v<C>, istream&> {
	for (auto& x : c) in >> x;
	return in;
}

template<typename C> auto operator<<(ostream& out, const C& c) -> enable_if_t<is_range_v<C>, ostream&> {
	bool first = true;
	for (const auto& x : c) {
		if (!first) out << (is_range_v<decay_t<decltype(x)>> ? '\n' : ' ');
		out << x;
		first = false;
	}
	return out;
}

// ============================== FUNCTIONS ==============================

template<typename T> void cin0(vector<T>& arr) { cin >> arr; }
template<typename T> void cin1(vector<T>& arr) { for (size_t i = 1; i < arr.size(); ++i) cin >> arr[i]; }

template<typename T> void cout0(const vector<T>& arr) { cout << arr << '\n'; }

template<typename T> void cout1(const vector<T>& arr) {  // skips index 0 (in every dimension)
	if constexpr (is_range_v<T>) {
		for (size_t i = 1; i < arr.size(); ++i) {
			cout1(arr[i]);
		}
	}
	else {
		for (size_t i = 1; i < arr.size(); ++i) {
			cout << arr[i] << (i + 1 < arr.size() ? " " : "");
		}
		cout << '\n';
	}
}

template<typename C> auto summed(const C& c) {
	return accumulate(c.begin(), c.end(), typename C::value_type{});
}

template<typename T, typename = void> struct is_ordered : false_type {};
template<typename T> struct is_ordered<T, void_t<typename T::key_compare>> : true_type {};

template<typename C, enable_if_t<is_iterable<C>::value, ll> = 0> auto max(const C& c) {
	if constexpr (is_range_v<typename C::value_type>) {
		auto result = max(*c.begin());
		for (const auto& x : c) result = max(result, max(x));
		return result;
	}
	else if constexpr (is_ordered<C>::value) {
		return *c.rbegin();
	}
	else {
		return *max_element(c.begin(), c.end());
	}
}

template<typename C, enable_if_t<is_iterable<C>::value, ll> = 0> auto min(const C& c) {
	if constexpr (is_range_v<typename C::value_type>) {
		auto result = min(*c.begin());
		for (const auto& x : c) {
			result = min(result, min(x));
		}
		return result;
	}
	else if constexpr (is_ordered<C>::value) {
		return *c.begin();
	}
	else {
		return *min_element(c.begin(), c.end());
	}
}

template<typename T1, typename T2> bool setmax(T1& V1, const T2& V2) { return V1 < V2 ? V1 = V2, true : false; }
template<typename T1, typename T2> bool setmin(T1& V1, const T2& V2) { return V2 < V1 ? V1 = V2, true : false; }
template<typename T1, typename T2> bool amax(T1& V1, const T2& V2) { return setmax(V1, V2); }
template<typename T1, typename T2> bool smax(T1& V1, const T2& V2) { return setmax(V1, V2); }
template<typename T1, typename T2> bool amin(T1& V1, const T2& V2) { return setmin(V1, V2); }
template<typename T1, typename T2> bool smin(T1& V1, const T2& V2) { return setmin(V1, V2); }

template<typename T> void sort(T& obj) { sort(all(obj)); }
template<typename T> void rsort(T& obj) { sort(rall(obj)); }
template<typename T> void usort(T& obj) { sort(all(obj)); obj.erase(unique(all(obj)), obj.end()); }
template<typename T> void reverse(T& obj) { reverse(all(obj)); }

template<typename T> T sorted(T obj) { sort(obj); return obj; }
template<typename T> T rsorted(T obj) { rsort(obj); return obj; }
template<typename T> T usorted(T obj) { usort(obj); return obj; }
template<typename T> T reversed(T obj) { reverse(obj); return obj; }

int sgn(int V) {
	return (V > 0) - (V < 0);
}

int fastPow(int V, int a, int MOD) {
	int res = 1;
	while (a != 0) {
		if (a & 1) {
			res *= V;
			res %= MOD;
		}
		V *= V;
		V %= MOD;
		a >>= 1;
	}
	return res;
}

int binPow(int V, int a, int MOD) { return fastPow(V, a, MOD); }

int getMex(const vector<int>& arr) {
	vector<bool> seen(arr.size() + 1);
	for (int x : arr) {
		if (0 <= x && x < arr.size()) seen[x] = true;
	}
	int result = 0;
	while (seen[result]) ++result;
	return result;
}

bool isPrime(int N) {
	if (N < 2) return false;
	for (int i = 2; i * i <= N; ++i) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

int getBit(int N, int i) {
	return (N >> i) & 1;
}

// ============================== CODE STARTS HERE ==============================

void solve();
void precalc();

mt19937 mt_rand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mt_rand64(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
#ifdef FILEIO
	freopen("workspace/input.txt", "r", stdin);
	freopen("workspace/output.txt", "w", stdout);
#endif

	srand(time(0));

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//cout << fixed << setprecision(2);
	//cout.precision(20);

	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	precalc();

	int tests = 1;
	cin >> tests;

	for (int test_case = 1; test_case <= tests; ++test_case) {
		solve();
	}

	return 0;
}

constexpr int INF = (int)2e15;
constexpr int MOD = (int)998244353;

void precalc() {}

void solve() {

	

}