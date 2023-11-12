#include <bits/stdc++.h>

#include <atcoder/all>
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
typename enable_if<is_same_v<T, ll> || is_same_v<T, int> ||
                       is_same_v<T, unsigned int>,
                   void>::type
out(T value) {
  cout << value << endl;
}
template <typename T>
typename enable_if<is_same_v<T, mint>, void>::type out(T value) {
  cout << value.val() << endl;
}
template <typename T>
typename enable_if<is_same_v<T, vector<ll>> || is_same_v<T, vector<int>>,
                   void>::type
out(T value) {
  for (auto v : value) cout << v << " ";
  cout << endl;
}

using Graph = vector<vector<int>>;
vector<int> mem;
vector<bool> seen;
Graph g;

bool dfs(int now) {
  if (mem[now] == 1 || seen[now]) return true;
  if (mem[now] == 2) return false;
  seen[now] = true;

  for (auto to : g[now]) {
    if (dfs(to)) {
      mem[now] = 1;
      mem[to] = 1;
      return true;
    }
  }
  mem[now] = 2;
  seen[now] = false;
  return false;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  g.resize(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
  }

  mem.assign(n, 0);
  rep(i, n) {
    seen.assign(n, false);
    dfs(i);
  }
  int ans = 0;
  for (auto me : mem)
    if (me == 1) ans++;
  out(ans);
}
