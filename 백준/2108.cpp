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

	vector<int>arr;
	vector<pi>parr(8001);

	int n, sum = 0, a;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
		sum += a;
		parr[a+4000].first--;
		parr[a + 4000].second = a;
	}

	sort(arr.begin(), arr.end());
	sort(parr.begin(), parr.end());

	cout << (int)floor(((double)sum / (double)n) + 0.5) << '\n';
	cout << arr[n / 2] << '\n';

	if (parr[0].first == parr[1].first)cout << parr[1].second << '\n';
	else cout << parr[0].second << '\n';
	cout << arr[n - 1] - arr[0] << '\n';


	return 0;

}