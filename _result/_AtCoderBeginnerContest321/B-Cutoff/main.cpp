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

int calc(vector<int> bs) {
  sort(all(bs));
  int ans = 0;
  rep2(i, 1, bs.size() - 1) { ans += bs[i]; }
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, x;
  cin >> n >> x;
  vector<int> as;
  rep(i, n - 1) {
    int a;
    cin >> a;
    as.push_back(a);
  }

  int ans = INF;
  rep(i, 101) {
    vector<int> bs;
    for (auto a : as) bs.push_back(a);
    bs.push_back(i);
    if (calc(bs) >= x) ans = min(ans, i);
  }
  cout << (ans == INF ? -1 : ans) << endl;
}
