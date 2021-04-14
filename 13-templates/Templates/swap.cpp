template<typename DATA_TYPE>
void swap(DATA_TYPE &x, DATA_TYPE &y)
{
    DATA_TYPE temp = x;
    x = y;
    y = temp;
}