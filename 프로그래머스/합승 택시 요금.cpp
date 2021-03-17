#include <string>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

const int MAX = 300000000;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int ans = INF;

	vector<vector<int>>arr(n + 1, vector<int>(n + 1, MAX));
	for (int i = 1; i <= n; ++i)arr[i][i] = 0;

	for (int i = 0; i < fares.size(); ++i) {
		arr[fares[i][0]][fares[i][1]] = arr[fares[i][1]][fares[i][0]] = fares[i][2];
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j)continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		ans = min(ans, arr[s][i] + arr[i][a] + arr[i][b]);
	}

	return ans;
}