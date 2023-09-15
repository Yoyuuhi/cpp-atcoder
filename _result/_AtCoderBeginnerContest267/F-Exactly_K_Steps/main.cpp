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
vector<vector<int>> g(200001);
int q;
int l1, l2;

pair<int, int> tdist;

vector<bool> seen;
void dfs(vector<vector<int>> &G, int v, int dis) {
  if (dis > tdist.first) tdist = {dis, v};
  seen[v] = true;
  for (auto next : G[v]) {
    if (!seen[next]) {
      dfs(G, next, dis + 1);
    }
  }
}

vector<int> nodeNum1(200001), nodeNum2(200001);
vector<int> numNode1(200001), numNode2(200001);
vector<vector<int>> levelNum1(200001), levelNum2(200001);
vector<int> numLevel1(200001), numLevel2(200001);

int numCount;
void assignNum(vector<int> &nodeNum, vector<int> &numNode,
               vector<vector<int>> &levelNum, vector<int> &numLevel, int v,
               int level) {
  seen[v] = true;
  for (auto next : g[v]) {
    if (!seen[next]) {
      assignNum(nodeNum, numNode, levelNum, numLevel, next, level + 1);
    }
  }
  nodeNum[v] = numCount;
  numNode[numCount] = v;
  levelNum[level].push_back(numCount);
  numLevel[numCount] = level;
  numCount++;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  tdist = {0, 0};
  seen.assign(n, false);
  dfs(g, 0, 0);
  tdist.first = 0;
  l1 = tdist.second;

  seen.assign(n, false);
  dfs(g, tdist.second, 0);
  l2 = tdist.second;

  seen.assign(n, false);
  numCount = 0;
  assignNum(nodeNum1, numNode1, levelNum1, numLevel1, l1, 0);
  seen.assign(n, false);
  numCount = 0;
  assignNum(nodeNum2, numNode2, levelNum2, numLevel2, l2, 0);

  cin >> q;
  rep(i, q) {
    int u, k;
    cin >> u >> k;
    u--;
    int num1 = nodeNum1[u];
    int num2 = nodeNum2[u];
    if (numLevel1[num1] >= k) {
      int level = numLevel1[num1] - k;
      int idx =
          lower_bound(all(levelNum1[level]), num1) - levelNum1[level].begin();
      out(numNode1[levelNum1[level][idx]] + 1);
      continue;
    }
    if (numLevel2[num2] >= k) {
      int level = numLevel2[num2] - k;
      int idx =
          lower_bound(all(levelNum2[level]), num2) - levelNum2[level].begin();
      out(numNode2[levelNum2[level][idx]] + 1);
      continue;
    }
    out(-1);
  }
}
