#include <bits/stdc++.h>
using namespace std;

string str1, str2;

bool check(string str1, string str2) {
    if (str1.size() > str2.size()) return true;
    else if (str1.size() < str2.size()) return false;
    else {
        for (int i = 0; i < str1.size(); i ++) {
            if (str1[i] > str2[i]) return true;
            else if (str1[i] < str2[i]) return false;
        }
    }
    return true;
}

string div(string str1, string str2) {
    vector<int> a, b, c;
    for (int i = str1.size() - 1; i >= 0; i --) a.push_back(str1[i] - '0');
    for (int i = str2.size() - 1; i >= 0; i --) b.push_back(str2[i] - '0');
    int t = 0, temp1 = 0, temp2 = 0;
    for (int i = 0; i < a.size(); i ++) {
        if (i >= b.size()) temp2 = 0;
        else temp2 = b[i];
        temp1 = a[i];
        //printf("temp1 = %d, temp2 = %d, t = %d\n", temp1, temp2, t);
        c.push_back((temp1 - temp2 - t + 10) % 10);
        t = (temp1 - temp2 - t) >= 0 ? 0 : 1;
    }
    while (c.size() >= 2 && c.back() == 0) c.pop_back();
    string ans;
    for (int i = c.size() - 1; i >= 0; i --) ans += to_string(c[i]);
    return ans;
}

int main() {
    cin >> str1 >> str2;
    if (check(str1, str2)) cout << div(str1, str2);
    else cout << "-" << div(str2, str1);
    return 0;
}