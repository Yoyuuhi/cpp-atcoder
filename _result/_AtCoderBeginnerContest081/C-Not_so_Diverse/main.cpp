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
  vector<int> mem(n, 0);
  rep(i, n) {
    int a;
    cin >> a;
    mem[a - 1]++;
  }

  sort(all(mem));
  int count = 0;
  for (auto m : mem)
    if (m) count++;
  int ans = 0;
  rep(i, n) {
    if (count <= k) {
      out(ans);
      return 0;
    }
    ans += mem[i];
    if (mem[i]) count--;
  }
}
