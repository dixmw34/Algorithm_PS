#include <string>
#include <vector>

using namespace std;

vector<string>month = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
vector<int>day = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

string solution(int a, int b) {

    int num = 4;

    for (int i = 0; i < a; i++)num += day[i];

    num += b;

    return month[num % 7];

}