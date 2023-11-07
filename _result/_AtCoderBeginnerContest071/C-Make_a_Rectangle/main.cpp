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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> as(n);
  rep(i, n) cin >> as[i];
  sort(all(as), greater<int>());

  map<int, int> mem;
  ll x = 0;
  for (auto a : as) {
    mem[a]++;
    if (mem[a] == 2) {
      mem[a] = 0;
      if (x) {
        out(x * a);
        return 0;
      } else {
        x = a;
      }
    }
  }
  out(0);
}
