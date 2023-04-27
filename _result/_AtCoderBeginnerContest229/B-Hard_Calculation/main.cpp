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

  ll a, b;
  cin >> a >> b;

  rep(i, 18) {
    ll tens = 1;
    rep(j, i) tens *= 10;
    ll aa = a / tens % 10;
    ll bb = b / tens % 10;
    if (aa + bb >= 10) {
      out("Hard");
      return 0;
    }
  }
  out("Easy");
}
