//1
#include <iostream>
#include <functional>

// Higher-order function to compute the product
template<typename T, typename U>
U prod(T start, T end, std::function<U(T)> func) {
    U result = 1;
    for (T i = start; i <= end; ++i) {
        result *= func(i);
    }
    return result;
}

// Main function
int main() {
    // (a) Calculating x^n
    double x;
    int n;
    std::cout << "Enter a real number (x) and a natural number (n) for x^n: ";
    std::cin >> x >> n;
    double power = prod<int, double>(1, n, [x](int) { return x; });
    std::cout << "x^n = " << power << std::endl;

    // (b) Calculating n!
    int m;
    std::cout << "Enter a natural number (n) for n!: ";
    std::cin >> m;
    int factorial = prod<int, int>(1, m, [](int i) { return i; });
    std::cout << "n! = " << factorial << std::endl;

    return 0;
}
//3
#include <iostream>

double compute_expression(int n, int m, double a) {
    double y = 0.0;
    for (int i = 1; i <= n; ++i) {
        double product = 1.0;
        for (int j = 1; j <= m; ++j) {
            product *= (a + j) / (i + j);
        }
        y += product;
    }
    return y;
}

int main() {
    int n, m;
    double a;
    
    // Input n, m, and a
    std::cout << "Enter the values of n, m, and a: ";
    std::cin >> n >> m >> a;
    
    // Compute and display the result
    double result = compute_expression(n, m, a);
    std::cout << "The value of the expression is: " << result << std::endl;
    
    return 0;
}
//2
#include <iostream>
#include <functional>
#include <cmath>

// Higher-order function to compute the product (factorial in this case)
template<typename T>
T prod(int start, int end, std::function<T(int)> func) {
    T result = 1;
    for (int i = start; i <= end; ++i) {
        result *= func(i);
    }
    return result;
}

// Higher-order function to compute the sum of the series
template<typename T>
T sum(int n, std::function<T(int)> func) {
    T result = 0;
    for (int i = 0; i <= n; ++i) {
        result += func(i);
    }
    return result;
}

int main() {
    double x;
    int n;
    
    // Input x and n
    std::cout << "Enter the value of x: ";
    std::cin >> x;
    std::cout << "Enter the number of terms n: ";
    std::cin >> n;

    // Calculate series (a)
    double sine_series = sum<double>(n, [&](int i) {
        return (i % 2 == 0 ? 1 : -1) * std::pow(x, 2 * i + 1) / prod<double>(1, 2 * i + 1, [](int j) { return j; });
    });

    // Calculate series (b)
    double cosine_series = sum<double>(n, [&](int i) {
        return (i % 2 == 0 ? 1 : -1) * std::pow(x, 2 * i) / prod<double>(1, 2 * i, [](int j) { return j; });
    });

    // Display the results
    std::cout << "The value of the sine series is: " << sine_series << std::endl;
    std::cout << "The value of the cosine series is: " << cosine_series << std::endl;

    return 0;
}
//4
#include <iostream>
#include <functional>

const int MAX_SIZE = 100; // Maximum size of the matrix

void applyToMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n, std::function<int(int)> f, std::function<int(int)> g) {
    int seq = 0;

    for (int slice = 0; slice < 2 * n - 1; ++slice) {
        int z = (slice < n) ? 0 : slice - n + 1;
        for (int j = z; j <= slice - z; ++j) {
            if (j == slice - j) continue; // Skip main diagonal elements

            if (seq % 2 == 0) {
                matrix[j][slice - j] = f(matrix[j][slice - j]);
            } else {
                matrix[j][slice - j] = g(matrix[j][slice - j]);
            }
            ++seq;
        }
    }
}

std::function<int(int)> getUserFunction(char funcName) {
    char operation;
    int value;
    std::cout << "Enter operation for function " << funcName << " (add: +, subtract: -, multiply: *, divide: /): ";
    std::cin >> operation;
    std::cout << "Enter value for function " << funcName << ": ";
    std::cin >> value;

    switch (operation) {
        case '+': return [value](int x) { return x + value; };
        case '-': return [value](int x) { return x - value; };
        case '*': return [value](int x) { return x * value; };
        case '/': return [value](int x) { return x / value; }; // Note: No division by zero check
        default:  return [](int x) { return x; }; // Default case
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;
    std::cout << "Enter size of square matrix (max " << MAX_SIZE << "): ";
    std::cin >> n;
    if (n > MAX_SIZE) {
        std::cout << "Matrix size too large!" << std::endl;
        return 1;
    }

    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    auto f = getUserFunction('f');
    auto g = getUserFunction('g');

    applyToMatrix(matrix, n, f, g);

    std::cout << "Modified matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
