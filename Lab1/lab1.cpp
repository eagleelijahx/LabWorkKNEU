#include <iostream>
using namespace std;

// Функція активації
int activation(double v) {
    return (v > 0) ? 1 : 0;
}

// Функція OR
int OR(int x1, int x2) {
    return (x1 || x2);
}

// Функція AND
int AND(int x1, int x2) {
    return (x1 && x2);
}

// Функція XOR через OR та AND
int XOR(int x1, int x2) {
    return OR(x1, x2) && !AND(x1, x2);
}

// Нейрон OR для персептрона
int neuronOR(int x1, int x2) {
    return activation(x1 + x2 - 0.5);
}

// Нейрон AND для персептрона
int neuronAND(int x1, int x2) {
    return activation(x1 + x2 - 1.5);
}

// Нейрон XOR для персептрона
int neuronXOR(int y1, int y2) {
    return activation(y1 - 2 * y2 - 0.5);
}

int main() {

    // ==========================================
    // ЗАВДАННЯ 1. Реалізація XOR через OR та AND
    // ==========================================

    int x1, x2;

    cout << "ЗАВДАННЯ 1: XOR через OR та AND\n";

    cout << "Enter x1 (0 or 1): ";
    cin >> x1;

    cout << "Enter x2 (0 or 1): ";
    cin >> x2;

    if ((x1 != 0 && x1 != 1) || (x2 != 0 && x2 != 1)) {
        cout << "Error! Enter only 0 or 1." << endl;
        return 1;
    }

    cout << "\nOR = " << OR(x1, x2) << endl;
    cout << "AND = " << AND(x1, x2) << endl;
    cout << "XOR = " << XOR(x1, x2) << endl;


    // ==========================================
    // ЗАВДАННЯ 2. Двошаровий персептрон для XOR
    // ==========================================

    cout << "\nЗАВДАННЯ 2: Двошаровий персептрон XOR\n\n";

    cout << "x1  x2  OR  AND  XOR\n";
    cout << "---------------------\n";

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {

            int y1 = neuronOR(a, b);
            int y2 = neuronAND(a, b);
            int result = neuronXOR(y1, y2);

            cout << a << "   "
                 << b << "   "
                 << y1 << "   "
                 << y2 << "    "
                 << result << endl;
        }
    }

    return 0;
}
