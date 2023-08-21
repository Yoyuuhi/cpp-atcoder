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

  int m;
  cin >> m;
  vector<int> ds(m);
  rep(i, m) cin >> ds[i];
  int sum = accumulate(all(ds), 0);
  int mid = (sum + 1) / 2;
  int idx = 0;
  while (ds[idx] < mid) {
    mid -= ds[idx];
    idx++;
  }
  cout << idx + 1 << ' ' << mid << endl;
}
