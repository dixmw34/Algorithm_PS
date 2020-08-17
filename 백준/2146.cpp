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

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

int arr[100][100];
int time[100][100];
queue<pi>land;
int N, color = 2;

void make_color(int a, int b) {
	queue<pi>q;
	q.push(pi(a, b));

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		land.push(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N && arr[x + dx[i]][y + dy[i]] == 1) {
				arr[x + dx[i]][y + dy[i]] = arr[x][y];
				q.push(pi(x + dx[i], y + dy[i]));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int ans = INF;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = color++;
				make_color(i, j);
			}
		}
	}

	while (!land.empty()) {
		int x = land.front().first, y = land.front().second;
		land.pop();
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N) {
				if (arr[x + dx[i]][y + dy[i]] == 0) {
					arr[x + dx[i]][y + dy[i]] = arr[x][y];
					time[x + dx[i]][y + dy[i]] = time[x][y] + 1;
					land.push(pi(x + dx[i], y + dy[i]));
				}
				else if (arr[x + dx[i]][y + dy[i]] != arr[x][y]) {
					ans = min(ans, time[x + dx[i]][y + dy[i]] + time[x][y]);
				}
				
			}
		}
	}

	cout << ans << '\n';

	return 0;
	

}