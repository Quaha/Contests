#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <bitset>
#include <random>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <numeric>
#include <cassert>
#include <cstring>
#include <list>
#include <climits>
#include <stack>

#define GCC

#ifdef GCC
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#endif

#pragma comment(linker, "/STACK:102400000000")

using namespace std;

#ifdef GCC
using namespace __gnu_pbds;
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define int ll

/*

██████  ███████ ███████ ██ ███    ██ ███████ ███████ 
██   ██ ██      ██      ██ ████   ██ ██      ██      
██   ██ █████   █████   ██ ██ ██  ██ █████   ███████ 
██   ██ ██      ██      ██ ██  ██ ██ ██           ██ 
██████  ███████ ██      ██ ██   ████ ███████ ███████ 

*/                                                                                                                                          

#ifdef GCC

template<typename set_type> using ordered_set = tree<
    set_type,
    null_type,
    std::less<set_type>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

#endif

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

using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;
using vvvii = vector<vector<vector<pair<int, int>>>>;

using pll = pair<long long, long long>;
using vll = vector<pair<long long, long long>>;
using vvll = vector<vector<pair<long long, long long>>>;
using vvvll = vector<vector<vector<pair<long long, long long>>>>;

using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vvvb = vector<vector<vector<bool>>>;
using vvvvb = vector<vector<vector<vector<bool>>>>;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vvvvi = vector<vector<vector<vector<int>>>>;

using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vvvl = vector<vector<vector<long long>>>;
using vvvvl = vector<vector<vector<vector<long long>>>>;

using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vvvl = vector<vector<vector<long long>>>;
using vvvvl = vector<vector<vector<vector<long long>>>>;

using vc = vector<char>;
using vvc = vector<vector<char>>;
using vvvc = vector<vector<vector<char>>>;
using vvvvc = vector<vector<vector<vector<char>>>>;

using vs = vector<string>;
using vvs = vector<vector<string>>;
using vvvs = vector<vector<vector<string>>>;

using vld = vector<ld>;
using vvld = vector<vector<ld>>;
using vvvld = vector<vector<vector<ld>>>;

#define y1 y1_

#define fi first
#define se second

#define co continue
#define con continue
#define pb push_back

#define re return
#define ret return

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()

#define fori(N) for (int i = 0; i < N; ++i)
#define forj(N) for (int j = 0; j < N; ++j)
#define fork(N) for (int k = 0; k < N; ++k)

#define fori1(N) for (int i = 1; i < N; ++i)
#define forj1(N) for (int j = 1; j < N; ++j)
#define fork1(N) for (int k = 1; k < N; ++k)

template<typename T> std::istream& operator>>(std::istream& in, vector<T>& arr) {
	for (T& object : arr) {
		in >> object;
	}
	return in;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const vector<T>& arr) {
	for (const T& object : arr) {
		out << object << ' ';
	}
	return out;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const vector<vector<T>>& arr) {
	for (const vector<T>& object : arr) {
		out << object << '\n';
	}
	return out;
}

template<typename T1, typename T2> std::istream& operator>>(std::istream& in, pair<T1, T2>& p) {
	in >> p.first >> p.second;
	return in;
}

template<typename T1, typename T2> std::ostream& operator<<(std::ostream& out, const pair<T1, T2>& p) {
	out << p.first << ' ' << p.second << '\n';
	return out;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const set<T>& S) {
	for (const T& V : S) {
		cout << V << ' ';
	}
	return out;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const unordered_set<T>& S) {
	for (const T& V : S) {
		cout << V << ' ';
	}
	return out;
}

template<typename T> std::ostream& operator<<(std::ostream& out, const multiset<T>& S) {
	for (const T& V : S) {
		cout << V << ' ';
	}
	return out;
}

/*

███████ ██    ██ ███    ██  ██████ ████████ ██  ██████  ███    ██ ███████ 
██      ██    ██ ████   ██ ██         ██    ██ ██    ██ ████   ██ ██      
█████   ██    ██ ██ ██  ██ ██         ██    ██ ██    ██ ██ ██  ██ ███████ 
██      ██    ██ ██  ██ ██ ██         ██    ██ ██    ██ ██  ██ ██      ██ 
██       ██████  ██   ████  ██████    ██    ██  ██████  ██   ████ ███████

*/

