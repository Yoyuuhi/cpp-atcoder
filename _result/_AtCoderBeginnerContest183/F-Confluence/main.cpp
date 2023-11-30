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

  int n, q;
  cin >> n >> q;
  auto cs = nis(n);
  vector<int> pos(n);
  rep(i, n) pos[i] = i;
  vector<vector<int>> ps(n);
  vector<map<int, int>> memc(n);
  rep(i, n) {
    memc[i][cs[i]] = 1;
    ps[i].push_back(i);
  }

  rep(i, q) {
    int que;
    cin >> que;
    if (que == 1) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      int ia = pos[a];
      int ib = pos[b];
      if (ia == ib) continue;
      if (ps[ia].size() < ps[ib].size()) swap(ia, ib);
      for (auto p : ps[ib]) {
        pos[p] = ia;
        ps[ia].push_back(p);
        memc[ia][cs[p]]++;
      }
    }
    if (que == 2) {
      int x, y;
      cin >> x >> y;
      x--;
      cout << (memc[pos[x]].find(y) == memc[pos[x]].end() ? 0 : memc[pos[x]][y])
           << endl;
    }
  }
}
