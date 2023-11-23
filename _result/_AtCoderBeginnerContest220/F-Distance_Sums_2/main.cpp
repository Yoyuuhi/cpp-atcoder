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
ll ni() {
  ll ret;
  cin >> ret;
  return ret;
}
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

int n;

using Graph = vector<vector<int>>;
vector<ll> cdown;
vector<bool> seen;
ll a0 = 0;
ll dfs(const Graph &G, int v) {
  ll cnt = 1;
  for (auto next : G[v]) {
    if (!seen[next]) {
      seen[next] = true;
      int nc = dfs(G, next);
      cnt += nc;
      a0 += nc;
    }
  }
  cdown[v] = cnt;
  return cnt;
}

vector<ll> ans;
void calc(const Graph &G, int v) {
  for (auto next : G[v]) {
    if (!seen[next]) {
      seen[next] = true;
      ll num = ans[v];
      num -= cdown[next];
      num += n - cdown[next];
      ans[next] = num;
      calc(G, next);
    }
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  Graph g(n);
  rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cdown.assign(n, 0);
  seen.assign(n, false);
  seen[0] = true;
  dfs(g, 0);

  ans.assign(n, 0);
  ans[0] = a0;
  seen.assign(n, false);
  seen[0] = true;
  calc(g, 0);
  for (auto a : ans) out(a);
}
