#include <bits/stdc++.h>
using namespace std;
int main()
{
    double num, depth, i;
    while (1)
    {
        cin >> num;
        if (num == 0)
            break;
        vector<double> arr(num);
        for (i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        cin >> depth;
        if(depth <= 0 || depth > floor(log2(num) + 1))
        {
            cout << "EMPTY" << endl;            
            continue;
        }
        for (i = pow(2, depth - 1) - 1; i < num && i < pow(2, depth) - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}