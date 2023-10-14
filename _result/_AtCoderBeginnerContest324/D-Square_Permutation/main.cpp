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

vector<int> mem1(10, 0);
bool judge(ll num, string s) {
  vector<int> mem(10, 0);
  int num1 = num;
  while (num) {
    mem[num % 10] += 1;
    num /= 10;
  }
  bool poss = true;
  if (mem[0] > mem1[0]) return false;
  rep2(i, 1, 10) {
    if (mem[i] != mem1[i]) poss = false;
  }
  return poss;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;
  for (auto c : s) {
    mem1[c - '0'] += 1;
  }

  int ans = 0;
  for (ll i = 0; i * i <= pow(10, n); i++) {
    if (judge(i * i, s)) ans++;
  }
  out(ans);
}
