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

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

long long lcm2(long long a, long long b) {
  long long d = gcd(a, b);
  return a / d * b;
}

long long lcm(const vector<long long> &vec) {
  long long l = vec[0];
  for (int i = 0; i < vec.size() - 1; i++) {
    l = lcm2(l, vec[i + 1]);
  }
  return l;
}

int n, x, y;
vector<pair<int, int>> pts;
int q;
vector<int> qs;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> x >> y;
  pts.resize(n - 1);
  rep(i, n - 1) {
    int p, t;
    cin >> p >> t;
    pts[i] = {p, t};
  }
  cin >> q;
  qs.resize(q);
  rep(i, q) cin >> qs[i];

  vector<ll> ps;
  for (auto pt : pts) ps.push_back(pt.first);
  int l = lcm(ps);

  vector<vector<ll>> dp(n, vector<ll>(l, INF));
  rep(i, l) dp[n - 1][i] = 0;
  pts.push_back({1, 0});
  for (int i = n - 2; i >= 0; i--) {
    int p = pts[i].first;
    int pn = pts[i + 1].first;
    int t = pts[i].second;
    for (int j = 0; j * p < l; j++) {
      int pos = j * p;
      int post = pos + t;
      int posn = (post / pn * pn + ((post % pn) ? pn : 0)) % l;
      dp[i][pos] = t + (posn - post % l + l) % l + dp[i + 1][posn];
    }
  }
  for (auto q : qs) {
    int pos = q + x;
    int pn = pts[0].first;
    int posn = (pos / pn * pn + ((pos % pn) ? pn : 0)) % l;
    out(pos + (posn - pos % l + l) % l + dp[0][posn] + y);
  }
}
