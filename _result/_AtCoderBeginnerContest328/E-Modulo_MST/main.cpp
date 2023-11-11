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

ll n, m, k;
ll ans = INFLL;
vector<vector<ll>> edges;

void solve(vector<int> vs) {
  ll sum = 0;
  int c = 0;

  dsu d(n);
  rep(i, m) {
    if (!vs[i]) continue;
    auto edge = edges[i];
    int from = edge[0];
    int to = edge[1];
    d.merge(from, to);
    sum += edge[2];
  }

  if (d.size(0) == n) ans = min(ans, sum % k);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> n >> m >> k;

  edges.resize(m);
  rep(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edges[i] = {u, v, w};
  }

  vector<int> vs;
  rep(i, m - (n - 1)) vs.push_back(0);
  rep(i, n - 1) vs.push_back(1);
  do {
    solve(vs);
  } while (next_permutation(all(vs)));
  out(ans);
}
