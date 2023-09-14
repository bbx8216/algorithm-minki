#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > v;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }
    sort(v.begin(), v.end());

    int last = v[0].first;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].second >= last)
        {
            ans++;
            last = v[i].first;
        }
    }
    cout << ans;
}