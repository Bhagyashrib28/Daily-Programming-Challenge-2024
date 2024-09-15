# include <iostream>
using namespace std;

int missing_element(int a[] , int n)
{
    for (int i=0; i<n; i++)
    {
        if (a[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

int main()
{
    int input_array[] = {1,2,4,5};
    int size = ( sizeof(input_array) / sizeof(input_array[0]) );

    int result = missing_element(input_array , size);
    cout<<"Missing Element is :- "<<result;

    return 0;
}