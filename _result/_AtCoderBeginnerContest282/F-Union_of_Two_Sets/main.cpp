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

int n;
vector<pair<int, int>> lrs;
vector<vector<int>> mem(4001, vector<int>(4001, 0));

pair<int, int> calc(int il, int ir) {
  int l = 1;
  int r = n;
  int mid = (l + r) / 2;
  while (mid < il || mid > ir) {
    if (mid < il) {
      l = mid;
    } else {
      r = mid;
    }
    mid = (l + r) / 2;
  }
  return {mem[il][mid], mem[mid][ir]};
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;

  queue<pair<int, int>> que;
  que.push({1, n});
  while (!que.empty()) {
    auto lr = que.front();
    que.pop();

    int mid = (lr.first + lr.second) / 2;
    if (mid - lr.first > 1) que.push({lr.first, mid});
    if (lr.second - mid > 1) que.push({mid, lr.second});

    rep2(i, lr.first, mid) {
      if (mem[i][mid]) continue;
      lrs.push_back({i, mid});
      mem[i][mid] = lrs.size();
    }
    rep2(i, mid + 1, lr.second + 1) {
      if (mem[mid][i]) continue;
      lrs.push_back({mid, i});
      mem[mid][i] = lrs.size();
    }
  }
  rep2(i, 1, n + 1) {
    if (mem[i][i]) continue;
    lrs.push_back({i, i});
    mem[i][i] = lrs.size();
  }

  out(lrs.size());
  rep2(i, 0, lrs.size()) {
    auto lr = lrs[i];
    cout << lr.first << " " << lr.second << endl;
  }
  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    pair<int, int> lr;
    if (l != r) {
      lr = calc(l, r);
    } else {
      lr = {mem[l][l], mem[r][r]};
    }

    cout << lr.first << " " << lr.second << endl;
  }
}
