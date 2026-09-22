#include <iostream>
#include <random>
using namespace std;

int main() {

    /*int n;
    cout << "Enter the number of array elements:\n";
    cin >> n;*/

    int i;
    double arr[10];

    for (i = 0; i < 10; ++i) {

        arr[i] = (double)rand() / RAND_MAX * 50 - 25;
        cout << arr[i] << "  ";
    }
    cout << endl;

    double p;
    cout << "Enter P\n";
    cin >> p; 

    int n = 0;

    for (i = 0; i < 10; ++i) {
        if (arr[i] < p) {
            
            n += 1;
        }
    }

    int size = 10;
    double summa = 0;

    for (i = size - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            
            break;
        }

        double round = floor(arr[i]);
        summa += round;
    }

    cout << "The number of: " << n << '\n';
    cout << "Summa is: " << summa << '\n';

    /*for (i = 1; i < 10; ++i) {
       while (arr[i] <= p && arr[i - 1] > p) {
           swap(arr[i], arr[i - 1]);
       }
   }*/

    /*for (i = 0; i < 10; ++i) {

        cout << arr[i] << "  ";
    }*/

    return 0;
}