#include<stdio.h>
#include<string.h>
struct card
{
    char hs[10];
    int mz;
};
int main()
{
    struct card h3, m4 = {"梅花", 4};
    strcpy(h3.hs, "黑桃");
    h3.mz = 3;
    printf("%s %d\n", h3.hs, h3.mz);
    printf("%s %d\n", m4.hs, m4.mz);
    return 0;
}