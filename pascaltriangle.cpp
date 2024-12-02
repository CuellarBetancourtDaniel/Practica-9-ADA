#include <iostream>
using namespace std;

void generatePascalTriangle(int numRows) {
    int** triangle = new int*[numRows]; // Creamos un arreglo de punteros

    for (int i = 0; i < numRows; i++) {
        triangle[i] = new int[i + 1]; // Creamos un arreglo para cada fila
        triangle[i][0] = 1;           // Para el primer elemento de cada fila es 1
        triangle[i][i] = 1;           // Para el último elemento de cada fila es 1

        // Calculamos los valores internos
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // Imprimimos el triángulo de Pascal
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    // Liberaamos la memoria dinámica para evitar fugas de memoria
    for (int i = 0; i < numRows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
}

int main() {
    int numRows;
    cout << "Digita el número de filas para el triángulo de Pascal: ";
    cin >> numRows;

    if (numRows < 1 || numRows > 30) {
        cout << "El número debe estar entre 1 y 30." << endl;
        return 1;
    }

    generatePascalTriangle(numRows);

    return 0;
}
