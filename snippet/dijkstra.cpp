#include <bits/stdc++.h>
#include <alias.hpp>
#include <queue>

using namespace std;
/**
 * @brief Dijkstra in const map which can only move up, down, left, right
 * 
 * @param source 
 * @param sink 
 * @param map cost map
 * @return int shortest cost
 */
int 
dijkstra(PII source, PII sink, const vector<vector<int>> &map, const vector<PII> &dir)
{
    if (map.empty()) return -1;
    vector<vector<int>> memo (map.size(), vector<int>(map[0].size(), INT_MAX));
    auto cmp = [&](const PII &lhs, const PII &rhs) { 
        return memo[lhs.fi][lhs.se] > memo[rhs.fi][rhs.se];
    };
    priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
    pq.push(source);
    memo[source.fi][source.se] = map[source.fi][source.se];
    while (!pq.empty()) {
        PII cur = pq.top();
        pq.pop();
        for (auto d : dir) {
            PII next = {cur.fi + d.fi, cur.se + d.se};
            if (next.fi < 0 || next.fi >= map.size() || next.se < 0 || next.se >= map[0].size()) 
                continue;
            if (memo[next.fi][next.se] != INT_MAX) {
                continue;
            }
            memo[next.fi][next.se] = memo[cur.fi][cur.se] + map[next.fi][next.se];
            if (next == sink) {
                return memo[next.fi][next.se];
            }
            pq.push({next.fi, next.se});
        }
    }
    return -1;
}
