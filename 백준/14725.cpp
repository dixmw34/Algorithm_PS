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

bool cmp(vector<string>a, vector<string>b) {
	for (int i = 0; i < min(a.size(), b.size()); ++i) {
		if (a[i] < b[i])return true;
		else if (a[i] > b[i])return false;
	}
	return a.size() < b.size();
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	cin >> n;
	vector<vector<string>>arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> m;
		vector<string>a(m);
		for (int j = 0; j < m; ++j) {
			cin >> a[j];
		}
		arr[i] = a;
		a.clear();
	}

	sort(arr.begin(), arr.end());

	for (int j = 0; j < arr[0].size(); ++j) {
		int num = j * 2;
		while (num--)cout << '-';
		cout << arr[0][j] << '\n';
	}

	for (int i = 1; i < arr.size(); ++i) {
		int j = 0;
		for (; j < min(arr[i].size(), arr[i - 1].size()); ++j) {
			if (arr[i][j] != arr[i-1][j])break;
		}
		for (; j < arr[i].size(); ++j) {
			int num = j * 2;
			while (num--)cout << '-';
			cout << arr[i][j] << '\n';
		}
	}

	return 0;

}