int buffer;
int sum0 = 0, sum1 = 0, sum2 = 0;

semaphore empty = 1;
semaphore full0 = 0;
semaphore full1 = 0;
semaphore full2 = 0;

process A()
{
    int x;
    while (readfile(x))
    {
        wait(empty);
        buffer = x;
        if (x % 3 == 0)
            signal(full0);
        else if (x % 3 == 1)
            signal(full1);
        else
            signal(full2);
    }
}

process B()
{
    while (true)
    {
        wait(full0);
        sum0 += buffer;
        signal(empty);
    }
}

process C()
{
    while (true)
    {
        wait(full1);
        sum1 += buffer;
        signal(empty);
    }
}

process D()
{
    while (true)
    {
        wait(full2);
        sum2 += buffer;
        signal(empty);
    }
}
