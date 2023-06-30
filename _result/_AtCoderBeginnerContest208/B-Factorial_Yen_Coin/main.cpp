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

int factorial(int n) {
  int i;
  int val = 1;

  for (i = 1; i <= n; i++) {
    val = val * i;
  }

  return (val);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int p;
  cin >> p;
  vector<int> as(10);
  rep(i, 10) as[i] = factorial(i + 1);

  int ans = 0;
  for (int i = 9; i > -1; i--) {
    ans += p / as[i];
    p -= p / as[i] * as[i];
  }
  out(ans);
}
