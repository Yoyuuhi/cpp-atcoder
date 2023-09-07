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

  fenwick_tree<mint> fcount(200001);
  fenwick_tree<mint> fsum(200001);
  vector<mint> ans;
  rep(i, n) {
    int a = as[i];
    mint s = 0;
    if (i) s += ans[i - 1] * i * i;
    s += (fcount.sum(0, a) * 2 + fcount.sum(a, a + 1) * 2 + 1) * a;
    s += fsum.sum(a + 1, 200001) * 2;
    ans.push_back(s / (i + 1) / (i + 1));
    fcount.add(a, 1);
    fsum.add(a, a);
  }
  for (auto a : ans) out(a.val());
}
