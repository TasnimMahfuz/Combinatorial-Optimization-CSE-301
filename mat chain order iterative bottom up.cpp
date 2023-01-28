#include <bits/stdc++.h>
using namespace std;

int m[100][100],s[100][100];
//I should think about a different algo to traverse diagonally.
//I will hopefully do that after my exam ends.

void matChain(int p[],int len)
{
    int n = len;//sizeof()/sizeof(p[0]);

    for(int i = 1;i <= n; i++)
        m[i][i] = 0;

    for(int l = 2; l <= n; l++)
    {
        for(int i = 1; i <= n + 1 - l ; i++)
        {
            int j = i + l - 1;
            m[i][j] = 66666;//infinity.

            for(int k = i; k <= j-1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i-1]*p[k]*p[j];

                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int ara[] = {10,5,1,10,2,10};

    matChain(ara, 6-1);

    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl<<endl<<endl;

    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cout<< s[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}
