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

int h, w;
char arr[20][20];

vector<vector<pi>>block = { {pi(0, 0), pi(0, 1), pi(1, 0)},{pi(0, 0), pi(0, 1), pi(1, 1)},{pi(0, 0), pi(1, 0), pi(1, 1)},{pi(0, 0), pi(1, 0), pi(1, -1)} };

int dfs(int num) {
	
	while (num < h*w) {
		int x = num / w, y = num % w;
		if (arr[x][y] == '.') {
			int ans = 0;
			for (int i = 0; i < 4; ++i) {
				if (x + block[i][1].first < h && x + block[i][2].first < h && y + block[i][1].second >= 0 && y + block[i][1].second < w && y + block[i][2].second >= 0 && y + block[i][2].second < w && arr[x + block[i][1].first][y + block[i][1].second] == '.' && arr[x + block[i][2].first][y + block[i][2].second] == '.') {
					arr[x][y] = arr[x + block[i][1].first][y + block[i][1].second] = arr[x + block[i][2].first][y + block[i][2].second] = '#';
					ans += dfs(num + 1);
					arr[x][y] = arr[x + block[i][1].first][y + block[i][1].second] = arr[x + block[i][2].first][y + block[i][2].second] = '.';
				}
			}
			return ans;
		}
		num++;
	}

	if (num == h * w)return 1;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> h >> w;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> arr[i][j];
			}
		}

		cout << dfs(0) << '\n';
	}

	return 0;

}