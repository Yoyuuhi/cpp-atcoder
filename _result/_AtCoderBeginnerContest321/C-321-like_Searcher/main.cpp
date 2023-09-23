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

vector<ll> sel;
vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
void dfs(int idx, ll num) {
  if (idx == 10) {
    sel.push_back(num);
    return;
  }
  dfs(idx + 1, num);
  dfs(idx + 1, num * 10 + nums[idx]);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int k;
  cin >> k;

  dfs(0, 0);
  sort(all(sel));
  out(sel[k + 1]);
}
