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

  ll n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);

  ll ans = 0;
  if (m == 1) {
    ans = 1;
  } else if (n == 1) {
    ans = m - 2;
  } else {
    ans = (n - 2) * (m - 2);
  }
  out(ans);
}
