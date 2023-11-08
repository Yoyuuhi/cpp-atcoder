#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outwoln(X) cout << (X);
#ifdef __LOCAL
#define DBG(X) cout << #X << " = " << (X) << endl;
#else
#define DBG(X)
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define outv(vs) \
  for (auto v : vs) out(v)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;
vector<ll> nis(int n) {
  vector<ll> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<ll> as = nis(n);

  int c1 = 0;
  int c2 = 0;
  for (auto a : as) {
    if (a % 2 == 0) c1++;
    if (a % 4 == 0) c2++;
  }
  int c3 = n - c1;
  c1 -= c2;
  if (c1) c3++;

  c1 %= 2;
  cout << (c2 >= c3 - 1 ? "Yes" : "No") << endl;
}
