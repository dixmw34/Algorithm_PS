#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>>link(n);
    vector<int>visit(n, INF);

    for (int i = 0; i < edge.size(); i++) {
        link[edge[i][0] - 1].push_back(edge[i][1] - 1);
        link[edge[i][1] - 1].push_back(edge[i][0] - 1);
    }

    queue<int>q;
    q.push(0);
    visit[0] = 0;
    int mx = 0;

    while (!q.empty()) {
        int num = q.front(); q.pop();
        for (int i = 0; i < link[num].size(); i++) {
            int next = link[num][i];
            if (visit[next] == INF) {
                mx = max(mx, visit[num] + 1);
                visit[next] = visit[num] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (visit[i] == mx)answer++;
    }

    return answer;
}