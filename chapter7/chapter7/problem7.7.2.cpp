#include <iostream>

using namespace std;

class Matrix {
private:
    int matrix[4];
public:
    Matrix(int a, int b, int c, int d) { matrix[0] = a, matrix[1] = b, matrix[2] = c, matrix[3] = d; }
    Matrix() { for (int i = 0; i < 4; i++) { matrix[i] = 0; } }
    void show() {
        cout << "matrix = " << "{ ";
        for (int i = 0; i < 4; i++) { cout << matrix[i] << " "; }
        cout << "}" << endl;
    }
    Matrix operator+(Matrix& other) {
        Matrix temp;
        for (int i = 0; i < 4; i++) {
            temp.matrix[i] = this->matrix[i] + other.matrix[i];
        }
        return temp;
    }
    void operator+=(Matrix& other) {
        for (int i = 0; i < 4; i++) {
            this->matrix[i] += other.matrix[i];
        }
    }
    bool operator==(Matrix& comp_matrix) {
        int check = 0;
        for (int i = 0; i < 4; i++) {
            if (this->matrix[i] != comp_matrix.matrix[i]) {
                check++;
            }
        }
        if (!check) {
            return true;
        }
        else return false;
    }

    friend void operator>> (Matrix& self, int destination[4]);
    friend void operator<< (Matrix& self, int source[4]);
};

void operator>> (Matrix& self, int destination[4]) {
    for (int i = 0; i < 4; i++) {
        destination[i] = self.matrix[i];
    }
}

void operator<< (Matrix& self, int source[4]) {
    for (int i = 0; i < 4; i++) {
        self.matrix[i] = source[i];
    }
}

void problem7_2() {
    Matrix a(4, 3, 2, 1), b;
    int x[4], y[4] = { 1,2,3,4 };
    a >> x;
    b << y;

    for (int i = 0; i < 4; i++) cout << x[i] << ' ';
    cout << endl;
    b.show();
    cout << endl;
}
