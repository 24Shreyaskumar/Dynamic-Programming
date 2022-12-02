#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;

    int prev = 1, prev2 = 0, curi = 0;

    for (int i = 0; i <= n; i++) {
        curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }

    cout<<prev<<"\n";

    return;
}