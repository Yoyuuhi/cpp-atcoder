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

long long lcm2(long long a, long long b) {
  long long d = gcd(a, b);
  return a / d * b;
}
long long lcm(const vector<long long> &vec) {
  long long l = vec[0];
  for (int i = 0; i < vec.size() - 1; i++) {
    l = lcm2(l, vec[i + 1]);
  }
  return l;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  auto ts = nis(n);
  out(lcm(ts));
}
