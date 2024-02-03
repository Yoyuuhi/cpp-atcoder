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

int n;
vector<string> ss;
int calc(int num0, vector<int> v) {
  int x0 = num0 / n;
  int y0 = num0 % n;
  int x = x0 + v[0], y = y0 + v[1];

  if (x < 0 || x >= n || y < 0 || y >= n) return num0;
  if (ss[x][y] == '#') return num0;
  return x * n + y;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  ss.resize(n);
  rep(i, n) cin >> ss[i];
  int p1 = -1, p2 = -1;

  rep(i, n) {
    rep(j, n) {
      if (ss[i][j] == 'P') {
        if (p1 == -1) {
          p1 = i * n + j;
        } else {
          p2 = i * n + j;
        }
      }
    }
  }
  if (p1 > p2) swap(p1, p2);

  vector<vector<int>> vs = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  queue<pair<int, int>> que;
  que.push({p1, p2});
  vector<vector<ll>> dp(n * n, vector<ll>(n * n, INFLL));
  dp[p1][p2] = 0;
  while (!que.empty()) {
    auto now = que.front();
    p1 = now.first;
    p2 = now.second;
    que.pop();

    for (auto v : vs) {
      int pp1 = calc(p1, v);
      int pp2 = calc(p2, v);
      if (pp1 > pp2) swap(pp1, pp2);
      if (dp[pp1][pp2] == INFLL) {
        dp[pp1][pp2] = dp[p1][p2] + 1;
        que.push({pp1, pp2});
      }
    }
  }

  ll ans = INFLL;
  rep(i, n * n) ans = min(ans, dp[i][i]);
  if (ans == INFLL) {
    out(-1);
  } else {
    out(ans);
  }
}
