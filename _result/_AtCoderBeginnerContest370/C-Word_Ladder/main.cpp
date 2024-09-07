#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
#ifdef __LOCAL
#define DBG(X) cout << #X << " = " << (X) << endl;
#else
#define DBG(X)
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator()
      : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) {  // [a, b)
    uniform_int_distribution<int> dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) {  // [0, b)
    return (*this)(0, b);
  }
};

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    if (!item.empty()) {
      elems.push_back(item);
    }
  }
  return elems;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  string s, t;
  cin >> s >> t;
  vector<int> m;
  rep(i, s.size()) {
    auto c1 = s[i], c2 = t[i];
    if (c1 == c2) continue;
    if (c1 > c2) m.push_back(i);
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    auto c1 = s[i], c2 = t[i];
    if (c1 == c2) continue;
    if (c1 < c2) m.push_back(i);
  }

  out(m.size());
  for (auto i : m) {
    s[i] = t[i];
    out(s);
  }
}
