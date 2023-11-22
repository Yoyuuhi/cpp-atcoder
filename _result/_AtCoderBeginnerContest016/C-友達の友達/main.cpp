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

using Graph = vector<vector<int>>;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  rep(i, n) {
    int ans = 0;
    vector<int> mem(n, -1);
    queue<int> que;
    que.push(i);
    while (!que.empty()) {
      int now = que.front();
      que.pop();
      if (mem[now] == -1) mem[now] = 0;
      for (auto to : g[now]) {
        if (mem[to] != -1) continue;
        mem[to] = mem[now] + 1;
        if (mem[to] == 2) ans++;
        que.push(to);
      }
    }
    out(ans);
  }
}