// cin/cout

template<typename T> void cin0(vector<T>& arr) {
	for (size_t i = 0; i < arr.size(); ++i) {
		cin >> arr[i];
	}
}

template<typename T> void cin1(vector<T>& arr) {
	for (size_t i = 1; i < arr.size(); ++i) {
		cin >> arr[i];
	}
}

template<typename T> void cout0(const vector<T>& arr) {
	for (size_t i = 0; i + 1 < arr.size(); ++i) {
		cout << arr[i] << ' ';
	}
	cout << arr.back() << '\n';
}

template<typename T> void cout0(const vector<vector<T>>& arr) {
	for (size_t i = 0; i < arr.size(); ++i) {
		for (size_t j = 0; j + 1 < arr[i].size(); ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << arr[i].back() << '\n';
	}
}

template<typename T> void cout1(const vector<T>& arr) {
	for (size_t i = 1; i + 1 < arr.size(); ++i) {
		cout << arr[i] << ' ';
	}
	cout << arr.back() << '\n';
}

template<typename T> void cout1(const vector<vector<T>>& arr) {
	for (size_t i = 1; i < arr.size(); ++i) {
		for (size_t j = 1; j + 1 < arr[i].size(); ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << arr[i].back() << '\n';
	}
}

// summed

template<typename T> T summed(const vector<T>& arr) {
	T result = static_cast<T>(0);
	for (const auto& V: arr) {
		result += V;
	}
	return result;
}

template<typename T> T summed(const set<T>& st) {
	T result = static_cast<T>(0);
	for (const auto& V: st) {
		result += V;
	}
	return result;
}

template<typename T> T summed(const unordered_set<T>& st) {
	T result = static_cast<T>(0);
	for (const auto& V: st) {
		result += V;
	}
	return result;
}

template<typename T> T summed(const multiset<T>& st) {
	T result = static_cast<T>(0);
	for (const auto& V: st) {
		result += V;
	}
	return result;
}

// max/min

template<typename T> T max(const vector<T>& arr) {
	T V = arr[0];
	for (size_t i = 1; i < arr.size(); ++i) {
		V = max(V, arr[i]);
	}
	return V;
}

template<typename T> T max(const vector<vector<T>>& arr) {
	T result = max(arr[0]);
	for (size_t i = 1; i < arr.size(); ++i) {
		result = max(result, max(arr[i]));
	}
	return result;
}

template<typename T> T max(const set<T>& st) {
	return *(st.rbegin());
}

template<typename T> T max(const unordered_set<T>& st) {
	T result = *st.begin();
	for (const auto& V: st) {
		result = max(result, V);
	}
	return result;
}

template<typename T> T max(const multiset<T>& st) {
	return *(st.rbegin());
}

template<typename T> T min(const vector<T>& arr) {
	T V = arr[0];
	for (size_t i = 1; i < arr.size(); ++i) {
		V = min(V, arr[i]);
	}
	return V;
}

template<typename T> T min(const vector<vector<T>>& arr) {
	T result = min(arr[0]);
	for (size_t i = 1; i < arr.size(); ++i) {
		result = min(result, min(arr[i]));
	}
	return result;
}

template<typename T> T min(const set<T>& st) {
	return *(st.begin());
}

template<typename T> T min(const unordered_set<T>& st) {
	T result = *st.begin();
	for (const auto& V: st) {
		result = min(result, V);
	}
	return result;
}

template<typename T> T min(const multiset<T>& st) {
	return *(st.begin());
}

template<typename T> void setmax(T& V1, const T& V2) {
	V1 = max(V1, V2);
}

template<typename T> void amax(T& V1, const T& V2) {
	setmax(V1, V2);
}

template<typename T> void smax(T& V1, const T& V2) {
	setmax(V1, V2);
}


template<typename T> void setmin(T& V1, const T& V2) {
	V1 = min(V1, V2);
}

template<typename T> void amin(T& V1, const T& V2) {
	setmin(V1, V2);
}

template<typename T> void smin(T& V1, const T& V2) {
	setmin(V1, V2);
}

// sort

template<typename T> void sort(T& obj) {
	sort(all(obj));
}

template<typename T> void usort(T& obj) {
	sort(all(obj));
	int p = 0;
	for (size_t i = 1; i < obj.size(); ++i) {
		if (obj[i] != obj[p]) {
			obj[++p] = obj[i];
		}
	}
	obj.resize(p + 1);
}

template<typename T> void rsort(T& obj) {
	sort(rall(obj));
}

template<typename T> void reverse(T& obj) {
	reverse(all(obj));
}

template<typename T> T sorted(T obj) {
	sort(obj);
	return obj;
}

template<typename T> T usorted(T obj) {
	usort(obj);
	return obj;
}

template<typename T> T rsorted(T obj) {
	rsort(obj);
	return obj;
}

template<typename T> T reversed(T obj) {
	reverse(obj);
	return obj;
}

// math

int sgn(int V) {
	if (V < 0) {
		return -1;
	}
	if (V > 0) {
		return 1;
	}
	return 0;
}

int gcd(int A, int B) {
	A = abs(A);
	B = abs(B);
	while (B > 0) {
		A %= B;
		swap(A, B);
	}
	return A;
}

int lcm(int A, int B) {
	if (A == 0 || B == 0) {
		throw "Incorrect lcm arguments";
	}
	A = abs(A);
	B = abs(B);
	return A / gcd(A, B) * B;
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

int binPow(int V, int a, int MOD) {
	return fastPow(V, a, MOD);
}

int getMex(const vector<int>& arr) {
	int N = arr.size();
	vector<bool> cnt_sort(N + 1, true);
	for (size_t i = 0; i < arr.size(); ++i) {
		if (arr[i] < N) {
			cnt_sort[arr[i]] = false;
		}
	}
	for (int i = 0; i <= N; i++) {
		if (cnt_sort[i]) return i;
	}
	return 0;
}

bool isPrime(int N) {
	if (N < 2) {
		return false;
	}
	for (int i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

int getBit(int N, int i) {
	return ((N >> i) & 1);
}

/*

 ██████  ██████  ██████  ███████     ███████ ████████  █████  ██████  ████████ ███████     ██   ██ ███████ ██████  ███████ 
██      ██    ██ ██   ██ ██          ██         ██    ██   ██ ██   ██    ██    ██          ██   ██ ██      ██   ██ ██      
██      ██    ██ ██   ██ █████       ███████    ██    ███████ ██████     ██    ███████     ███████ █████   ██████  █████   
██      ██    ██ ██   ██ ██               ██    ██    ██   ██ ██   ██    ██         ██     ██   ██ ██      ██   ██ ██      
 ██████  ██████  ██████  ███████     ███████    ██    ██   ██ ██   ██    ██    ███████     ██   ██ ███████ ██   ██ ███████ 

*/                                                                                                                                                               

void solve();
void precalc();

mt19937 mt_rand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mt_rand64(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
	
	#ifdef GCC
	#ifdef FILEIO
	freopen("workspace/input.txt", "r", stdin);
	freopen("workspace/output.txt", "w", stdout);
	#endif
	#endif
	
	srand(time(0));
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	//cout << fixed << setprecision(2);
	//cout.precision(20);
	
	//freopen("math.in", "r", stdin);
	//freopen("math.out", "w", stdout);
	
	precalc();
	
	int __TESTS_IN_TASK__ = 1;
	//cin >> __TESTS_IN_TASK__;
	
	for (int __TEST_CASE__ = 1; __TEST_CASE__ <= __TESTS_IN_TASK__; __TEST_CASE__++) {
		solve();
	}

	return 0;
}

const int INF = (int)2e15;
const int MOD = (int)998244353;

void precalc() {}

void solve() {
	
	

}