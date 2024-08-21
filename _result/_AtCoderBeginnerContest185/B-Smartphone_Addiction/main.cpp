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

  ll N, m, t;
  cin >> N >> m >> t;
  vector<vector<ll>> as;
  as.push_back({0, 0});
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    as.push_back({a, b});
  }

  ll n = N;
  rep2(i, 1, m + 1) {
    ll a = as[i][0], b = as[i][1], b0 = as[i - 1][1];
    if (a - b0 >= n) {
      out("No");
      return 0;
    }
    n -= a - b0;

    n = min(N, n + (b - a));
  }
  if (t - as[m][1] >= n) {
    out("No");
  } else {
    out("Yes");
  }
}
