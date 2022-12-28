#include <bits/stdc++.h>
using namespace std;
 
// Returns true if n is prime, else
// return false.
// i is current divisor to check.
bool isPrime(int n, int i = 2)
{
    // Base cases
    if (n <= 2)
        return (n == 2) ? true : false;
    if (n % i == 0)
        return false;
    if (n%i!=0)
        return true;
 
    // Check for next divisor
    return isPrime(n, i + 1);
}
 
// Driver Program
int main()
{
    int n;
    cout<<"Enter a no"<<endl;
    cin>>n;
    if (isPrime(n))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}