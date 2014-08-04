#include<stdio.h>
int ratings[100005];

int main()
{
    int x,n,i=0,j=-1,k;
    scanf("%d %d", &x, &n);
    for(i=0;i<n;i++)
        scanf("%d", &ratings[i]);
    int lastrating = ratings[0];
    for(i=1,j=-1;i<n;i++)
    {
        if(ratings[i]>lastrating)
        {
            lastrating = ratings[i];
            for(k=1; i-k>j;k++)
                ratings[i-k]=k;
            if(j<i-1 && ratings[j]<=ratings[j+1])
                ratings[j] = ratings[j+1] +1;
            ratings[i] = ratings[i-1]+1;
            j=i;
        }
        else{
        lastrating = ratings[i];
        }
       
    }
    for(k=1; i-k>j;k++)
        ratings[i-k]=k;
    if(j<i-1 && ratings[j]<=ratings[j+1])
                ratings[j] = ratings[j+1] +1;
               
    long int sum = 0;
    for(i=0;i<n;i++)
    {
        sum+= ratings[i];
    }
    printf("%d\n", sum*x);
   
    /* //for debugging
    for(i=0;i<n;i++)
        printf("%d\n",ratings[i]);
       
    scanf("%d", &i);
    */
    return 0;
}