#include <stdio.h>
#include <stdlib.h>

void sort(int []);
int noofrect;
int checkinside(int x,int y);
int checkrect(int x1,int y1,int x2,int y2);
int arr[100][4];
int main()
{
    FILE *input;
    register int i,j;
    int lx,ly,ux,uy;
    int xmin,xmax,ymin,ymax;
    int area,maxarea=0;

    input=fopen("data.txt","r");
    fscanf(input,"%d",&noofrect);
    printf("number = %d ", noofrect);
    for(i=0;i<noofrect;i++)
    {
        fscanf(input,"%d %d %d %d",&lx,&ly,&ux,&uy);
        if((lx >= ux) || (ly >= uy))
        {
            printf("\nThe data entry (%d,%d) (%d,%d) is not a valid rectangle!!!!\nExiting the program!!!!",lx,ly,ux,uy);
            fclose(input);
            return 0;
        }
        printf("\nCood = %d %d %d %d\n",lx,ly,ux,uy);
        arr[i][0] = lx;
        arr[i][1] = ux;
        arr[i][2] = ly;
        arr[i][3] = uy;
    }

    for(i=0;i<noofrect;i++)
    {
        for(j=noofrect-1;j>=0;j--)
        {
            printf("\nRect checking.... %d %d %d %d",arr[i][0],arr[i][2],arr[j][1],arr[j][3]);
            if(checkrect(arr[i][0],arr[i][2],arr[j][1],arr[j][3]))
            {
                printf("\nRect %d %d %d %d",arr[i][0],arr[i][2],arr[j][1],arr[j][3]);
                if((arr[i][0]<arr[j][2])&&(arr[i][1]<arr[i][3]))
                {
                    area = (arr[j][2]-arr[i][0])*(arr[j][3]-arr[i][1]);
                    if(maxarea < area)
                    {
                        maxarea = area;
                        xmax = arr[i][2];
                        ymax = arr[i][3];
                        xmin = arr[i][0];
                        ymin = arr[i][1];
                    }
                    printf("\ncheck area %d %d",maxarea,area);
                }
            }
        }
    }
    printf("\nArea = %d",maxarea);
    fclose(input);
    return 0;
}

int checkinside(int x,int y)
{
    int i;
    for(i=0;i<noofrect;i++)
    {
        if((arr[i][0]>=x || arr[i][2]<=x)&&(arr[i][1]>=y || arr[i][3]<=y))
            return 1;
    }
    return 0;
}

int checkrect(int x1,int y1,int x2,int y2)
{
    int i,j;
    for(i=x1;i<=x2;i++)
    {
        for(j=y1;j<=y2;j++)
        {
            if(checkinside(i,j)==0)
                return 0;
        }
    }
    return 1;
}
