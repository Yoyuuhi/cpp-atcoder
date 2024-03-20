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

struct Edge {
  long long from;
  long long to;
};
using Graph = map<int, Edge>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  auto as = nis(n);
  auto s = as[0];

  Graph g;
  rep2(i, 1, n - 1) g[as[i]] = {as[i - 1], as[i + 1]};
  if (n > 1) {
    g[as[0]] = {-1, as[1]};
    g[as[n - 1]] = {as[n - 2], INF};
  } else {
    g[as[0]] = {-1, INF};
  }

  int q;
  cin >> q;
  rep(i, q) {
    int que;
    cin >> que;
    if (que == 1) {
      int x, y;
      cin >> x >> y;
      int to = g[x].to;

      g[x].to = y;
      g[y] = {x, to};
      if (to != INF) g[to].from = y;
    }
    if (que == 2) {
      int x;
      cin >> x;
      int from = g[x].from;
      int to = g[x].to;

      if (to != INF) g[to].from = from;
      if (from != -1) {
        g[from].to = to;
      } else {
        s = to;
      }
    }
  }

  while (s != INF) {
    cout << s << ' ';
    s = g[s].to;
  }
  outl;
}
