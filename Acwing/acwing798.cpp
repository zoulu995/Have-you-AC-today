#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int b[N][N];
int sum[N][N];
int n, m, k;
int x1, x2, y3, y2, c;

void insert(int x1, int y3, int x2, int y2, int c) {
    b[x1][y3] += c, b[x1][y2 + 1] -= c, b[x2 + 1][y3] -= c, b[x2 + 1][y2 + 1] += c;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            int x;
            cin >> x;
            insert(i, j, i, j, x);
        }
    while (k --) {
        cin >> x1 >> y3 >> x2 >> y2 >> c;
        insert(x1, y3, x2, y2, c);
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i-1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + b[i][j];
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
        
    return 0;
}