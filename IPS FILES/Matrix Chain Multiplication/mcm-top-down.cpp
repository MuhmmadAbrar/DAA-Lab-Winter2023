#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int lookupChain(vector<vector<int> > &m, vector<int> &p, int i, int j) {
    if (m[i][j] < INT_MAX)
        return m[i][j];
    if (i == j)
        m[i][j] = 0;
    else {
        for (int k = i; k < j; k++) {
            int q = lookupChain(m, p, i, k) + lookupChain(m, p, k + 1, j) + p[i - 1] * p[k] * p[j];
            if (q < m[i][j])
                m[i][j] = q;
        }
    }
    return m[i][j];
}

void matrixChainOrder(vector<int> &p) {
    int n = p.size() - 1;
    vector<vector<int> > m(n + 1, vector<int>(n + 1, INT_MAX));
    cout << "Minimum number of multiplications is " << lookupChain(m, p, 1, n) << endl;
    cout << "Table: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> p = { 1, 2, 3, 4, 3 };
    matrixChainOrder(p);
    return 0;
}
