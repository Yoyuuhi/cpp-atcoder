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

  int x, n;
  cin >> x >> n;
  vector<bool> mem(101);
  rep(i, n) {
    int p;
    cin >> p;
    mem[p] = true;
  }

  int ans;
  int dis = INF;
  rep(i, 102) {
    if (mem[i]) continue;
    if (abs(x - i) < dis) {
      dis = abs(x - i);
      ans = i;
    }
  }
  out(ans);
}
