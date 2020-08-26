#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool>visit(n, false);

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            answer++;
            visit[i] = true;
            queue<int>q;
            q.push(i);
            while (!q.empty()) {
                int num = q.front(); q.pop();
                for (int i = 0; i < n; i++) {
                    if (computers[num][i] && !visit[i]) {
                        visit[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }


    return answer;
}