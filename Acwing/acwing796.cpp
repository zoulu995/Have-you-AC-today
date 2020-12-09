#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N];
int sum[N][N];
int n, m, q;

int main() {
    //std::ios::sync_with_stdio(false);
    //cin >> n >> m >> q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            //cin >> a[i][j];
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            //cout << sum[i][j] << " ";
        }
        //cout << endl;
    }
    while (q --) {
        int x1, y1, x2, y2;
        //cin >> x1 >> y1 >> x2 >> y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        //cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << endl;
        printf("%d\n", sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]);
    }
    return 0;
}