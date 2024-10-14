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

ll ans;
void calc(vector<ll> is) {
  rep(i, is.size() - 1) ans -= (is[i] + 1) * (is.size() - 1 - i);
  rep2(i, 1, is.size()) ans += is[i] * i;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  string s;
  cin >> s;
  ans = 0;

  vector<vector<ll>> mem(26);
  rep(i, 26) {
    auto c = 'A' + i;
    rep(ii, s.size()) if (s[ii] == c) mem[i].push_back(ii);
    calc(mem[i]);
  }
  out(ans);
}
