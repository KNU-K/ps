#include <iostream>
using namespace std;
int numberStoreArray[10] = { 0, };
int main() {
    int operand1, operand2, operand3;
    cin >> operand1 >> operand2 >> operand3;
    int operandsProductResult = operand1 * operand2 * operand3;
    while (operandsProductResult != 0) {
        numberStoreArray[operandsProductResult % 10] ++;
        operandsProductResult = operandsProductResult / 10;
    }
    for (int i = 0; i <= 9; i++) {
        cout << numberStoreArray[i] << "\n";
    }
}