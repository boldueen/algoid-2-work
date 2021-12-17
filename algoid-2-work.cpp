#include <iostream>
#include <ctime>

using namespace std;

class Stack {
    int * arr;
    unsigned int size;

public:
    Stack(int _size) {
        size = 0;
        arr = new int[_size];
    }

    ~Stack(){
        delete [] arr;
    }


    bool isEmpty() {
        return(size == 0) ? true : false;
    }


    void Push(int value) {
        
        arr[size] = value;
        size++;

    }


    int Pop() {
        if (size == 0) 
            return NULL;   

        int x = size - 1;
        size--;
        return arr[x];
    }


    int Peek() {
        if (size == 0)
            return NULL;

        int x = size - 1;

        return arr[x];
    }


    void Fill(int needed_size) {
        srand(time(0));
        for (int i = 0; i < needed_size; i++)
        {
            int n = rand() % 100 + 1;
            Push(n);
        }
        size = needed_size;

    }


    void Print() {

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
     
    }


    void Swap(int indDown) {
        int i = size - 1;
        int n_size = 0;
        while (i != indDown) {
            n_size++;
            i -= 1;
        }
        Stack help(n_size);
        i = size - 1;
        while (i != indDown) {
            help.Push(Pop());
            i -= 1;
        }
        int x = Pop();
        Push(help.Pop());
        Push(x);

        while (!help.isEmpty()) {
            Push(help.Pop());
        }

    }


    void InsertSort() {
        for (int i = size-1; i >= 1; i--) {
            for (int j = i; j >= 0; j--)
            {
                if (j == 0) break;
                if (arr[j] < arr[j - 1]) {
                    int s = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = s;
                    Print();

                }
            }
        }
    }


    void StackInsertSort() {
        int help = size - 1;
        for (int i = 0; i <=size; i++) {
            for (int j = help; j >= 0; j--)
            {
                if (j == 0) break;

                if (arr[j] < arr[j - 1]) 
                    Swap(j-1);
            }
        }
    }


};

int main()
{

    int size;
    cin >> size;

    Stack st(size);
    cout << "array input: ";
    st.Fill(size);
    st.Print();
    st.StackInsertSort();
    cout << "sorted array: ";
    st.Print();

    cin.get();
    cin.get();

}
