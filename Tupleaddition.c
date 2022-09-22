#include<stdio.h>

void tupleconv(int matrix[10][10],int r,int c,int count);

int main()
{
    int i,j,r,c,matrix1[10][10],matrix2[10][10],smatrix[20][3],count1=0,count2=0,k=1;
    
    printf("Enter no of rows for both matrices:");
    scanf("%d",&r);
    printf("Enter no of columns for both matrices");
    scanf("%d",&c);
    printf("Enter elements of Matrix 1:");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&matrix1[i][j]);
            if(matrix2[i][j]!=0)
                count1++;
        }
    }
    printf("Enter elements of Matrix 2:");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&matrix2[i][j]);
            if(matrix2[i][j]!=0)
                count2++;
        }
    }
    
    printf("Matrix 1:\n");
     for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
     for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }

    printf("Tuple matrix 1:\n");
    tupleconv(matrix1,r,c,count1);
    printf("Tuple matrix 2:\n");
    tupleconv(matrix2,r,c,count2);
    

    smatrix[0][0] = r;
    smatrix[0][1] = c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(matrix1[i][j]!=0 && matrix2[i][j]!=0)
                {
                    smatrix[k][0] = i;
                    smatrix[k][1] = j;
                    smatrix[k][2] = matrix1[i][j]+ matrix2[i][j];
                    k++;
                }
            else if(matrix1[i][j]!=0)
                {
                    smatrix[k][0] = i;
                    smatrix[k][1] = j;
                    smatrix[k][2] = matrix1[i][j];
                    k++;
                }
            else if(matrix2[i][j]!=0)
                {
                    smatrix[k][0] = i;
                    smatrix[k][1] = j;
                    smatrix[k][2] = matrix2[i][j];
                    k++;
                }
        }
    }
    smatrix[0][2] = k-1;
    
    printf("Sum of tuple matrices are:\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",smatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void tupleconv(int matrix[10][10], int r, int c, int count)
{
    int i,j,tmatrix[20][3],k=1;
    tmatrix[0][0] = r;
    tmatrix[0][1] = c;
    tmatrix[0][2] = count;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(matrix[i][j]!=0)
            {
                tmatrix[k][0] = i;
                tmatrix[k][1] = j;
                tmatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    
     for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d ",tmatrix[i][j]);
        }
        printf("\n");
    }
 }