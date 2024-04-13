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

  ll n, a, b;
  cin>>n>>a>>b;
  auto ds = nis(n);

  vector<vector<ll>> lrs;
  rep2(i, 1, n) {
    ll d = ds[i];
    d -= ds[0];
    d %= a + b;
    if (d == 0) continue;

    ll l = max(ll(1), a + 1 - d);
    ll r = min(a, a + b - d);
    lrs.push_back({l, r});
  }
  sort(all(lrs));

  if (lrs.size() == 0 || lrs[0][0] > 1 || lrs[lrs.size()-1][1] < a) {
    out("Yes");
    return 0;
  }

  rep(i, lrs.size()-1) {
    if (lrs[i][1] + 1 < lrs[i+1][0]) {
      out("Yes");
      return 0;
    }
  }
  out("No");
}
