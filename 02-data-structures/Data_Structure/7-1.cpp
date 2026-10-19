int Bisearch(int a[], int low, int high, int key)
{
    int mid;
    if (low > high)
        return -1;
    mid = (low + high) / 2;
    if (key == a[mid])
        return mid;
    else if (key < a[mid])
        return Bisearch(a, low, mid - 1, key);
    else
        return Bisearch(a, mid + 1, high, key);
}