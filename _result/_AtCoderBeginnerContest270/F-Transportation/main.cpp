#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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
using mint = atcoder::modint998244353;
const ll INF = numeric_limits<ll>::max() / 2;

int n, m;
vector<int> xs;
vector<int> ys;
vector<vector<int>> as;

auto compare = [](vector<ll> &a1, vector<ll> &a2) -> bool {
  return a1[2] > a2[2];
};

ll calc(int bit) {
  int s = n;
  priority_queue<vector<ll>, vector<vector<ll>>, decltype(compare)> pq(compare);
  if (bit & (1 << 0)) {
    s++;
    rep(i, xs.size()) pq.push({i + 1, s, xs[i]});
  }
  if (bit & (1 << 1)) {
    s++;
    rep(i, ys.size()) pq.push({i + 1, s, ys[i]});
  }
  if (bit & (1 << 2)) {
    for (auto abz : as) pq.push({abz[0], abz[1], abz[2]});
  }

  dsu d(s + 1);
  ll ans = 0;
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int a = p[0];
    int b = p[1];
    int z = p[2];
    if (!d.same(a, b)) {
      d.merge(a, b);
      ans += z;
    }
  }
  return d.size(1) == s ? ans : INF;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m;
  xs.resize(n);
  rep(i, n) cin >> xs[i];
  ys.resize(n);
  rep(i, n) cin >> ys[i];

  as.resize(m, vector<int>(3));
  rep(i, m) rep(j, 3) cin >> as[i][j];

  ll ans = INF;
  rep2(bit, 1, 1 << 3) { ans = min(ans, calc(bit)); }
  out(ans);
}
