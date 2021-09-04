#include <bits/stdc++.h>
using namespace std;

int main() {
    char A, B;
    cin >> A >> B;
    if(A==B)
        cout << 'D';
    else if((A=='R' && B=='S') || (A=='S' && B=='R'))
        cout << 'R';
    else if((A=='R'  && B=='P')||(A=='P' && B=='R'))
        cout << 'P';
    else
        cout << 'S';

}