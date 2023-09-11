// greta guagnelli
// a01722531
// act 1.2


#include <iostream>
using namespace std;


int sumIterative(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum +=i;
    }
    return sum;
}

int sumRecursive(int n)
{
    //condicion de control
    if (n > 1)
    {
        return n + sumRecursive(n-1);
    }
 else
    {
        return 1;
    }
}

int sumFormula(int n)
{
    return n*(n+1)/2;
}

int fibonacciIterative(int n)
{
int antesFib = 0;
    int fib = 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = antesFib +fib;
        antesFib = fib;
        fib = c;
    }
    return fib;
}

int fibonacciRecursive(int n)
{
    int fib = 1;
    if (n == 1 || n == 2)
    {
        return 1;    
    }
    else
 {
        return fibonacciIterative(n-1) + fibonacciIterative(n-2);
    }
}

int bacteriasIterative(int days)
{
    int bacterias = 1;
    float rate = 1.44;
    for (int i = 1; i <= days; i++)
    {
        bacterias = bacterias + bacterias * rate;
    }
    return bacterias;
}

int bacteriasRecursive(int days)
{
    if (days > 0)
    {
        int bacterias = bacteriasRecursive(days-1);
        float born = bacterias*1.44;
        return bacterias + born;
    }
    else
    {
        return 1;
    } 
}
float investmentIterative(float balance, int months)
{
    float interestRate = 18.75;
    float newBalance = balance;
    for (int i = 0; i < months; i++)
    {
        newBalance = newBalance *(1+interestRate/100);
    }
    return newBalance;
}

float investmentRecursive(float balance, int months)
{
    if (months>0)
    {
        return investmentRecursive(balance, months-1) * (1+ 18.75/100);
    }else{
        return balance;
    }
    
}
int powIterative(int n, int y)
{
    int  r=1;
    for (int i = 0; i < y; i++)
    {
         r = r*n;
    }
    return r;
}

int powRecursive(int n, int y)
{
    if (y>0)
    {
        return n * powRecursive(n,y-1);
    }
    else{
        return 1;
    }
    
}
int PowIterative(int n, int y)
{
    int  r=1;
    for (int i = 0; i < y; i++)
    {
         r = r*n;
    }
    return r;
}

int PowRecursive(int n, int y)
{
    if (y>0)
    {
        return n * powRecursive(n,y-1);
    }
    else{
        return 1;
    }
    
}
int main()
{
    //Suma Iterativa 
    int sum1 = sumIterative(5);
    cout <<"La suma del 1 al 5 es: " << sum1 << "\n";

    //Suma Recursive  
    int sum2 = sumRecursive(5);
    cout <<"La suma del 1 al 5 es: " << sum2 << "\n";

    //Suma con formula  
    int sum3 = sumFormula(5);
    cout <<"La suma del 1 al 5 es: " << sum3 << "\n";

    //fibonacciIterative
    int sum4 = fibonacciIterative(6);
    cout <<"El numero Fibonacci Iterativamente de 6 es: " << sum4 << "\n";

    //fibonacciRecursive
    int sum5 = fibonacciRecursive(6);
    cout <<"El numero Fibonacci Recursivamente de 6 es: " << sum5 << "\n";
//bacteriasIterative
    int sum6 = bacteriasIterative(4);
    cout <<"El numero Bacterias Iterativamente de 4 dias es: " << sum6 << "\n";

    //bacteriasRecursive
    int sum7 = bacteriasRecursive(4);
    cout <<"El numero Bacterias Recurcivamente de 4 dias es: " << sum7 << "\n";

   //investmentIterative
    int sum8 = investmentIterative(100, 18);
    cout <<"El monto final Iterativamente es: " << sum8 << "\n";

    //investmentRecursive
    int sum9 = investmentRecursive(100, 18);
    cout <<"El monto final Recursivamente es: " << sum9 << "\n";
 int sum10 = powIterative(2,5);
    cout <<"El numero dos elevado a la quinta potencia de modo Iterativo es: " << sum10 << "\n";

    int sum11 = powRecursive(2,6);
    cout <<"El numero dos elevado a la sexta potencia de modo Recursivo es " << sum11 << "\n";


return 0;

}