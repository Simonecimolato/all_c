//PrimeQuestion
//Simone Cimolato, 07/10/2016

#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

int main(int argc, char** argv) {
    while (true) {
        cout << "Enter a positive integer (max: 18.446.744.073.709.551.615): ";
        unsigned long long number;
        cin >> number;

        if (cin.fail() || number < 1) {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (number == 1) {
            cout << endl << "1 is not prime." << endl << endl;
        } else {
            int radQ = round(sqrt(number) + 0.5);
            int Div = 2;
            int Resto;
            while (Div <= radQ) {
                Resto = number % Div;
                if (Div == radQ) {
                    cout << endl << number << " is prime." << endl << endl;
                    system("PAUSE");
                    return 0;
                }
                if (Resto == 0) {
                    cout << endl << number << " is not prime" << ", it is divisible by " << Div << "." << endl << endl;
                    system("PAUSE");
                    return 0;
                }
                Div++;
            }
        }
        system("PAUSE");
        return 0;
    }
}
