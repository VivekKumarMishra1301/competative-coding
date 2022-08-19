void printTable(int start, int end, int step)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.

     */
    if (start >= 0 && start <= 1000 && end >= 0 && end <= 1000 && step >= 0 && step <= 1000)
    {
        int i = start;
        while (i <= end)
        {
            int celsius = (5 / 9) * (i - 32);
            cout << i << "\t" << celsius << endl;
            i = i + step;
        }
    }
}
