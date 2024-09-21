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

  int n, q;
  cin >> n >> q;

  dsu d(n);
  vector<priority_queue<int, vector<int>>> mempq;
  map<int, int> memc;
  int c = 0;

  rep(i, q) {
    int que;
    cin >> que;
    if (que == 1) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;

      if (d.same(u, v)) continue;
      auto su = d.size(u);
      auto sv = d.size(v);

      if (su < sv) swap(u, v);
      auto lu = d.leader(u);
      auto lv = d.leader(v);
      if (memc.find(lu) == memc.end()) {
        memc[lu] = c;
        c++;

        priority_queue<int, vector<int>> pq;
        pq.emplace(lu);
        mempq.push_back(pq);
      }

      if (memc.find(lv) == memc.end()) {
        mempq[memc[lu]].emplace(lv);
      } else {
        while (!mempq[memc[lv]].empty()) {
          auto pp = mempq[memc[lv]].top();
          mempq[memc[lv]].pop();
          mempq[memc[lu]].emplace(pp);
        }
      }

      d.merge(u, v);
    }
    if (que == 2) {
      int v, k;
      cin >> v >> k;
      v--;

      if (k > d.size(v)) {
        out(-1);
        continue;
      }

      if (d.size(v) == 1) {
        out(v + 1);
        continue;
      }

      vector<int> pps;
      int col = memc[d.leader(v)];
      int pp = -1;
      rep(ii, k) {
        pp = mempq[col].top();
        mempq[col].pop();
        pps.push_back(pp);
      }
      out(pp + 1);

      for (auto p : pps) mempq[col].emplace(p);
    }
  }
}
