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
  vector<int> ss(n);
  rep(i, n) cin >> ss[i];
  vector<bool> mem(n, false);

  rep2(a, 1, 1001) {
    rep2(b, 1, 1001) {
      rep(i, n) {
        if (ss[i] == 4 * a * b + 3 * a + 3 * b) mem[i] = true;
      }
    }
  }

  int ans = 0;
  rep(i, n) {
    if (!mem[i]) ans++;
  }
  out(ans);
}
