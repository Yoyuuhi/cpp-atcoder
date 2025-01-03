#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int ans = 0;
int n;
vector<int> as;
void calc(int right) {
  while (right >= 0 && as[right] != as[right + 1]) right -= 2;
  if (right < 0) return;
  map<int, bool> mem;

  for (int left = right; left >= 0; left -= 2) {
    if (as[left] != as[left + 1]) {
      right = left;
      while (right >= 0 && as[right] != as[right + 1]) right -= 2;
      if (right < 0) return;

      mem.clear();
    }
    if (left > right) continue;

    while (mem[as[left]]) {
      mem[as[right]] = false;
      right -= 2;
    }
    mem[as[left]] = true;
    ans = max(ans, right - left + 2);
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  as = nis(n);
  calc(n - 2);
  calc(n - 3);

  out(ans);
}
