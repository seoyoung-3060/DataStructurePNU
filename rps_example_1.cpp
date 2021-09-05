#include <bits/stdc++.h>
using namespace std;

int main() {
    char A, B;
    cin >> A >> B;
    if (A-B == 0) cout << 'D';
    else if(A-B < 0 ) {
        if(A=='P'&&B=='S') cout << B;
        else cout << A;
    }
    else{
        if(A=='S'&&B=='P') cout << A;
        else cout << B;
    }

}