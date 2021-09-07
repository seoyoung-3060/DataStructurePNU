#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> array;
    int input;
    while (cin >> input && input != 0)
        array.push_back(input);

    int size = array[0] + 1;
    int arraysize = array.size();
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < arraysize; j++)
            if (array[j] >= (i + 1))
                count++;
        cout << count << ' ';
    }
    return 0;
}