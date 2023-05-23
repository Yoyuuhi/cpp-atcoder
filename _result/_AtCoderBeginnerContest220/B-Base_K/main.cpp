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

  ll k;
  cin >> k;
  ll a, b;
  cin >> a >> b;

  ll aa = 0;
  ll bb = 0;
  ll ks = 1;
  ll ten = 10;
  rep(i, 19) {
    aa += a % ten / (ten / 10) * ks;
    bb += b % ten / (ten / 10) * ks;
    ten *= 10;
    ks *= k;
  }
  out(aa * bb);
}
