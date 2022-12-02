#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int Rob(int n, vi v) {
    int prev = v[0], prev2 = 0, curi;
    for (int i = 1; i < n; i++) {
        int pick = v[i];
        if (i > 1) pick += prev2;
        int dontPick = 0 + prev;

        curi = max(pick, dontPick);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vi v(n);
    for (int i = 0; i < n; i++) cin>>v[i];

    if (n == 1) {
        cout<<v[0]<<"\n";
        return 0;
    } 

    vi vf(n-1), vl(n-1);
    for (int i = 0; i < n; i++) {
        if (i < n-1) vf[i] = v[i];
        if (i > 0) vl[i-1] = v[i];
    }

    for (auto i : vf) cout<<i<<", \n";
    for (auto i : vl) cout<<i<<"/ \n";

    int ans1 = Rob(n-1, vf);
    int ans2 = Rob(n-1, vl);

    cout<<max(ans1, ans2)<<"\n";
    cout<<"ans1 : "<<ans1<<" ans2 : "<<ans2<<"\n";
    return 0;
}