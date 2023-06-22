// https://algo-logic.info/topological-sort/
#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;
/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
 */
vector<int> topo_sort(const Graph &G) {  // bfs
  vector<int> ans;
  int n = (int)G.size();
  vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
  for (int i = 0; i < n; i++) {  // 次数を数えておく
    for (auto e : G[i]) {
      ind[e.to]++;
    }
  }
  queue<int> que;
  for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
    if (ind[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {  // 幅優先探索
    int now = que.front();
    ans.push_back(now);
    que.pop();
    for (auto e : G[now]) {
      ind[e.to]--;
      if (ind[e.to] == 0) {
        que.push(e.to);
      }
    }
  }
  return ans;
}