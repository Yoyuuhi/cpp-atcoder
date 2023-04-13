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
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  scc_graph graph(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(a, b);
  }
  std::vector<std::vector<int>> ans = graph.scc();
  out(ans.size());
  for (auto as : ans) {
    reverse(all(as));
    cout << as.size();
    for (auto a : as) {
      cout << " " << a;
    }
    cout << endl;
  }
}
