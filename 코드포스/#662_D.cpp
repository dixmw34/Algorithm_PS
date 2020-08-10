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

const int MAX = 200000;

vector<vector<char>>arr;
vector<vector<ll>>dp1;
vector<vector<ll>>dp2;
vector<vector<ll>>dp3;
vector<vector<ll>>dp4;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	ll ans = 0;
	cin >> N >> M;
	arr = vector<vector<char>>(N + 2, vector<char>(M + 2, ' '));
	dp1 = vector<vector<ll>>(N + 2, vector<ll>(M + 2, 0));
	dp2 = vector<vector<ll>>(N + 2, vector<ll>(M + 2, 0));
	dp3 = vector<vector<ll>>(N + 2, vector<ll>(M + 2, 0));
	dp4 = vector<vector<ll>>(N + 2, vector<ll>(M + 2, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			dp1[i][j] = dp2[i][j] = dp3[i][j] = dp4[i][j] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1]) {
				dp1[i][j] = min(dp1[i - 1][j], dp1[i][j - 1]) + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= 1; j--) {
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j + 1]) {
				dp2[i][j] = min(dp2[i - 1][j], dp2[i][j + 1]) + 1;
			}
		}
	}
	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <=M; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j - 1]) {
				dp3[i][j] = min(dp3[i + 1][j], dp3[i][j - 1]) + 1;
			}
		}
	}
	for (int i = N; i >= 1; i--) {
		for (int j = M; j >= 1; j--) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j + 1]) {
				dp4[i][j] = min(dp4[i + 1][j], dp4[i][j + 1]) + 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ans += min(min(dp1[i][j], dp2[i][j]), min(dp3[i][j], dp4[i][j]));
		}
	}

	cout << ans << '\n';

	return 0;


}