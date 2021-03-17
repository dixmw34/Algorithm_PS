#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;
int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	
	vector<int>ans(2, 0);
	vector<vector<bool>>v(m, vector<bool>(n, false));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!v[i][j] && picture[i][j]) {
				v[i][j] = true;
				int cnt = 1;
				queue<pi>q;
				q.push(pi(i, j));
				while (!q.empty()) {
					pi p = q.front(); q.pop();
					for (int k = 0; k < 4; ++k) {
						int x = p.first + dx[k], y = p.second + dy[k];
						if (x >= 0 && x < m && y >= 0 && y < n && picture[p.first][p.second] == picture[x][y] && !v[x][y]) {
							v[x][y] = true;
							cnt++;
							q.push(pi(x, y));
						}
					}
				}
				ans[0]++;
				ans[1] = max(ans[1], cnt);
			}
		}
	}

	return ans;
}