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

bool isPalindrome(const string& str, int start, int end) {
  while (start < end) {
    if (str[start] != str[end]) {
      return false;
    }
    ++start;
    --end;
  }
  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  map<string, bool> mem;
  vector<int> vs;
  rep(i, n) vs.push_back(i);
  do {
    string ss = "";
    for (auto v : vs) ss += s[v];
    mem[ss] = true;
    // outs(vs);
  } while (next_permutation(all(vs)));

  ll ans = 0;
  for (auto ss : mem) {
    auto str = ss.first;
    bool inc = false;
    rep(i, n - k + 1) {
      if (isPalindrome(str, i, i + k - 1)) {
        inc = true;
        break;
      }
    }
    if (!inc) ans++;
  }
  out(ans);
}
