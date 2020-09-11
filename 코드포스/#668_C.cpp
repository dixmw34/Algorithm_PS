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

int n, k;
string s;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cin >> s;
		vector<char>a(k, ' ');
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (s[i] == '?')continue;
			else if (s[i] == '1') {
				if (a[i%k] == ' ') {
					a[i%k] = s[i];
				}
				else if (a[i%k] != s[i]) {
					flag = false;
					break;
				}
			}
			else if (s[i] == '0') {
				if (a[i%k] == ' ') {
					a[i%k] = s[i];
				}
				else if (a[i%k] != s[i]) {
					flag = false;
					break;
				}
			}
		}
		int num = 0, unknown = 0;
		for (int i = 0; i < k; i++) {
			if (a[i] == '1')num++;
			else if (a[i] == '0')num--;
			else unknown++;
		}
		if (abs(num) > unknown)flag = false;
		if (flag)cout << "YES\n";
		else cout << "NO\n";

	}



	return 0;

}