#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> cut(string s) {
    vector <string>r;
    string a = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (a.size() > 0)r.push_back(a);
            a = "";
        }
        else a += s[i];
    }
    if (a.size() > 0)r.push_back(a);
    return r;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>>arr(record.size());
    map<string, string>m;

    for (int i = 0; i < record.size(); i++) {
        arr[i] = cut(record[i]);
        if (arr[i][0] != "Leave")m[arr[i][1]] = arr[i][2];
    }
    for (int i = 0; i < record.size(); i++) {
        if (arr[i][0] == "Enter") {
            answer.push_back(m[arr[i][1]] + "님이 들어왔습니다.");
        }
        else if (arr[i][0] == "Leave") {
            answer.push_back(m[arr[i][1]] + "님이 나갔습니다.");
        }
    }

    return answer;
}