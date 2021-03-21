int vectorMax(int v[], int size)
{
    int currentMax = v[0];
    for (int i = 1; i < size; ++i)
    {
        if (currentMax < v[i])
        {
            currentMax = v[i];
        }
    }
    return currentMax;
}