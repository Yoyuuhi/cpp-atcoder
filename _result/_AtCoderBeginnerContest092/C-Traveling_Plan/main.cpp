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

  int n;
  cin >> n;
  vector<int> as(n + 1, 0);
  rep(i, n) cin >> as[i + 1];

  int s = 0;
  rep2(i, 1, n + 1) { s += abs(as[i] - as[i - 1]); }
  s += abs(as[n]);

  rep2(i, 1, n + 1) {
    int f = i - 1;
    int t = (i + 1) % (n + 1);
    out(s - abs(as[i] - as[f]) - abs(as[t] - as[i]) + abs(as[f] - as[t]));
  }
}
