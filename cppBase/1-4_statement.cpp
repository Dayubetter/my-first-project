//
// Created by dayub on 2026/3/12.
//
#include <iostream>
using namespace std;

void whileStatement() {
    int sum = 0, val =1;
    while (val <= 10) {
        sum += val;
        val++;
    }
    cout << sum << endl;
}

void forStatement() {
    int sum = 0;
    for (int i = -100; i <= 100; i++) {
        sum+=i;
    }
    cout << sum << endl;
}

void whileInput() {
    int sum = 0,val = 0;
    while (cin>>val) {
        sum+=val;
    }
    cout << sum << endl;
}
int main() {
    whileStatement();
    forStatement();
    whileInput();
    return 0;
}