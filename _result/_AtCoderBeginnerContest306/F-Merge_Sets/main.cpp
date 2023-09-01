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
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  vector<vector<int>> ax(n);
  vector<int> at;
  rep(i, n) {
    int a;
    rep(j, m) {
      cin >> a;
      ax[i].push_back(a);
      at.push_back(a);
    }
    sort(all(ax[i]));
  }
  sort(all(at));

  map<int, int> mem;
  rep(i, m * n) mem[at[i]] = i;

  ll ans = 0;
  fenwick_tree<int> f(n * m);
  for (int i = n - 1; i >= 0; i--) {
    rep(j, m) {
      ans += (j + 1) * (n - 1 - i);
      ans += f.sum(0, mem[ax[i][j]]);
    }
    rep(j, m) f.add(mem[ax[i][j]], 1);
  }
  out(ans);
}
