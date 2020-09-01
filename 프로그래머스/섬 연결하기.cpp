#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;

vector<int>par;

int find(int x) {
    if (par[x] == x)return x;
    else return par[x] = find(par[x]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    par = vector<int>(n);
    for (int i = 0; i < n; i++)par[i] = i;

    priority_queue<ppi>pq;
    for (int i = 0; i < costs.size(); i++) {
        pq.push(ppi(-costs[i][2], pi(costs[i][0], costs[i][1])));
    }

    while (!pq.empty()) {
        int x = pq.top().second.first, y = pq.top().second.second, cost = -pq.top().first; pq.pop();
        x = find(x), y = find(y);
        if (x != y) {
            par[x] = par[y] = min(x, y);
            answer += cost;
        }
    }

    return answer;
}