#include <stdio.h>
void choice(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    int a[10]={2,4,7,1,6,9,8,3,0,5};
    int i;
    choice(a,10);
    for(i=0;i<10;i++)
        printf("%d  ",a[i]);
 
    printf("\n");
    return 0;
}
