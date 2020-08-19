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

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>arr(n);
		vector<string>sarr(1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
		for (int i = 0; i < n; i++) {
			string s = "";
			cin >> arr[i];
			int j = 0;
			for (; j < arr[i]; j++) {
				s += sarr[i][j];
			}
			char ch;
			if (sarr[i][j] == 'a')ch = 'b';
			else ch = 'a';
			for (; j < 50; j++)s += ch;
			sarr.push_back(s);
		}
		for (int i = 0; i <= n; i++)cout << sarr[i] << '\n';

	}

	return 0;

}