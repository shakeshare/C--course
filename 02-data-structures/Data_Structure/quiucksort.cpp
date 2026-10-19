
#include <stdio.h>
#include <stdlib.h>
int partition(int a[], int left, int right)
{
    int key = a[left];
    while (left < right)
    {
        while (left < right && a[right] > key)
        {
            right--;
        }
        a[left] = a[right];
        while (left < right && a[left] <= key)
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = key;
    return left;
}
void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int k = partition(a, low, high);
        printf("%d ", k);
        quicksort(a, low, k - 1);
        quicksort(a, k + 1, high);
    }
}
int main()
{
    int n, a[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)

        scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
