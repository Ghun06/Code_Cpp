#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>
using namespace std;
struct Edge{
    int i, j;
    double trongso;
};

int main(int argc, char* argv[]){
    if (argc < 7){
        cout << "Truyen thieu tham so" << endl;
        exit(0);
    }

    string path;
    int nodeid = 0;
    double w = 0;
    for (int i = 0; i < argc; ++i) {
        if (string(argv[i]) == "-p"){
            path = argv[i+1];
        } else if (string(argv[i]) == "-n"){
            nodeid = stoi(argv[i+1]);
        } else if (string(argv[i]) == "-w"){
            w = stod(argv[i+1]);
        }
    }
    string line;
    vector<Edge> list;
    ifstream myfile(path);
    if (!myfile){
        cout << "ERROR: Could not open";
        return 0;
    }
    getline(myfile, line);
    while (getline(myfile, line)){
        istringstream iss(line);
        string token;
        Edge c;
        getline(iss, token, ',');
        c.i = stoi(token);
        getline(iss, token, ',');
        c.j = stoi(token);
        getline(iss, token, ',');
        c.trongso = stod(token);

        list.push_back(c);
    }

    for (auto &canh : list){
        if (canh.i == nodeid && canh.trongso > w){
            cout << canh.j << " " << canh.trongso << endl;
        }
    }
    cout << endl;
    return 0;
}