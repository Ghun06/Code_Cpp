#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

struct Node {
    int id;
    double x,y;
};

double khoangcach(Node node1, Node node2){
    return sqrt(pow(node1.x - node2.x, 2) + pow(node1.y - node2.y, 2));
}
int main(int argc, char* argv[]){
   string path = argv[1];
   ifstream inputFile(path);
   string line;
   vector<Node> danhsach;
   getline(inputFile, line);
    while (getline(inputFile, line)){
         stringstream ss(line);
         string token;
         Node node;
         getline(ss, token, ',');
         node.id = stoi(token);
         getline(ss, token, ',');
         node.x = stod(token);
         getline(ss, token, ',');
         node.y = stod(token);

         danhsach.push_back(node);
    }
    // chuyen argv[2] sang diemkhaosat
    int diemkhaosat = stoi(argv[2]);
    double kcln = -100000;
    double kcnn = 100000;

    for (int i = 0; i < danhsach.size(); i++){
        if (danhsach[i].id == diemkhaosat) continue;
        double kc = khoangcach(danhsach[i], danhsach[diemkhaosat]);
        if (kc > kcln){
            kcln = kc;
        }
        if (kc < kcnn){
            kcnn = kc;
        }
    }

    // in ra diem gan nhat
    cout << "Diem gan nhat: ";
    for (int i = 0; i < danhsach.size(); i++){
        if (danhsach[i].id == diemkhaosat) continue;
        double kc = khoangcach(danhsach[i], danhsach[diemkhaosat]);
        if (kc == kcnn){
            cout << danhsach[i].id << " ";
        }
    }
    cout << endl;
    // in ra diem xa nhat
    cout << "Diem xa nhat: ";
    for (int i = 0; i < danhsach.size(); i++){
        if (danhsach[i].id == diemkhaosat) continue;
        double kc = khoangcach(danhsach[i], danhsach[diemkhaosat]);
        if (kc == kcln){
            cout << danhsach[i].id << " ";
        }
    }
    cout << endl;
    return 0; 
}