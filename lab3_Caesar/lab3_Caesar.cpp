// lab3_Caesar.cpp : 
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	char str[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int sum = 3;
	int t = 0;
	cout << "enter 10 characters ";
	cout << '\n';
	for (int i = 0; i < 10; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < 10; i++) {
		t = str[i] + sum;
		str[i] = char(t);
	}
	cout << '\n';
	cout << "Encrypted characters co offset 3 characters to the right - ";
	for (int i = 0; i < 10; i++) {
		cout << str[i];
	}
	 cout << '\n';
     cout << '\n';
	 cout << '\n';
	 return (0);
}

