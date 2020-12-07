#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, q;
int arr[N];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    while (q --) {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (arr[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (arr[l] != x) {
            cout << "-1 -1" << endl;
            continue;
        }
        int left = l;
        l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1>> 1;
            if (arr[mid] > x) r = mid - 1;
            else l = mid;
        }
        printf("%d %d\n", left, l);
    }
    return 0;
}