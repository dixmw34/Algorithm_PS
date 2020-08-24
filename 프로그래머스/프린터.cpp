#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	vector<vector<int>>arr(10);
	int n = priorities.size(), idx = -1;
	for (int i = 0; i < n; i++) {
		arr[priorities[i]].push_back(i);
	}

	for (int i = 9; i >= 1; i--) {
		if (priorities[location] == i) {
			int num = -1;
			for (int j = 0; j < arr[i].size(); j++) {
				if (arr[i][j] > idx) {
					num = j;
					break;
				}
			}
			if (num == -1)idx = 0;
			else idx = num;
			while (1) {
				if (arr[i][idx] == location) {
					return answer + 1;
				}
				else {
					idx++;
					answer++;
					if (idx == arr[i].size())idx = 0;
				}
			}
		}
		else if(arr[i].size()){
			answer += arr[i].size();
			int num = -1;
			for (int j = 0; j < arr[i].size(); j++) {
				if (arr[i][j] < idx)num = arr[i][j];
				else break;
			}
			if (num == -1)idx = arr[i][arr[i].size() - 1];
			else idx = num;
		}
	}


	return answer;
}