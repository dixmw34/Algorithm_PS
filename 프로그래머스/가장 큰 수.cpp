#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    int na = atoi((a + b).c_str());
    int nb = atoi((b + a).c_str());

    if (na > nb)return true;
    else if (na < nb)return false;
    else return a.size() < b.size();
}

string solution(vector<int> numbers) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    string result = "";

    int n = numbers.size();

    vector<string>a(numbers.size());

    for (int i = 0; i < n; i++) {
        a[i] = to_string(numbers[i]);
    }

    sort(a.begin(), a.end(), cmp);

    if (a[0][0] == '0')return "0";

    for (int i = 0; i < n; i++) {
        result += a[i];
    }

    return result;
}