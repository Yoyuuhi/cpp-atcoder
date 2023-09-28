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

  double a, b;
  double h, m;
  cin >> a >> b >> h >> m;
  if (a > b) swap(a, b);
  double d1 = h * 360 / 12 + m * 360 / 60 / 12;
  double d2 = m * 360 / 60 + 360;
  double deg1 = (d1 >= d2) ? d1 - d2 : d1 + 360 - d2;
  double deg2 = (d2 >= d1) ? d2 - d1 : d2 + 360 - d1;
  double deg = min(deg1, deg2);

  double l1 = a * sin(deg * M_PI / 180);
  double l2 = b - a * cos(deg * M_PI / 180);
  double ans = sqrt(l1 * l1 + l2 * l2);
  cout << fixed << setprecision(16) << ans << endl;
}
