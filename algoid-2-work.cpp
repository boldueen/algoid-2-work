#include <iostream>

using namespace std;


void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void Push(int*& arr, int& size, int value) {
    int new_size = size + 1;
    int* help = new int[new_size];
    for (int i = 0; i < size; i++)
    {
        help[i] = arr[i];
    }
    help[size] = value;
    size++;

    delete[] arr;

    arr = help;

}

int Pop(int*& arr, int& size) {
    if (size == 0)
        return NULL;
    int new_size = size - 1;
    int* help = new int[new_size];
    int rtrn = arr[size - 1];
    size--;


    for (int i = 0; i < size; i++)
    {
        help[i] = arr[i];
    }

    delete[] arr;

    arr = help;
    return rtrn;

}

void Add(int*& arr, int& size, int value) {

    int new_size = size + 1;
    int* help = new int[new_size];


    for (int i = 0; i < size; i++)
    {
        help[i+1] = arr[i];
    }
    help[0] = value;
    size++;
    delete[] arr;

    arr = help;


}


int Peek(int* arr, int size) {
    return arr[size - 1];
}

void InsertSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j >= 0; j--)
        {
            if (j == 0) break;
            if (arr[j] < arr[j - 1]) {
                int s = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = s;


            }
        }
    }
}


//void Swap(int* arr, int size) {
//    int* help = new int[];
//    if () {
//
//    }
//
//
//}

void StackInsertSort(int* arr, int size) {
    int* help = new int[size];

    if (arr[size - 1] < arr[size - 2]) {
        int n = Pop(arr, size);
        int m = Pop(arr, size);
        Push(arr, size, n);
        Push(help, size, m);
    }

    delete[] help;
}





int main()
{


    int size, a;
    cin >> size;
    int* arr = new int[size];
    int* help_arr = arr;
    int helpsz = size;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }


    
    //for (int i = size-1; i > 0; --i)
    //{
    //    if (arr[i] < arr[i-1]) {
    //        int n = Pop(arr, size);
    //        int m = Pop(arr, size);
    //        Add(help_arr, helpsz, m);
    //        int n_sz = size--;
    //        Push(arr, n_sz, n);

    //    }
    //    
    //    if (arr[i] < arr[i - 1]) {
    //        int n = Pop(arr, size);
    //        Add(help_arr, size, n);
    //    }
    //    


    //}

    PrintArray(arr, size);
    cout << "\n";
    PrintArray(help_arr, size);
   
    delete[] arr;
    cin.get();
    cin.get();



}
