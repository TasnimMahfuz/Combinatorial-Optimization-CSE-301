#include <bits/stdc++.h>
using namespace std;


int costTable[100][100];
int indexTable[100][100];

const int infi = 99999999;

void initialize()
{
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++){
            costTable[i][j] = infi;
            indexTable[i][j] = 0;
        }
}

int chainMultiplication(int p[],int i,int j)
{
    if(i == j)
        return costTable[i][j] = 0;

    if(i > j)
        return infi;

    if(costTable[i][j] != infi)
        return costTable[i][j];

    for(int m = i; m <= j - 1; m++)
    {
        int temp = chainMultiplication(p,i,m) + chainMultiplication(p,m + 1, j) + p[i-1]*p[m]*p[j];

        if(temp < costTable[i][j])
        {
            costTable[i][j] = temp;
            indexTable[i][j] = m;
        }
    }

    return costTable[i][j];

}
int main()
{
    initialize();

    int ara[] = {10,5,1,10,2,10};

    FILE *ptr;
    ptr = fopen("matChain.txt","w");

    cout<<chainMultiplication(ara,1,5)<<endl;

    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            int temp = chainMultiplication(ara,i,j);

            if(temp == infi)
                //cout<<"INF\t";//
                fprintf(ptr,"%s\t","INF");
            else
                //cout<<temp<<"\t";
                fprintf(ptr,"%d\t",temp);

        }
        fprintf(ptr,"\n");
    }
    //cout<<endl<<endl<<endl;

    fprintf(ptr,"\n\n\n");

    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            int temp;
            if(j <= i)
                temp = infi;

            else
                temp = indexTable[i][j];

            if(temp == infi)
                //cout<<"INF\t";
                fprintf(ptr,"INF\t");
            else
                //cout<<temp<<"\t";
                fprintf(ptr,"%d\t",temp);
        }
        fprintf(ptr,"\n");
    }
    fclose(ptr);
    return 0;
}
