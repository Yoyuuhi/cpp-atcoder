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

  ll n, w;
  cin >> n >> w;
  vector<vector<pair<ll, ll>>> wv(4);
  rep(i, 4) wv[i].push_back({0, 0});
  ll w0, v0;
  cin >> w0 >> v0;
  wv[0].push_back({w0, v0});
  rep(i, n - 1) {
    ll w, v;
    cin >> w >> v;
    wv[w - w0].push_back({w, v});
  }
  rep(i, 4) {
    sort(all(wv[i]), greater<pair<ll, ll>>());
    rep2(j, 1, wv[i].size() - 1) {
      wv[i][j].first += wv[i][j - 1].first;
      wv[i][j].second += wv[i][j - 1].second;
    }
  }

  ll ans = 0;
  rep(i, wv[0].size()) {
    rep(j, wv[1].size()) {
      rep(k, wv[2].size()) {
        rep(l, wv[3].size()) {
          if (wv[0][i].first + wv[1][j].first + wv[2][k].first +
                  wv[3][l].first >
              w)
            continue;

          ans = max(ans, wv[0][i].second + wv[1][j].second + wv[2][k].second +
                             wv[3][l].second);
        }
      }
    }
  }
  out(ans);
}
