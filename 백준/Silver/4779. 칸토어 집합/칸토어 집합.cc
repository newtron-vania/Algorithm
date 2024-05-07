#include <iostream>
#include <cmath>
using namespace std;

void Cantor(int n)
{
    int size = pow(3, n - 1);

    if (n == 0)
    {
        cout << "-";
        return;
    }

    Cantor(n - 1);
    for (int i = 0; i < size; i++)
    {
        cout << " ";
    }
    Cantor(n - 1);
}

int main()
{
    int n;
    while (cin >> n)
    {
        Cantor(n);
        cout << endl;
    }
}