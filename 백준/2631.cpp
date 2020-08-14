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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int>arr;
	vector<int>ans;
	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		if (ans.empty() || ans.back() < arr[i])ans.push_back(arr[i]);
		else {
			int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[idx] = arr[i];
		}
	}

	cout << N - ans.size() << '\n';
	


	return 0;
	

}