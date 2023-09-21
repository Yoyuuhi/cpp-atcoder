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

bool poss10(int num) {
  while (num) {
    if (num % 10 == 7) return false;
    num /= 10;
  }
  return true;
}
bool poss8(int num) {
  while (num) {
    if (num % 8 == 7) return false;
    num /= 8;
  }
  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  int ans = 0;
  rep2(i, 1, n + 1) {
    if (poss10(i) && poss8(i)) ans++;
  }
  out(ans);
}
