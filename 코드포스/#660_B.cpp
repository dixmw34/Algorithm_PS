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

const int MAX = 1000001;
const int MOD = 1000000007;

vector<vector<pi>>road;
vector<vector<pi>>back;
vector<int>inDegree;
vector<int>outDegree;
vector<int>time;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, num, ans = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		vector<int>arr(n);
		for (int i = 0; i < n; i++)cin >> arr[i];
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		}
		sort(arr.begin(), arr.end());
		int start = arr[0] + arr[1];
		int end = arr[n - 2] + arr[n - 1];

		for (int i = start; i <= end; i++) {
			num = 0;
			int left = 0, right = n - 1;
			
			while (left < right) {
				if (arr[left] + arr[right] == i) {
					num++;
					left++;
					right--;
				}
				else if (arr[left] + arr[right] > i)right--;
				else left++;
			}

			ans = max(ans, num);
		}

		cout << ans << '\n';

		arr.clear();
	}



	return 0;


}