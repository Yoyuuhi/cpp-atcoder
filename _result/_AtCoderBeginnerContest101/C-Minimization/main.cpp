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

  int n, k;
  cin >> n >> k;
  vector<int> as(n);
  rep(i, n) cin >> as[i];

  int pos;
  rep(i, n) {
    if (as[i] == 1) {
      pos = i;
      break;
    }
  }

  int ans = INF;
  rep(i, min(k, pos + 1)) {
    int ta = 1 + (pos - i) / (k - 1) + max(0, n - pos - k + i) / (k - 1);
    if ((pos - i) % (k - 1)) ta++;
    if (max(0, n - pos - k + i) % (k - 1)) ta++;
    ans = min(ans, ta);
  }
  out(ans);
}
