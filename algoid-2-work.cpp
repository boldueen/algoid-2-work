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







void StackInsertSort(int* arr, int size) {
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





int main()
{


    int size, a;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }



    //StackInsertSort(arr, size);






    Push(arr, size, Pop(arr, size));

    if (Pop(arr, size) > Peek(arr, size)) {

    }
    else {

    }


    //if (Pop(arr, size) > Peek(arr, size)) {
    //    cout << "pop bolshe peek emae\n" ;
    //    PrintArray(arr, size);
    //}










    cout << "\n========\n" << "\n============\n";

    PrintArray(arr, size);





    delete[] arr;
    cin.get();
    cin.get();



}
