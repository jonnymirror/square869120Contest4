#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(int, char**) {
    int n, k;
    cin >> n >> k;
    vector<long long int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    long long int ans = 100100100100;
    for (int bit = 0;bit < (1 << n); bit++) {
        int count = 0;
        long long int temp = 0;
        long long int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                count++;
                if (A[i] <= maxi) {
                    temp += maxi + 1 - A[i];
                    maxi = maxi + 1;
                }
            }
            maxi = max(maxi, A[i]);
        }
        if (count >= k) {
            ans = min(ans, temp);
        }
    }
    cout << ans << endl;
    return 0;
}