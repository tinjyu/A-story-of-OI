#include <iostream>
#include <algorithm>
using namespace std;
long long int MAX = 1000000007;
long long int q, n, m, a[1000005], tree[4000005][2], lazy[4000005], pos[4000005][2];
void build(int l, int r, int t)
{
    if (l == r)
    {
        lazy[t] = 0;
        tree[t][0] = a[l];
        tree[t][1] = a[r];
        pos[t][0] = l;
        pos[t][1] = l;
        return;
    }
    lazy[t] = 0;
    long long int mid = (l + r) / 2;
    build(l, mid, 2 * t);
    build(mid + 1, r, 2 * t + 1);
    tree[t][0] = max(tree[2 * t][0], tree[2 * t + 1][0]);
    if (tree[2 * t][0] >= tree[2 * t + 1][0])
        pos[t][0] = pos[2 * t][0];
    else
        pos[t][0] = pos[2 * t + 1][0];

    tree[t][1] = min(tree[2 * t][1], tree[2 * t + 1][1]);
    if (tree[2 * t][1] <= tree[2 * t + 1][1])
        pos[t][1] = pos[2 * t][1];
    else
        pos[t][1] = pos[2 * t + 1][1];
    return;
}
void pushdown(int l, int r, int t)
{
    if (lazy[t] == 0)
        return;
    lazy[2 * t] += lazy[t];
    lazy[2 * t + 1] += lazy[t];
    lazy[2 * t] %= 2;
    lazy[2 * t + 1] %= 2;
    lazy[t] = 0;
    swap(tree[2 * t][0], tree[2 * t][1]);
    swap(pos[2 * t][0], pos[2 * t][1]);
    tree[2 * t][1] = MAX - tree[2 * t][1];
    tree[2 * t][0] = MAX - tree[2 * t][0];
    swap(tree[2 * t + 1][0], tree[2 * t + 1][1]);
    swap(pos[2 * t + 1][0], pos[2 * t + 1][1]);
    tree[2 * t + 1][1] = MAX - tree[2 * t + 1][1];
    tree[2 * t + 1][0] = MAX - tree[2 * t + 1][0];
    return;
}
void change(int l, int r, int t, int st, int en)
{
    if (r < st || l > en)
        return;
    if (l >= st && r <= en)
    {
        // cout << st << " " << en << " " << l << " " << r << " " << tree[t][0] << " " << pos[t][0] << " " << tree[t][1] << " " << pos[t][1] << endl;
        lazy[t] += 1;
        lazy[t] %= 2;
        swap(tree[t][0], tree[t][1]);
        swap(pos[t][0], pos[t][1]);
        tree[t][1] = MAX - tree[t][1];
        tree[t][0] = MAX - tree[t][0];
        // cout << st << " " << en << " " << l << " " << r << " " << tree[t][0] << " " << pos[t][0] << endl;
        return;
    }
    pushdown(l, r, t);
    long long int mid = (l + r) / 2;
    change(l, mid, 2 * t, st, en);
    change(mid + 1, r, t * 2 + 1, st, en);

    tree[t][0] = max(tree[2 * t][0], tree[2 * t + 1][0]);
    if (tree[2 * t][0] >= tree[2 * t + 1][0])
        pos[t][0] = pos[2 * t][0];
    else
        pos[t][0] = pos[2 * t + 1][0];

    tree[t][1] = min(tree[2 * t][1], tree[2 * t + 1][1]);
    if (tree[2 * t][1] <= tree[2 * t + 1][1])
        pos[t][1] = pos[2 * t][1];
    else
        pos[t][1] = pos[2 * t + 1][1];
    return;
}
long long int solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    cin >> q;
    long long int sum = 0;
    while (q--)
    {
        long long int l, r;
        cin >> l >> r;
        change(1, n, 1, l, r);
        sum += pos[1][0];
        // cout << pos[1][0] << " " << tree[1][0] << " " << a[pos[1][0]] << endl;
    }
    return sum;
}
int main()
{
    freopen("today_is_gonna_be_a_great_day_input.txt", "r", stdin);
    freopen("today_is_gonna_be_a_great_day_output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}