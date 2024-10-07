#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

const int SIZE = 25;
const int MIN_VALUE = 15;
const int MAX_VALUE = 94;

void generateArray(int arr[], int size) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

    for (int i = 0; i < size; ++i) {
        arr[i] = distribution(generator);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}


int processArray(int arr[], int size, int& count, int& sum) {
    count = sum = 0;
    for (int i = 0; i < size; i++) {

        if (!(arr[i] % 2 == 0 && i % 13 == 0)) {
            ++count;
            sum += arr[i];
        }
    }
    return sum;
}


void replaceElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {

        if ((arr[i] % 2 == 0 || arr[i] % 13 == 0)) {
            arr[i] = 0;
        }
    }
}

int main() {
    int p[SIZE], count, sum;


    generateArray(p, SIZE);


    cout << "Initial array:" << endl;
    printArray(p, SIZE);


    processArray(p, SIZE, count, sum);


    replaceElements(p, SIZE);

    cout << "\nNumber of elements satisfying the criterion: " << count << endl;
    cout << "Sum of elements satisfying the criterion: " << sum << endl;

    cout << "Modified array:" << endl;
    printArray(p, SIZE);

    return 0;
}
