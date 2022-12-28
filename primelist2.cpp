#include <stdio.h>
#include<iostream>
using namespace std;

void primeInRange(int L, int R)
{
    int i, j, flag;
    for (i = L; i <= R; i++) {
        if (i == 1 || i == 0)
            continue;
        flag = 1;
        for (j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cout<<i<<endl;
    }
}
int main()
{
    int L,R;
    cout<<"enter lower limit:";
    cin>>L;
    cout<<"enter upper limit:";
    cin>>R;
    primeInRange(L, R);
 
    return 0;
}