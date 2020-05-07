#include <bits/stdc++.h> 
using namespace std;

// Обчислення u
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

// Обчислення n!
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    // кількість значень 
    int n = 7;
    float x[] = { -1.5, -1.0, -0.5,
                  0.0, 0.5, 1.0, 1.5 };

    // y[][] is used for difference  
    // table and y[][0] used for input 
    float y[n][n];
    y[0][0] = -0.7;
    y[1][0] = 0.0;
    y[2][0] = 0.7;
    y[3][0] = 1.0;
    y[4][0] = 0.7;
    y[5][0] = 0.0;
    y[6][0] = -0.7;

    // Обчислення таблиці скінченних різниць 
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    // Відображення таблиці скінченних різниць 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << setw(4) << y[i][j]
            << "\t";
        cout << endl;
    }

    // Значення для інтерполяції 
    float value = -0.443;

    // Ініціалізація u і sum 
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) /
            fact(i);
    }

    cout << "\n Value at " << value << " is "
        << sum << endl;
    return 0;
}