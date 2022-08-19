
bool checkMember(int n)
{

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int fib;
    int fib1 = 0;
    int fib2 = 1;
    while (1)
    {
        if (n == fib1 || n == fib2 || n == fib)
        {
            return true;
        }
        else if (n < fib)
        {
            return false;
        }
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
}
