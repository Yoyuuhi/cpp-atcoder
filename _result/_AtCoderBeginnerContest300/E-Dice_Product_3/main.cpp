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

map<ll, mint> mem;

mint calc(ll n) {
  if (mem.find(n) != mem.end()) {
    return mem[n];
  }

  mint ans = 0;
  rep2(i, 2, 7) {
    if (n % i != 0) {
      continue;
    }

    ans += calc(n / i) / 5;
  }
  mem[n] = ans;
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  mem[1] = 1;
  out(calc(n).val());
}
