#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n;
int arr[N];
stack<int> stk;

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        while (stk.size() && arr[stk.top()] >= arr[i]) stk.pop();
        if (stk.empty()) cout << "-1 ";
        else cout << arr[stk.top()] << " ";
        stk.push(i);
    }
    
    
    return 0;
}