#include<stdio.h>
void soft(int *a);
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }  
    soft(a);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
void soft(int *a)
{
    int i, j,temp;
    for (i = 0; i < 9;i++)
    {
        for (j = i + 1; j < 10 - i;j++)
        {
            if(a[i]<a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}