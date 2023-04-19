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
  vector<int> as(n), bs(n);
  rep(i, n) { cin >> as[i]; }
  rep(i, n) { cin >> bs[i]; }

  vector<int> mema(n + 1), memb(n + 1);
  rep(i, n) {
    mema[as[i]] += 1;
    memb[bs[i]] += 1;
  }

  bool hasDup = false;
  rep(i, n + 1) {
    if (mema[i] != memb[i]) {
      out("No");
      return 0;
    }
    if (mema[i] > 1) {
      hasDup = true;
    }
  }

  if (hasDup) {
    out("Yes");
    return 0;
  }

  int count = 0;
  fenwick_tree<int> fa(n + 1), fb(n + 1);
  rep(i, n) {
    count = (count + fa.sum(0, as[i])) % 2;
    fa.add(as[i] - 1, 1);
    count = (count + fb.sum(0, bs[i])) % 2;
    fb.add(bs[i] - 1, 1);
  }
  if (count) {
    out("No");
  } else {
    out("Yes");
  }
}
