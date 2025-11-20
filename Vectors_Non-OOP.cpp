#include <iostream>
using namespace std;


void inputVector(double v[], int n);
void outputVector(const double v[], int n);
void addVectors(const double a[], const double b[], double result[], int n);
void subtractVectors(const double a[], const double b[], double result[], int n);
double dotProduct(const double a[], const double b[], int n);
void scalarMultiply(double v[], int n, double scalar);



// Input
void inputVector(double v[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
}

// Output 
void outputVector(const double v[], int n) {
    cout << "(";
    for (int i = 0; i < n; ++i) {
        cout << v[i];
        if (i < n - 1) cout << ", ";
    }
    cout << ")";
}

// Add 
void addVectors(const double a[], const double b[], double result[], int n) {
    for (int i = 0; i < n; ++i)
        result[i] = a[i] + b[i];
}

// Subtract
void subtractVectors(const double a[], const double b[], double result[], int n) {
    for (int i = 0; i < n; ++i)
        result[i] = a[i] - b[i];
}

// Dot product (scalar)
double dotProduct(const double a[], const double b[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i)
        sum += a[i] * b[i];
    return sum;
}

// Multiply 
void scalarMultiply(double v[], int n, double scalar) {
    for (int i = 0; i < n; ++i)
        v[i] *= scalar;
}


int main() {
    int n;
    cout << "Enter the dimension of the vectors: ";
    cin >> n;

    double *a = new double[n];
    double *b = new double[n];
    double *result = new double[n];

    cout << "\nEnter elements of vector A:\n";
    inputVector(a, n);

    cout << "\nEnter elements of vector B:\n";
    inputVector(b, n);

    cout << "\nVector A = ";
    outputVector(a, n);
    cout << "\nVector B = ";
    outputVector(b, n);
    cout << endl;

    addVectors(a, b, result, n);
    cout << "\nA + B = ";
    outputVector(result, n);

    subtractVectors(a, b, result, n);
    cout << "\nA - B = ";
    outputVector(result, n);

    double scalar = 0;
    cout << "\n\nEnter a scalar value: ";
    cin >> scalar;

    scalarMultiply(a, n, scalar);
    cout << "Scalar * A = ";
    outputVector(a, n);

    double dp = dotProduct(a, b, n);
    cout << "\nDot Product (A·B) = " << dp << endl;

    delete[] a;
    delete[] b;
    delete[] result;

    cout << "\nPress Enter to exit..";
    cin.ignore();
    cin.get();

    return 0;
}
