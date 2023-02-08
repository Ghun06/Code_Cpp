#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
bool isNum(string s){
    for (int i = 0; i < s.size(); ++i)
        if ( ! isdigit(s[i]))
            return false;
    return true;
}

int main(int argc, char *argv[]){
    if (argc < 3){
        cout << "Thieu du lieu !" << endl;
        exit(0);
    }
    // } else if (argc > 3) {
    //     cout << "Thua du lieu !" << endl;
    //     exit(0);
    // }
    // if ( ! isNum(argv[2])){
    //     cout << "Tuoi khong hop le !" << endl;
    //     exit(0);
    // }

    string name, age;
    // Since char is a primitive type inherited from C, no operator == is defined.
    // So we have to use strcmp() function from C library.
    /*
    for (int i = 1; i < argc; ++i){
        if (strcmp(argv[i], "-a") == 0){
            age = argv[i+1];
        } else if (strcmp(argv[i], "-n") == 0){
            name = argv[i+1];
        }
    }
    */
    // Using C++ string class
    for (int i = 1; i < argc; ++i){
        if (string(argv[i]) == "-a"){
            age = argv[i+1];
        } else if (string(argv[i]) == "-n"){
            name = argv[i+1];
        }
    }
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << name << " - " << age << endl;
    return 0;
}