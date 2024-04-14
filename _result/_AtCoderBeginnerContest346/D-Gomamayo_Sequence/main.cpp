#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  string s;
  cin >> s;
  auto cs = nis(n);

  vector<vector<ll>> mem(n, vector<ll>(2, 0));
  rep(i, n) {
    if (i > 0) {
      mem[i][0] += mem[i - 1][1];
      mem[i][1] += mem[i - 1][0];
    }
    if (s[i] == '0') {
      mem[i][1] += cs[i];
    } else {
      mem[i][0] += cs[i];
    }
  }
  vector<vector<ll>> memr(n, vector<ll>(2, 0));
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1) {
      memr[i][0] += memr[i + 1][1];
      memr[i][1] += memr[i + 1][0];
    }
    if (s[i] == '0') {
      memr[i][1] += cs[i];
    } else {
      memr[i][0] += cs[i];
    }
  }

  ll ans = INFLL;
  rep(i, n - 1) {
    ans = min(ans, mem[i][0] + memr[i + 1][0]);
    ans = min(ans, mem[i][1] + memr[i + 1][1]);
  }
  out(ans);
}
