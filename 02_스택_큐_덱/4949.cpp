#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s, buff;
    vector<string> str, answer;
    stack<char> st; // 문자열을 처리하는 스택

    getline(cin, s);
    while (s.compare(".")) {
        str.push_back(s);
        getline(cin, s);
    }

    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str[i].length(); j++) {
            if (str[i][j] == '(' || str[i][j] == '[')
                st.push(str[i][j]);
            else if (str[i][j] == ')' || str[i][j] == ']') {
                if (st.empty()) {
                    answer.push_back("no");
                    break;
                }
                char top = st.top();
                st.pop();
                if ((str[i][j] == ')' && top != '(') || (str[i][j] == ']' && top != '[')) {
                    answer.push_back("no");
                    break;
                }
                if (j == str[i].length()-1 && st.empty()) {
                    answer.push_back("yes");
                }
            }
        }
        while (!st.empty()) st.pop(); // 각 라인 처리 후 스택 비우기
    }

    // 벡터에 저장된 문자열 출력
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
