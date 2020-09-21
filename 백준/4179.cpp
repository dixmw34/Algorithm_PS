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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int r, c;
	cin >> r >> c;
	vector<vector<char>>arr(r + 2, vector<char>(c + 2, '!'));
	queue<pi>man, fire;

	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J')man.push(pi(i, j));
			else if (arr[i][j] == 'F')fire.push(pi(i, j));
		}
	}

	int time = 1;
	while (!man.empty()) {
		int n = man.size();
		for (int k = 0; k < n; ++k) {
			int x = man.front().first, y = man.front().second; man.pop();
			if (arr[x][y] == 'F')continue;
			for (int i = 0; i < 4; ++i) {
				if (arr[x + dx[i]][y + dy[i]] == '.') {
					arr[x + dx[i]][y + dy[i]] = 'J';
					man.push(pi(x + dx[i], y + dy[i]));
				}
				else if (arr[x + dx[i]][y + dy[i]] == '!') {
					cout << time << '\n';
					return 0;
				}
			}
		}

		n = fire.size();
		for (int k = 0; k < n; ++k) {
			int x = fire.front().first, y = fire.front().second; fire.pop();
			for (int i = 0; i < 4; ++i) {
				if (arr[x + dx[i]][y + dy[i]] == '.' || arr[x + dx[i]][y + dy[i]] == 'J') {
					arr[x + dx[i]][y + dy[i]] = 'F';
					fire.push(pi(x + dx[i], y + dy[i]));
				}
			}
		}
		time++;
	}

	cout << "IMPOSSIBLE\n";
	return 0;

}