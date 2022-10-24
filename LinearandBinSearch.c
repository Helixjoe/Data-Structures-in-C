#include<stdio.h>
int main()
{
    int a[10],ch,search,n,i,j,found=0,high,mid,low,temp,cont='y';
    printf("Enter no of elements:");
    scanf("%d",&n);
    
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(cont=='y')
    {
    printf("Enter element to be searched");
    scanf("%d",&search);
    printf("Choose Method 1) Linear Search 2) Binary Search");
    scanf("%d",&ch);
    
        if(ch==1)
        {
            for(i=0;i<n;i++)
                {
                    if(a[i]==search)
                    {
                        printf("Element %d found at %d",search,i);
                        found = 1;
                    }
                }
            if(found ==0)
                printf("Element not found");
        }
        else if(ch==2)
        {
            high = n-1;
            low = 0;
            mid = (low+high)/2;
            
            for(i=0;i<n;i++)
            {
                for(j=0;j<n-i-1;j++)
                {
                    if(a[j]>a[j+1])
                    {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    }
                }
            }
            for(i=0;i<n;i++)
            {
                printf("%d ",a[i]);
            }
            while(low<=high)
            {
                if(search>a[mid])
                {
                    low = mid+1;
                }
                else if(search==a[mid])
                {
                    printf("Element found at %d",mid+1);
                    break;
                }
                else
                {
                    high = mid-1;
                }
                mid = (low+high)/2;
            }
            
        }
        printf("Do you want to continue(y/n)?");
        scanf(" %c",&cont);
        if(cont =='n')
            break;
    }
    return 0;
}
