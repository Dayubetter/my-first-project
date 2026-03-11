//
// Created by dayub on 2026/3/11.
//
#include <iostream>
using namespace std;

void test1() {
    int a, b, c;
    cout << "Please enter three numbers: ";
    cin>>a>>b>>c;
    cout<<"the second number is:"<<b<<endl;
}

void test2() {
    int a, b;
    cin >> a >> b;
    cout << a/b << " " << a%b << endl;
}
int main() {
    //test1();
    test2();
}