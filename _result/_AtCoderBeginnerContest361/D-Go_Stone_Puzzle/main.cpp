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

struct S {
  int to;
  int bit;
};

int n;
int calcBit(vector<int> v) {
  int bit = 0;
  rep(i, n + 2) {
    bit *= 3;
    bit += v[i];
  }
  return bit;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> n;
  string s, t;
  cin >> s >> t;

  vector<int> vs(n + 2, 0), vt(n + 2, 0);
  int bits = 0, bitt = 0;
  rep(i, n) {
    auto cs = s[i], ct = t[i];
    if (cs == 'W') {
      vs[i] = 1;
      bits += 1;
    }
    if (cs == 'B') {
      vs[i] = 2;
      bits += 2;
    }
    if (ct == 'W') {
      vt[i] = 1;
      bitt += 1;
    }
    if (ct == 'B') {
      vt[i] = 2;
      bitt += 2;
    }

    bits *= 3;
    bitt *= 3;
  }
  bits *= 3;
  bitt *= 3;
  map<int, int> mem;
  mem[bits] = 0;

  queue<vector<int>> que;
  que.push(vs);
  while (!que.empty()) {
    auto v = que.front();
    int vBit = calcBit(v);
    // outs(v);
    // DBG(vBit);
    if (vBit == bitt) {
      out(mem[vBit]);
      return 0;
    }
    que.pop();

    int ei = -1;
    rep(i, n + 2) {
      if (v[i] == 0) {
        ei = i;
        break;
      }
    }
    // DBG(ei)

    rep(i, n + 1) {
      if (v[i] == 0 || v[i + 1] == 0) continue;
      auto vv = v;
      swap(vv[i], vv[ei]);
      swap(vv[i + 1], vv[ei + 1]);
      // outs(vv);
      int bit = calcBit(vv);
      if (mem.find(bit) != mem.end()) continue;
      mem[bit] = mem[vBit] + 1;
      que.push(vv);
    }
  }
  out(-1);
}
