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

using P = pair<int, int>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  vector<int> mem(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    mem[a]++;
    mem[b]++;
  }

  vector<bool> isV(n, false);
  rep(i, k) {
    int v;
    cin >> v;
    v--;
    isV[v] = true;
  }

  priority_queue<P, vector<P>, greater<P>> pq;
  rep(i, n) pq.emplace(mem[i], i);
  int ans = n;
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();

    if (isV[p.second] || mem[p.second] == 0 || mem[p.second] > 1) continue;
    mem[p.second] = 0;
    ans--;
    for (auto to : g[p.second]) {
      if (mem[to]) {
        mem[to]--;
        pq.emplace(mem[to], to);
      }
    }
  }

  out(ans);
}
