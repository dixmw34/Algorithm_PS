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

ui signal(ui num) {
	return num * 214013 + 2531011;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int k, n, sum = 0, ans = 0;
		cin >> k >> n;
		ui seed = 1983;
		queue<int>q;
		for (int i = 0; i < n; ++i) {
			if (i != 0)seed = signal(seed);
			sum += (seed % 10000 + 1);
			q.push(seed % 10000 + 1);
			while (!q.empty() && sum > k) {
				sum -= q.front();
				q.pop();
			}
			if (sum == k)ans++;
		}
		cout << ans << '\n';
	}
	

	return 0;

}