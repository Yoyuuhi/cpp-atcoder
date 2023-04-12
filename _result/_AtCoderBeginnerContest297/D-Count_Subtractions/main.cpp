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
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

ll ans;
void cal(ll a, ll b) {
  if (a == b) return;
  if (a < b) swap(a, b);
  if (!(a % b)) {
    ans += a / b - 1;
    return;
  }
  ans += a / b;
  cal(a % b, b);
}
int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll a, b;
  cin >> a >> b;
  ans = 0;
  cal(a, b);
  out(ans);
}
