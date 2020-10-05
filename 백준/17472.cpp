#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <string.h>
#include <iomanip>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

struct Bri
{
	int start;
	int end;
	int l;
};

int arr[100][100], len[100][100], par[10];
vector< queue<pi>>land;
vector<Bri>bridge;
int N, M, color = 0;

void make_color(int a, int b) {
	queue<pi>q;
	q.push(pi(a, b));
	land.push_back(queue<pi>());
	par[color] = color;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		land.back().push(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M && arr[x + dx[i]][y + dy[i]] == -1) {
				arr[x + dx[i]][y + dy[i]] = arr[x][y];
				q.push(pi(x + dx[i], y + dy[i]));
			}
		}
	}
}

int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}

bool cmp(Bri a, Bri b) {
	return a.l < b.l;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			arr[i][j] = -arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == -1) {
				arr[i][j] = ++color;
				make_color(i, j);
			}
		}
	}

	for (int i = 1; i <= color; ++i) {
		for (int j = 0; j < 4; ++j) {
			queue<pi>q = land[i-1];
			memset(len, -1, sizeof(len));
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second; q.pop();
				if (len[x][y] == -1)len[x][y] = 0;
				if (x + dx[j] >= 0 && x + dx[j] < N && y + dy[j] >= 0 && y + dy[j]<M && (len[x + dx[j]][y + dy[j]]>len[x][y] + 1||len[x + dx[j]][y + dy[j]] == -1)) {
					if (arr[x + dx[j]][y + dy[j]] == 0) {
						q.push(pi(x + dx[j], y + dy[j]));
						len[x + dx[j]][y + dy[j]] = len[x][y] + 1;
					}
					else if (arr[x + dx[j]][y + dy[j]] != i) {
						len[x + dx[j]][y + dy[j]] = len[x][y] + 1;
						bridge.push_back(Bri{ i, arr[x + dx[j]][y + dy[j]] , len[x][y]});
					}
				}
			}
		}
	}

	sort(bridge.begin(), bridge.end(), cmp);

	int ans = 0, cnt = 0;
	for (int i = 0; i < bridge.size(); ++i) {
		if (bridge[i].l <= 1)continue;
		int a = find(bridge[i].start), b = find(bridge[i].end);
		if (a != b) {
			par[a] = par[b] = min(a, b);
			++cnt;
			ans += bridge[i].l;
		}
	}

	if (cnt == color - 1)cout << ans << '\n';
	else cout << -1 << '\n';

	return 0;

}