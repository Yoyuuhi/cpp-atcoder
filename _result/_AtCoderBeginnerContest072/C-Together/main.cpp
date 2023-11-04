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
  vector<int> as(n);
  rep(i, n) cin >> as[i];

  vector<int> mem(100003, 0);
  for (auto a : as) {
    a++;
    mem[a - 1] += 1;
    mem[a + 2] -= 1;
  }
  int ans = 0;
  rep(i, 100003) {
    if (i) mem[i] += mem[i - 1];
    ans = max(ans, mem[i]);
  }
  out(ans);
}
