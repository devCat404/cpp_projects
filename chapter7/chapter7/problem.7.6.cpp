#include <iostream>

using namespace std;

void problem6_2();

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
};

void problem6() {
	
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b;
    a += b;
    a.show(); b.show(); c.show();
    if (a == c)
        cout << "a and c are the same" << endl << endl;
    problem6_2();
}
