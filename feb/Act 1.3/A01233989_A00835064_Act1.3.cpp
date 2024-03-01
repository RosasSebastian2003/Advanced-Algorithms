#include <iostream>
#include <vector>
#include <queue>


// Eugenio Pedraza a00835064
// Sebastian Rosales A01191733
using namespace std;

// Verifica si un movimiento es válido
// Complejidad: O(1)
bool isValid(const vector<vector<int>>& matriz, int row, int column) {
    int rows = matriz.size();
    int columns = matriz[0].size();
    return row >= 0 && row < rows && column >= 0 && column < columns && matriz[row][column] == 1;
}

// Algoritmo de backtracking para encontrar un camino
// Complejidad: O(2^(n*m))
bool backTracking(const vector<vector<int>>& matriz, vector<vector<int>>& ans, int row, int column) {
    if (row == matriz.size() - 1 && column == matriz[0].size() - 1) {
        ans[row][column] = 1;
        return true;
    }
    if (isValid(matriz, row, column)) {
        ans[row][column] = 1;
        if (backTracking(matriz, ans, row, column + 1)) {
            return true;
        }
        if (backTracking(matriz, ans, row + 1, column)) {
            return true;
        }
        ans[row][column] = 0;
    }
    return false;
}

// Estructura para representar un nodo en la matriz
struct Node {
    int row;
    int column;
    int cost;
};

// Ramificacion y poda 
// Complejidad: O(2^(n*m))
bool podaRamificacion(const vector<vector<int>>& matrix, vector<vector<int>>& ans, int row = 0, int column = 0) {
    int rows = matrix.size();
    int columns = matrix[0].size();

    if (!isValid(matrix, row, column) || ans[row][column] == 1) {
        return false;
    }

    ans[row][column] = 1;

    if (row == rows - 1 && column == columns - 1) {
        return true;
    }

    if (podaRamificacion(matrix, ans, row, column + 1) || podaRamificacion(matrix, ans, row + 1, column)) {
        return true;
    }

    ans[row][column] = 0;
    return false;
}

// Imprime la matriz
void printMatriz(const vector<vector<int>>& matriz) {
    for (const auto& row : matriz) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {

    // // Caso de prueba 1
    vector<vector<int>> matrix1 = {
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };
    vector<vector<int>> ans1 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    cout << "Caso de prueba 1" << endl;
    cout << "Camino encontrado (BACKTRACKING):" << endl;
    backTracking(matrix1, ans1, 0, 0);
    printMatriz(ans1);
    cout << "Camino encontrado (RAMIFICACION):" << endl;
    for (auto &row : ans1) fill(row.begin(), row.end(), 0);
    podaRamificacion(matrix1, ans1);
    printMatriz(ans1);
    cout << endl;


    // Caso de prueba 2
    vector<vector<int>> matrix2 = {
        {1, 0, 1},
        {1, 1, 1},
        {0, 1, 1}
    };
    vector<vector<int>> ans2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Caso de prueba 2" << endl;
    cout << "Camino encontrado (BACKTRACKING):" << endl;
    backTracking(matrix2, ans2, 0, 0);
    printMatriz(ans2);
    cout << "Camino encontrado (RAMIFICACION):" << endl;
    for (auto &row : ans2) fill(row.begin(), row.end(), 0);
    podaRamificacion(matrix2, ans2);
    printMatriz(ans2);
    cout << endl;

    // Caso de prueba 3
    vector<vector<int>> matrix3 = {
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };
    vector<vector<int>> ans3 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    cout << "Caso de prueba 3" << endl;
    cout << "Camino encontrado (BACKTRACKING):" << endl;
    backTracking(matrix3, ans3, 0, 0);
    printMatriz(ans3);
    cout << "Camino encontrado (RAMIFICACION):" << endl;
    for (auto &row : ans3) fill(row.begin(), row.end(), 0);
    podaRamificacion(matrix3, ans3);
    printMatriz(ans3);
    cout << endl;

    // Caso de prueba 4
    vector<vector<int>> matrix4 = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };
    vector<vector<int>> ans4 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    cout << "Caso de prueba 4" << endl;
    cout << "Camino encontrado (BACKTRACKING):" << endl;
    backTracking(matrix4, ans4, 0, 0);
    printMatriz(ans4);
    cout << "Camino encontrado (RAMIFICACION):" << endl;
    for (auto &row : ans4) fill(row.begin(), row.end(), 0);
    podaRamificacion(matrix4, ans4);
    printMatriz(ans4);
    cout << endl;

    // User In
    int M, N, valor;
    cout << "Ingrese la cantidad de filas: ";
    cin >> M;
    cout << "Ingrese la cantidad de columnas: ";
    cin >> N;

    vector<vector<int>> matriz(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            matriz[i][j] = row[j] - '0';  // Convert char to int
        }
    }

    // Comprobar si la esquina inferior derecha es accesible
    if (matriz[M-1][N-1] == 0) {
        cout << "No hay camino disponible." << endl;
        return 0; // Finalizar el programa
    }

    vector<vector<int>> ans(M, vector<int>(N, 0));

    backTracking(matriz, ans, 0, 0);
    cout << "Camino encontrado (BACKTRACKING):" << endl;
    printMatriz(ans);

    for (auto &row : ans) fill(row.begin(), row.end(), 0);

    podaRamificacion(matriz, ans);
    cout << "Camino encontrado (RAMIFICACION):" << endl;
    printMatriz(ans);

    return 0;
}
