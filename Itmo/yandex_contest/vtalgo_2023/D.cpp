#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t a, b, c, d, k, ans{};

    bool direction;

    cin >> a >> b >> c >> d >> k;

    ans += a;

    // let f(x) = bx - c => f - monotone => (x<f(x)) => (f^p(x) < f^{p+1}(x)) for all p
    // x, f(x), f^2(x), f^3(x), ... -> +inf/-inf (otherwise x = f(x) => f^p(x) = const = a)

    if (a * b - c == a)
    {
        cout << a << endl;
        return 0;
    }

    direction = (a * b - c > a);

    // calculating delta on each step :
    // d_1 = f(x) - x = a*b - c - a;
    // d_2 = f^2(x) - f(x) = b(a*b - c) - c - (a*b - c) = b(a*b - c - a)
    // d_3 = b^2(a*b - c - a)
    // ... d_n = b^{n-1}(a*b - c - a)
    // D = sum(d_i) = (1 + b + ... + b^{n-1})*(a*b - c - a)
    if (direction)
    { // -> +inf
        for (size_t i = 0; i < k; i++)
        {
            ans += pow(b, i) * (a * b - c - a);
            if (ans >= d)
            {
                ans = d;
                break;
            }
        }
        cout << ans << endl;
    }
    else
    { // -> -inf
        for (size_t i = 0; i < k; i++)
        {
            ans += pow(b, i) * (a * b - c - a);
            if (ans <= 0)
            {
                ans = 0;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}