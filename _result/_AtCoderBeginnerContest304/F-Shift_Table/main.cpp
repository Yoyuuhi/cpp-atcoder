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

vector<int> divisor(int n) {
  vector<int> ret;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n && i != 1) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());  // 昇順に並べる
  return ret;
}

map<int, mint> as;
map<int, bool> mem;
mint calc(int num) {
  if (mem[num]) return as[num];
  for (int i = 1; i * i <= num; i++) {
    if (num % i == 0) {
      as[num] -= calc(i);
      if (i * i != num && i != 1) as[num] -= calc(num / i);
    }
  }
  mem[num] = true;
  return as[num];
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  string s;
  cin >> n >> s;

  vector<int> fs = divisor(n);
  for (auto f : fs) {
    mint a = 1;
    rep(i, f) {
      bool isWork = true;
      for (int j = 0; i + j * f < n; j++) {
        int idx = i + j * f;
        if (s[idx] == '.') isWork = false;
      }
      if (isWork) a *= 2;
    }
    as[f] = a;
    mem[f] = false;
  }
  mem[1] = true;

  mint ans = 0;
  for (auto f : fs) {
    ans += calc(f);
  }
  out(ans.val());
}
