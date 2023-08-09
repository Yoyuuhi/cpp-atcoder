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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  vector<int> mem(n);
  vector<int> xs;
  xs.push_back(1);
  rep2(i, n - k + 2, n + 1) xs.push_back(i);

  vector<int> as(n, -1);
  as[0] = 0;
  rep(i, n - k + 1) {
    cout << '?';
    xs[0] = i + 1;
    for (auto x : xs) cout << ' ' << x;
    cout << endl;
    cin >> mem[i];
    as[i] = 0;
    if (mem[i] != mem[0]) as[i] = 1;
  }

  rep(i, k - 1) {
    xs.resize(0);
    xs.push_back(1);
    xs.push_back(2);
    rep2(j, n - k + 2, n + 1) {
      if (j == n - k + 2 + i) continue;
      xs.push_back(j);
    }
    cout << '?';
    for (auto x : xs) cout << ' ' << x;
    cout << endl;
    cin >> mem[n - k + 1 + i];
    as[n - k + 1 + i] = (mem[n - k + 1 + i] + mem[1]) % 2;
  }

  int sum = 0;
  rep2(i, n - k, n) sum += as[i];
  bool reverse = (sum % 2 != mem[n - k]);
  cout << '!';
  rep(i, n) {
    if (reverse) as[i] = (as[i] + 1) % 2;
    cout << ' ' << as[i];
  }
  cout << endl;
}
