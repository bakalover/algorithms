#include <iostream>
#include <vector>
using namespace std;

size_t part(vector<uint16_t> &arr, size_t l, size_t r)
{
    uint16_t p = arr[l];
    size_t i = l, j = r;
    while (i <= r)
    {

        while (arr[i] < p)
        {
            i++;
        }

        while (arr[j] > p)
        {
            j--;
        }

        if (i >= j)
        {
            break;
        }
        swap(arr[i++], arr[j--]);
    }
    return j;
}

void qsortt(vector<uint16_t> &arr, size_t l, size_t r)
{
    if (r <= l)
    {
        return;
    }
    size_t p = part(arr, l, r);
    qsortt(arr, l, p);
    qsortt(arr, p + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    uint32_t n, k;
    uint64_t ans{};

    cin >> n >> k;

    vector<uint16_t> cost(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    qsortt(cost, 0, cost.size() - 1);

    for (size_t i = 1; i <= n; ++i)
    {
        if (i % k != 0)
        {
            ans += cost[n - i];
        }
    }

    cout << ans << endl;

    return 0;
}