#include <bits/stdc++.h>
using namespace std;

string input1, input2;

string add(string& a, string& b) {
    string ans;
    vector<int> A, B, C;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    int t = 0, t1, t2;
    for (int i = 0; i < max(A.size(), B.size()) || t; i ++) {
        if (i < A.size()) t1 = A[i];
        else t1 = 0;
        if (i < B.size()) t2 = B[i];
        else t2 = 0;
        //printf("%d %d %d\n", t1, t2, t);
        C.push_back((t1 + t2 + t) % 10);
        t = (t1 + t2 + t) / 10;
        
    }
    for (int i = C.size() - 1; i >= 0; i --) {
        ans += to_string(C[i]);
    }
    return ans;

}

int main() {
    cin >> input1 >> input2;
    cout << add(input1, input2);
    return 0;
}