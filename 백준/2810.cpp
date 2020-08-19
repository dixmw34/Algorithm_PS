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

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	string s;
	string result = "*";

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'S') {
			result += "S*";
		}
		else {
			i++;
			result += "LL*";
		}
	}

	int ans = 0;

	for (int i = 0; i < result.size(); i++) {
		if (result[i] == 'S' || result[i] == 'L') {
			if (result[i - 1] == '*') {
				ans++;
				result[i - 1] = ' ';
			}
			else if (result[i + 1] == '*') {
				ans++;
				result[i + 1] = ' ';
			}
		}
		
	}

	cout << ans << '\n';

	return 0;

}