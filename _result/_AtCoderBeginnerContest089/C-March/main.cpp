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

  ll n;
  cin >> n;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];
  vector<ll> mem(5, 0);
  rep(i, n) {
    char c = ss[i][0];
    if (c == 'M') {
      mem[0]++;
    } else if (c == 'A') {
      mem[1]++;
    } else if (c == 'R') {
      mem[2]++;
    } else if (c == 'C') {
      mem[3]++;
    } else if (c == 'H') {
      mem[4]++;
    }
  }

  ll ans = 0;
  rep(i, 5) {
    rep2(j, i + 1, 5) {
      rep2(k, j + 1, 5) { ans += mem[i] * mem[j] * mem[k]; }
    }
  }
  out(ans);
}
