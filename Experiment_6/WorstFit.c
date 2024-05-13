#include<stdio.h>
struct process
{
int ps;
int flag;
} p[50];

struct sizes
{
int size;
int alloc;
}s[5];
int main()
{
int i=0,np=0,n=0,j=0, max=0,index;
printf("\n Worst fit");
printf("\n");

printf("enter the number of blocks \t");
scanf("%d",&n);
printf("\t\t\n enter the size for %d blocks\n",n);
for(i=0;i<n;i++)
{
printf("enter the size for %d block \t",i);
scanf("%d",&s[i].size);
}
printf("\n enter the number of process\t",i);
scanf("%d",&np);
printf("enter the size of %d processors !\t",np);
printf("\n");
for(i=0;i<np;i++)
{
printf("enter the size of process %d\t",i);
scanf("\n%d",&p[i].ps);
}
printf("\n\t\t Allocation of blocks using first fit is as follows\n");
printf("\n\t\t process \t process size\t blocks\n");
for(i=0;i<np;i++)
{
    max=0;
    for(j=0;j<n;j++)
    {
        if(s[j].alloc!=1)
        {
            if (max<s[j].size)
            {
                max=s[j].size;
                index=j;
            }
        }
    }
    if(p[i].flag!=1)
    {
        if(p[i].ps<=s[index].size)
        {
            p[i].flag=1;
            s[index].alloc=1;
        }
    }
printf("\n\t\t %d\t\t\t%d\t%d\t",i,p[i].ps,s[index].size);
}
for(i=0;i<np;i++)
{
if(p[i].flag!=1)
printf("sorry !!!!!!!process %d must wait as there is no sufficient memory",i);
}
}