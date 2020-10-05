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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

vector<bool>light(100000, true);
char a[100000];
int n;

int sol() {
	int result = 0;
	vector<bool>test = light;
	for (int i = 0; i < n - 1; ++i) {
		if (!test[i]) {
			test[i] = !test[i];
			test[i+1] = !test[i+1];
			if(i+2<n)test[i+2] = !test[i+2];
			++result;
		}
	}
	if (test[n - 1])return result;
	else return INF;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	char ch;
	for (int i = 0; i < n; ++i) {
		cin >> ch;
		if (ch != a[i])light[i] = false;
	}

	int ans = INF;

	ans = min(ans, sol());
	light[0] = !light[0];
	light[1] = !light[1];
	ans = min(ans, sol() + 1);

	if (ans == INF)cout << -1 << '\n';
	else cout << ans << '\n';


	return 0;

}