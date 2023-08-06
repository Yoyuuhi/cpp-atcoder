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

  int n, m;
  cin >> n >> m;
  vector<bool> mem(n, false);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    mem[b - 1] = true;
  }
  int num = -1;
  rep(i, n) {
    if (mem[i]) continue;
    if (num == -1) {
      num = i;
    } else if (!mem[i] && num != -1) {
      out(-1);
      return 0;
    }
  }
  out(num + 1);
}
