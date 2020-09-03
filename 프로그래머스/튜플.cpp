#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>>arr;
    vector<int>v;
    int num = 0;

    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == ',') {
            if (num) {
                v.push_back(num);
                num = 0;
            }
        }
        else if (s[i] == '}') {
            v.push_back(num);
            arr.push_back(v);
            v.clear();
            num = 0;
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            num *= 10;
            num += s[i] - '0';
        }
    }

    sort(arr.begin(), arr.end(), cmp);

    answer.push_back(arr[0][0]);
    for (int i = 1; i < arr.size(); i++) {
        sort(arr[i].begin(), arr[i].end());
        for (int j = 0; j < arr[i - 1].size(); j++) {
            if (arr[i - 1][j] != arr[i][j]) {
                answer.push_back(arr[i][j]);
                break;
            }
        }
        if (answer.size() == i)answer.push_back(arr[i][i]);
    }

    return answer;
}