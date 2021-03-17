#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {

	map<string, int>map;
	for (char ch = 'A'; ch <= 'Z'; ++ch) {
		string a(1, ch);
		map[a] = map.size() + 1;
	}
	vector<int> answer;

	while (msg.size()) {
		for (int i = msg.size(); i >= 1; --i) {
			if (answer.size() == 10) {
			}
			if (map.find(msg.substr(0, i)) != map.end()) {
				answer.push_back(map[msg.substr(0, i)]);
				if (i != msg.size()) {
					map[msg.substr(0, i + 1)] = map.size() + 1;
					msg = msg.substr(i, msg.size() - i);
					break;
				}
				else
					return answer;
			}
		}
	}
	return answer;
}