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
using mint = atcoder::modint998244353;
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

int n, k;
string s;

bool validBit(int bit) {
  rep(i, k / 2) {
    if (((bit >> i) & 1) != ((bit >> (k - 1 - i)) & 1)) {
      return true;
    }
  }
  return false;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> k;

  cin >> s;

  vector<vector<mint>> dp(s.size() + 1, vector<mint>(1 << k, 0));

  vector<int> bits;
  bits.push_back(0);
  rep(i, k - 1) {
    vector<int> bits1;
    char c = s[i];

    for (auto b : bits) {
      if (c == '?') {
        bits1.push_back(b << 1);
        bits1.push_back((b << 1) + 1);
      } else {
        bits1.push_back((b << 1) + (c - 'A'));
      }
    }
    bits = bits1;
  }

  for (auto bit : bits) dp[k - 1][bit]++;
  rep2(i, k - 1, n) {
    char c = s[i];

    rep(bit, 1 << k) {
      if (dp[i][bit].val() == 0) continue;

      if (c == '?') {
        if (validBit(bit << 1))
          dp[i + 1][(bit << 1) & ((1 << (k - 1)) - 1)] += dp[i][bit];
        if (validBit((bit << 1) + 1))
          dp[i + 1][((bit << 1) + 1) & ((1 << (k - 1)) - 1)] += dp[i][bit];
      }
      if (c == 'A') {
        if (validBit(bit << 1))
          dp[i + 1][(bit << 1) & ((1 << (k - 1)) - 1)] += dp[i][bit];
      }
      if (c == 'B') {
        if (validBit((bit << 1) + 1))
          dp[i + 1][((bit << 1) + 1) & ((1 << (k - 1)) - 1)] += dp[i][bit];
      }
    }
  }

  mint ans = 0;
  rep(bit, 1 << k) ans += dp[s.size()][bit];
  out(ans.val());
}
