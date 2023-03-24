#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

struct SaleRecord
{
    int rank;
    string name;
    string platform;
    string year;
    string genre;
    string publisher;
    double NAsale;
    double EUsale;
    double JPsale;
    double othersale;
    double globalsale;

    SaleRecord(string s) {
        stringstream ss(s);
        string token;
        getline(ss, token, ',');
        rank = stoi(token);
        getline(ss, token, ',');
        name = token;
        getline(ss, token, ',');
        platform = token;
        getline(ss, token, ',');
        year = (token);
        getline(ss, token, ',');
        genre = token;
        getline(ss, token, ',');
        publisher = token;
        getline(ss, token, ',');
        NAsale = stod(token);
        getline(ss, token, ',');
        EUsale = stod(token);
        getline(ss, token, ',');
        JPsale = stod(token);
        getline(ss, token, ',');
        othersale = stod(token);
        getline(ss, token, ',');
        globalsale = stod(token);
    }
};

int main(int argc, char* argv[])
{
    ifstream inFile(argv[1]);
    if (!inFile){
        cout << "ERROR !!!\n";
        exit(0);
    }

    vector<SaleRecord> games;
    unordered_map<string,double> genreSales;
    unordered_map<string,double> publisherSales;

    string line;
    getline(inFile, line);
    while (getline(inFile, line)){
        SaleRecord m(line);
        games.push_back(m);

        if (genreSales.find(m.genre) == genreSales.end())
            genreSales[m.genre] = m.globalsale;
        else
            genreSales[m.genre] += m.globalsale;

        if (publisherSales.find(m.publisher) == publisherSales.end())
            publisherSales[m.publisher] = m.globalsale;
        else
            publisherSales[m.publisher] += m.globalsale;
    }

    cout << "Thong ke sale moi the loai game:\n";
    for (auto p : genreSales){
        cout << "   " << p.first << " - " << p.second << endl;
    }

    // ------------
    // sort
    vector<pair<string,double>> vec;
    for (auto p : publisherSales)
        vec.push_back(p);

    for (int i = 0; i < vec.size(); ++i){
        for (int j = i + 1; j < vec.size(); ++j){
            if (vec[i].second < vec[j].second){
                auto temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }

    int n = stoi(argv[2]);
    cout << "TOP " << n << " mua giai cao diem nhat:\n";
    for (int i = 0; i < n; ++i){
        cout << "   " << vec[i].first << " - " << vec[i].second << "\n";
    }

    // ---------
    string dongGame = argv[3];
    double sum = 0;
    for (SaleRecord& s : games){
        if (s.name.find( dongGame ) != string::npos)
            sum += s.globalsale;
    }
    cout << "Dong game " << dongGame << " co tong sale la " << sum << endl;

    return 0;
}
