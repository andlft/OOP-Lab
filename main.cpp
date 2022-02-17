#include <iostream>
using namespace std;
int main()
{
    int a, b, aux;
    cin >> a >> b;
    cout<<"numerele perfecte sunt: "<< endl;
    if(a>b)
        {aux = a; a = b; b=aux;}
    for(int i = a; i <= b; ++i)
        {aux  =  0;
        for(int j = 1; j<i; j++)
            {
            if (i%j==0)
                aux += j;
            }
        if (aux == i)
            cout<<i<<endl;
        }
    return 0;
}
