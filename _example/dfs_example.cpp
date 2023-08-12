// https://atcoder.jp/contests/abc310/tasks/abc310_d
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

int ans;
int n, t, m;
vector<int> teams;
vector<int> bad;

void dfs(int now) {
  if (now == n) {
    if (teams.size() == t) ans++;
    return;
  }
  for (auto& te : teams) {
    if (te & bad[now]) continue;
    te ^= 1 << now;
    dfs(now + 1);
    te ^= 1 << now;
  }

  if (teams.size() < t) {
    teams.push_back(1 << now);
    dfs(now + 1);
    teams.pop_back();
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> t >> m;
  bad.assign(n, 0);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    bad[a] ^= 1 << b;
    bad[b] ^= 1 << a;
  }

  teams.reserve(t);
  ans = 0;
  dfs(0);
  out(ans);
}