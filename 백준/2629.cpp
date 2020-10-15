#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <unordered_map>
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

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

const int Max = 15000;
bool dp[15001];


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		for (int i = Max; i - x >= 0; --i) {
			if (dp[i - x])dp[i] = true;
		}
	}
	cin >> n;
	while (n--) {
		cin >> x;
		if (x > Max) {
			cout << "N ";
			continue;
		}
		bool flag = false;
		if (dp[x])flag = true;
		for (int i = 0; 2 * i + x <= Max; ++i) {
			if (dp[i] && dp[i + x] && dp[2 * i + x])flag = true;
		}
		if (flag)cout << "Y ";
		else cout << "N ";
	}
	cout << '\n';

	

	return 0;

}