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
  int l = 0;
  int r = 1000;
  vector<int> as(n);
  vector<int> bs(n);
  rep(i, n) cin >> as[i];
  rep(i, n) cin >> bs[i];
  rep(i, n) {
    r = min(r, bs[i]);
    l = max(l, as[i]);
  }
  out(max(0, r - l + 1));
}
