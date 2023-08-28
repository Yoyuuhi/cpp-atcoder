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

vector<vector<int>> mem;
vector<bool> passed;
vector<int> memNode;
void dfs(int now) {
  if (!passed[now]) {
    memNode.push_back(now);
    passed[now] = true;
  }
  for (auto next : mem[now]) dfs(next);
}

struct editDsu {
 public:
  editDsu() : _n(0) {}
  explicit editDsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (x > y) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int>& v) { return v.empty(); }),
        result.end());
    return result;
  }

 private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
};

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<pair<int, int>> pqs(n - 1);
  rep(i, n - 1) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    pqs[i] = {p, q};
  }

  editDsu d(n);
  mem.resize(n);
  passed.resize(n, false);
  rep(i, n - 1) {
    int lp = d.leader(pqs[i].first);
    int lq = d.leader(pqs[i].second);
    if (lp > lq) swap(lp, lq);
    mem[lp].push_back(lq);
    d.merge(lp, lq);
  }
  dfs(0);

  vector<int> memPos(n);
  rep(i, n) memPos[memNode[i]] = i;
  d = editDsu(n);
  vector<mint> ans(n + 1, 0);
  rep(i, n - 1) {
    int lp = d.leader(memPos[pqs[i].first]);
    int lq = d.leader(memPos[pqs[i].second]);
    ans[lp] += d.size(lp) / mint(d.size(lp) + d.size(lq));
    ans[lp + d.size(lp)] -= d.size(lp) / mint(d.size(lp) + d.size(lq));
    ans[lq] += d.size(lq) / mint(d.size(lp) + d.size(lq));
    ans[lq + d.size(lq)] -= d.size(lq) / mint(d.size(lp) + d.size(lq));
    d.merge(lp, lq);
  }
  rep(i, n) ans[i + 1] += ans[i];

  rep(i, n) cout << ans[memPos[i]].val() << ' ';
  cout << endl;
}
