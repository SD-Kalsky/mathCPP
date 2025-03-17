#include <iostream> //Подключение стандартной библиотеки ввода и вывода под названием "iostream"
#include <cstdlib>
#include <ctime>
using namespace std;// Настройка пропуска указания std 

template <typename T = int> 
class  Matrix{
protected:
    int colSize, strSize;
    T** matrix;
    void init(){
        int i, j=0;
        matrix = new T*[colSize];
        while(j < colSize){
            i = 0;
            matrix[j] = new T[strSize];
            while(i < strSize){
                matrix[j][i] = 0;
                i++;
            }
            j++;
        }
    }
    void destroy(){
        int j=0;
        while(j < colSize){
            delete [] matrix[j];
            matrix[j] = nullptr;
            j++;
        }
        delete [] matrix;
        matrix = nullptr;
    }
public:
Matrix(){
    this->colSize = 3, this->strSize = 3;
    this->init();
}
Matrix(int m, int n){
    this->colSize = m, this->strSize = n;
    this->init();
}
~Matrix(){
    this->destroy();
}
void setElement(T a, int i, int j){
    this->matrix[j][i] = a;
}
T getElement(int i, int j){
    return this->matrix[j][i];
}
void print(){
    int i, j=0;
        while(j < this->colSize){
            i = 0;
            while(i < this->strSize){
                cout << matrix[j][i];
                if( i < this->strSize - 1 )  cout<< ", "; else cout << endl;
                i++;
            }
            j++;
        }
}
template <typename TT = int>
void randomFill(TT a, TT b){
    int i, j=0;
    srand(time(0));
    while(j < this->colSize){
        i = 0;
        while(i < this->strSize){
            matrix[j][i] = rand()%b + a;
            i++;
        }
        j++;
    }
}
void replaceCol(int i, int j){
    int c, k=0;
    if(i > 0 && j > 0){
        i--; j--;
        while(k < this->colSize){
            c = this->matrix[k][i];
            this->matrix[k][i] = this->matrix[k][j];
            this->matrix[k][j] = c;
            k++; 
        }
    }   
}
bool isThereEqualCol(){
    int i, j = 0, k;
    bool b = false, bjk;
    while(j < this->colSize){
        k = j + 1;
        while(k < this->colSize){
            i = 0;
            bjk = true;
            while(i < this->strSize){
                bjk = (matrix[k][i] == matrix[j][i]);
                i++;
            }
            if (bjk) {b = true; break;}
            k++;
        }
        if (b) break;
        j++;
    }
    return b;
}
bool isThereEqualStr(){
    int i, j = 0, k;
    bool b = false, bjk;
    while(j < this->strSize){
        k = j + 1;
        while(k < this->strSize){
            i = 0;
            bjk = true;
            while(i < this->colSize){
                bjk = (matrix[i][k] == matrix[i][j]);
                i++;
            }
            if (bjk) {b = true; break;}
            k++;
        }
        if (b) break;
        j++;
    }
    return b;
}
Matrix& operator = (const Matrix& m ){
    this->colSize = m.colSize;
    this->strSize = m.strSize;
    this->init();
    int i, j = 0;
    while(j < this->colSize){
        i = 0;
        while(i < this->strSize){
            this->matrix[j][i] = m.matrix[j][i];
            i++;
        }
        j++;
    }
    return *this;
}



Matrix operator * (const Matrix& m ){
    Matrix ms(this->colSize, m.strSize);
    int i, j=0, k;
    T s = 0;
    while(j < this->colSize){
        i = 0;
        while(i < m.strSize){
            k = 0;
            while(k < this->strSize){
                    s += (this->matrix[i][k] * m.matrix[k][j]);
                k++;
            }
            i++;
        }
        ms.setElement(s,i,j);
        j++;
    }
    return m;
}

Matrix operator* (const int& m ){
    int i, j=0;
    while(j < this->colSize){
        i = 0;
        while(i < this->strSize){
            this->matrix[j][i] *= m;
            i++;
        }
        j++;
    }
    return this;
}
Matrix operator/ (const int& m ){
    int i, j=0;
    while(j < this->colSize){
        i = 0;
        while(i < this->strSize){
            this->matrix[j][i] /= m;
            i++;
        }
        j++;
    }
    return this;
}
template<T = int>
Matrix operator + (const <T>Matrix& m1, const  <T>Matrix& m2);
};

template <typename T = int>
Matrix sum( <T>Matrix m1,  <T>Matrix m2){
    Matrix m (m1.colSize, m1.strSize)
    int i, j=0;
    try{
        if ( m1.colSize == m2.colSize && m1.strSize == m2.strSize)
        while(j < this->colSize){
            i = 0;
            while(i < this->strSize){
                m1.matrix[j][i] += m2.matrix[j][i];
                i++;
            }
            j++;
        }
        else throw "Unequal sizes of the matrices";
    }
    catch (const char* error)
    {
        std::cout << "Error: " << error << std::endl;
    }
    return m;
}



// Matrix<T> Matrix<T>::operator -(const <T>Matrix& m1, const  <T>Matrix& m2){
//     Matrix m (m1.colSize, m1.strSize)
//     int i, j=0;
//     try{
//         if ( m1.colSize == m2.colSize && m1.strSize == m2.strSize)
//         while(j < this->colSize){
//             i = 0;
//             while(i < this->strSize){
//                 m1.matrix[j][i] -= m2.matrix[j][i];
//                 i++;
//             }
//             j++;
//         }
//         else throw "Unequal sizes of the matrices";
//     }
//     catch (const char* error)
//     {
//         std::cout << "Error: " << error << std::endl;
//     }
//     return m;
// }
