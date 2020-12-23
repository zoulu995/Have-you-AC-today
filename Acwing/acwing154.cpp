#include <bits/stdc++.h>
using namespace std;

const int N = 300010;
deque<int> q;
int n, k;
int arr[N];


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    for (int i = 0; i < n; i ++) {
        while (q.size() && i - q.front() >= k) q.pop_front();
        while (q.size() && arr[q.back()] >= arr[i]) q.pop_back();
        q.push_back(i);
        if (i - k >= -1)
            cout << arr[q.front()] << " ";
        
    }
    cout << endl;
    
    for (int i = 0; i < n; i ++) {
        while (q.size() && i - q.front() >= k) q.pop_front();
        while (q.size() && arr[q.back()] <= arr[i]) q.pop_back();
        q.push_back(i);
        if (i - k + 1 >= 0)
            cout << arr[q.front()] << " ";
    }
    return 0;
}