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

	int t, n, num;

	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>arr(n);
		for (int i = 0; i < n; i++)cin >> arr[i];
		sort(arr.begin(), arr.end());
		if (n == 1) {
			cout << "YES\n";
			continue;
		}
		bool check = true;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i + 1] - arr[i] > 1) {
				check = false;
				break;
			}
		}
		if(check)cout << "YES\n";
		else cout << "NO\n";
		
	}



	return 0;


}