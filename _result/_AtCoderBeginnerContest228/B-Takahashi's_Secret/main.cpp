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

  int n, x;
  cin >> n >> x;
  x--;
  vector<int> as(n);
  rep(i, n) {
    cin >> as[i];
    as[i]--;
  }

  vector<bool> mem(n);
  while (!mem[x]) {
    mem[x] = true;
    x = as[x];
  }
  int ans = 0;
  rep(i, n) {
    if (mem[i]) ans++;
  }
  out(ans);
}
