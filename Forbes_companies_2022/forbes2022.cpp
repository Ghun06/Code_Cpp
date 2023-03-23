#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

struct Company {
    string global_company;
    string country;
    double sales;
    double profit;
    string assets;
    string market_value;
};

double convertNumber(std::string num) {
    double factor = 1.0;
    if (num[0] == '$' && num.back() == 'B') {
        factor = pow(10, 9);
    } else if (num[0] == '$' && num.back() == 'M') {
        factor = pow(10, 6);
    }
    num.erase(num.size()-2);
    num.erase(0, 1);
    double value;
    istringstream(num) >> value;
    return value * factor;
}

int main(int argc, char* argv[]){
    if (argc < 7){
        cout << "Khong truyen du tham so";
        exit(0);
    }
    string path;
    string countryName;
    string value;
    for (int i = 0; i < argc; i++){
        if (string(argv[i]) == "-p") path = argv[i+1]; 
        if (string(argv[i]) == "-c") countryName = argv[i+1]; 
        if (string(argv[i]) == "-v") value = argv[i+1]; 
    }
    ifstream myfile(path);
    if (!myfile){
        cout << "Khong doc duoc file";
        return 0;
    }
    string line;
    vector<Company> danhsach;
    getline(myfile, line);
    while (getline(myfile, line)){
        istringstream iss(line);
        string token;
        Company company; 
        getline(iss, token, ',');
        getline(iss, token, ',');
        company.global_company = token;
        getline(iss, token, ',');
        company.country = token;
        getline(iss, token, ',');
        company.sales = convertNumber(token);
        getline(iss, token, ',');
        company.profit = convertNumber(token);
        getline(iss, token, ',');
        company.assets = token;
        getline(iss, token, ',');
        company.market_value = token;
        
        danhsach.push_back(company);
    }
    myfile.close();
    // ghi ra file csv với tên là tên quốc gia được nhâp từ bàn phím
    ofstream outFile(countryName + ".csv");
    if (!outFile){
        cout << "Khong ghi duoc file";
        return 0;
    }
    outFile << "Global Company Name, Country, Sales, Profit, Assets, Market Value" << endl;
    for (auto i : danhsach){
        if (i.country == countryName){
            outFile << i.global_company << "," << i.country << "," << i.sales << "," << i.profit << "," << i.assets << "," << i.market_value << endl;
        }
    }
    outFile.close();

    double valuess = convertNumber(value);
    int count = 0;
    //  In ra có bao nhiêu profit lớn hơn value
    cout << "Cac cong ty co loi nhuan lon hon " << value << " la: " << endl;
    for (auto i : danhsach){
        if (i.profit > valuess){
            cout << i.global_company << endl;
            count++;
        }
    }
    cout << "Tong cong ty co loi nhuan lon hon " << value << " la: " << count << endl;
    // In ra tên các công ty đang có lợi nhuận (profit) âm
    cout << "Cac cong ty co loi nhuan am: " << endl;
    for (auto a : danhsach){
        if (a.profit < 0){
            cout << a.global_company << endl;
        }
    }
    return 0;
}
        

