#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void sort1( int* arr1, int* arr2, int*& arr3, int inputSize, int& outputSize )
{
    //Store the starting time
    double duration;
    clock_t startTime = clock();

    if ( inputSize <= 0)
    {
      cout << "Error: size should be greater than 0" << endl;
      return;
    }
    else
    {
        if ( arr3)
            delete [] arr3;

        outputSize = inputSize * 2;

        arr3 = new int[outputSize];

        // Inserting every item in the first array to the third array
        for ( int i = 0; i < inputSize; i++)
        {
            arr3[i] = arr1[i];
        }

        int size3counter = 0;
        int size3 = inputSize;

        bool inserted;

        for ( int i = 0; i < inputSize; i++)
        {
            inserted = false;

            while ( !inserted)
            {
                if ( size3counter >= size3 || arr2[i] < arr3[size3counter]) {
                    // put element into kth spot
                    for ( int j = size3; j > size3counter; j--)
                    {
                        arr3[j] = arr3[j - 1];
                    }
                    arr3[size3counter] = arr2[i];
                    size3++;
                    inserted = true;
                }
                size3counter++;
            }
        }
    }
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds in first algorithm." << endl;
}

void sort2 ( int* arr1, int* arr2, int*& arr3, int inputSize, int& outputSize )
{
    //Store the starting time
    double duration;
    clock_t startTime = clock();

    if ( inputSize <= 0)
    {
        cout << "Error: size should be greater than 0." << endl;
        return;
    }
    else
    {
        outputSize = inputSize * 2;

        if ( arr3 != NULL)
            delete [] arr3;

        arr3 = new int[outputSize];

        int index = 0;
        int check = 0;
        int checked2 = 0;

        for ( int i = 0; i < inputSize; i++)
        {
            for ( int j = check; j < inputSize; j++)
            {
                if ( arr1[i] <= arr2[j])
                {
                    arr3[index] = arr1[i];
                    index++;
                    checked2 = i + 1;
                    break;
                }
                else if ( arr1[i] > arr2[j])
                {
                    arr3[index] = arr2[j];
                    check = j + 1;
                    index++;
                }
            }
        }

        for ( int i = check; i < inputSize; i++)
        {
            arr3[index] = arr2[i];
            index++;
        }

        if ( check >= inputSize)
        {
            for ( int i = checked2; i < inputSize; i++)
            {
                arr3[index] = arr1[i];
                index++;
            }
        }
    }

    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds in second algorithm." << endl;
}

int main()
{
    int N = 1000;

    while ( N < 150000000)
    {

        int outputSize;
        cout << "N = " << N << endl;
        int* arr1 = new int[N];
        int* arr2 = new int[N];
        int* arr3 = new int[2*N];

        for ( int i = 0; i < N; i++)
        {
            arr1[i] = rand();
        }

        sort(arr1,arr1 + N);

        for ( int i = 0; i < N; i++)
        {
            arr2[i] = arr1[N - 1] + rand();
        }

        sort(arr2,arr2 + N);

        cout << "When arr1 is strictly smaller than arr2" << endl;
        sort1(arr1,arr2,arr3,N,outputSize);
        sort2(arr1,arr2,arr3,N,outputSize);

        for ( int i = 0; i < N; i++)
        {
            arr2[i] = rand();
        }

        sort(arr2,arr2 + N);

        for ( int i = 0; i < N; i++)
        {
            arr1[i] = arr2[N - 1] + rand();
        }

        sort(arr1,arr1 + N);

        cout << "When arr2 is strictly smaller than arr1" << endl;
        sort1(arr1,arr2,arr3,N,outputSize);
        sort2(arr1,arr2,arr3,N,outputSize);


        for ( int i = 0; i < N; i++)
        {
            arr2[i] = rand();
            arr1[i] = rand();
        }

        sort(arr1,arr1 + N);
        sort(arr2,arr2 + N);

        cout << "When there is no such ordering" << endl;
        sort1(arr1,arr2,arr3,N,outputSize);
        sort2(arr1,arr2,arr3,N,outputSize);
        N = N * 2;
        delete [] arr1;
        delete [] arr2;
        delete [] arr3;
    }
    return 0;
}
