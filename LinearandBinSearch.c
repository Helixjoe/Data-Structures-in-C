#include<stdio.h>
int main()
{
    int a[10],ch,search,n,i,j,found=0,high,mid,low=0,temp;
    printf("Enter no of elements:");
    scanf("%d",&n);
    high = n-1;
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
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
        mid = high+low-1/2;
        //bubble sort
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
            printf("Low= %d",low);
            printf("\nHigh= %d",high);
            if(search>a[mid])
            {
                low = mid;
                mid = (high+low-1)/2;
            }
            else if(search<a[mid])
            {
                high = mid;
                mid = (high+low-1)/2;
            }
            else if(search == a[mid])
            {
                break;
            }
        }
        printf("Element found at %d",mid);
    }

    return 0;
}
