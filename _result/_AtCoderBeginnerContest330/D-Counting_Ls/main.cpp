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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  vector<ll> memr(n, 0);
  rep(i, n) {
    ll num = 0;
    rep(j, n) {
      if (ss[i][j] == 'o') num++;
    }
    memr[i] = num;
  }
  vector<ll> memc(n, 0);
  rep(j, n) {
    ll num = 0;
    rep(i, n) {
      if (ss[i][j] == 'o') num++;
    }
    memc[j] = num;
  }

  ll ans = 0;
  rep(i, n) {
    rep(j, n) {
      if (ss[i][j] != 'o') continue;
      ans += (memr[i] - 1) * (memc[j] - 1);
    }
  }
  out(ans);
}
