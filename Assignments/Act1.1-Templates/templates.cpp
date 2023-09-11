// greta guagnelli
// a01722531
// act 1.1


#include <iostream>
using namespace std;


int sumInt(int a, int b) {
    return a + b;
}

double sumDouble(double a, double b){
    return a + b;
}

string sumString (string a, string b){
    return a + b;
}

// función de sumas dos valores con templates
template <class T>
T sum(T a, T b){
    return a + b;
}

int main()
{
    int a = 5;
    int b = 10;
    int c = sum(a,b);

    double x = 5.5;
    double y = 10.5;
    double z = sum(x,y);

    string s1 = "5";
    string s2 = "10";
    string s3 = sum(s1,s2);

    
    cout << "a: " << a << " + b: " << b << "= c: " << c << endl;
    cout << "x: " << x << " + y:" << y << "= z: " << z << endl; 
    cout << "s1: " << s1 << " + s2:" << s2 << "= s3:" << s3 << endl;

    int v1[] = {1,2,3,4,5};
    cout << v1[10] << endl;
    
    return 0;
}