#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
	
	map<string, int>all, temp;

	int n = gems.size();
	vector<int> answer = { 1, n };
	int Max = n;

	for (int i = 0; i < n; ++i) {
		all[gems[i]]++;
	}

	int last = 0;
	for (int i = 0; i < n; ++i) {
		temp[gems[i]]++;
		while (temp.size() == all.size()) {
			if (Max > i - last + 1) {
				Max = i - last + 1;
				answer = { last + 1, i + 1 };
			}
			if (last != i) {
				if (--temp[gems[last]] == 0) {
					temp.erase(gems[last]);
				}
				last++;
			}
            else
                break;
		}
	}

	return answer;
}