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

  ll h, w, m;
  cin>>h>>w>>m;

  vector<vector<ll>> qs;
  rep(i, m) {
    ll t, a, x;
    cin>>t>>a>>x;
    a--;
    qs.push_back({t, a, x});
  }

  vector<bool> memh(h, false), memw(w, false);
  vector<ll> ans(200001, 0);
  ans[0] = h * w;
  for (int i = qs.size()-1; i >= 0; i--) {
    ll t = qs[i][0], a = qs[i][1], x = qs[i][2];
    if (t == 1) {
      if (memh[a] || w == 0) continue;
      memh[a] = true;
      ans[x] += w;
      ans[0] -= w;
      h--;
    } else {
      if (memw[a] || h == 0) continue;
      memw[a] = true;
      ans[x] += h;
      ans[0] -= h;
      w--;
    }
  }

  ll c = 0;
  rep(i, 200001) if (ans[i]) c++;

  out(c);
  rep(i, 200001) {
    if (ans[i] == 0) continue;
    cout<<i<<' '<<ans[i]<<endl;
  }
}
