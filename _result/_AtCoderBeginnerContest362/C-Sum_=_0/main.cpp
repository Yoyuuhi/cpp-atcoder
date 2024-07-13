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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<vector<ll>> lrs;
  vector<ll> ans;

  ll mi = 0, ma = 0;
  rep(i, n) {
    ll l, r;
    cin >> l >> r;
    mi += l;
    ma += r;
    lrs.push_back({l, r});
    ans.push_back(l);
  }

  if (mi <= 0 && ma >= 0) {
    out("Yes");
  } else {
    out("No");
    return 0;
  }

  ll diff = -mi;
  rep(i, n) {
    if (diff == 0) break;
    ll l = lrs[i][0], r = lrs[i][1];
    if (r - l > diff) {
      ans[i] += diff;
      diff = 0;
    } else {
      diff -= r - l;
      ans[i] = r;
    }
  }

  outs(ans);
}
