#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Date
{
    int d;
    int m;
    int y;
    Date(){}
    Date(string s){
        stringstream ss(s);
        string token;
        getline(ss, token, '/');
        d = stoi(token);
        getline(ss, token, '/');
        m = stoi(token);
        getline(ss, token, '/');
        y = stoi(token);
    }
};

struct Match
{
    Date date;
    string home;
    string away;
    int homeScore;
    int awayScore;
    string season;

    Match(string s) {
        stringstream ss(s);
        string token;
        getline(ss, token, ',');
        date = Date(token);
        getline(ss, token, ',');
        home = token;
        getline(ss, token, ',');
        away = token;
        getline(ss, token, ',');
        homeScore = stoi(token);
        getline(ss, token, ',');
        awayScore = stoi(token);
        getline(ss, token, ',');
        season = token;
    }
};

int main(int argc, char* argv[])
{
    ifstream inFile(argv[1]);
    if (!inFile){
        cout << "ERROR !!!\n";
        exit(0);
    }

    vector<Match> arsenalMatches;

    ofstream outFile("D:/File_CPP/ArsenalMaiDinh.csv");
    string line;
    getline(inFile, line);
    while (getline(inFile, line)){
        Match m(line);
        if (m.home == "Arsenal" || m.away == "Arsenal"){
            outFile << line << endl;
            arsenalMatches.push_back(m);
        }
    }
    cout << "Tong cong co " << arsenalMatches.size() << "tran dau cua Arsenal\n";

    // -------------
    int homeWin = 0;
    int homeDraw = 0;
    int homeLose = 0;

    int awayWin = 0;
    int awayDraw = 0;
    int awayLose = 0;
    for (Match &m : arsenalMatches){
        if (m.home == "Arsenal"){
            if (m.homeScore > m.awayScore)
                homeWin++;
            else if (m.homeScore == m.awayScore)
                homeDraw++;
            else
                homeLose++;
        } else {
            if (m.awayScore > m.homeScore)
                awayWin++;
            else if (m.homeScore == m.awayScore)
                awayDraw++;
            else
                awayLose++;
        }
    }
    cout << "Thang/Hoa/Thua san nha : " << homeWin << "/" << homeDraw << "/" << homeLose << endl;
    cout << "Thang/Hoa/Thua san khach : " << awayWin << "/" << awayDraw << "/" << awayLose << endl;

    // -----------------
    unordered_map<string,int> score;
    for (Match &m : arsenalMatches){
        if (score.find(m.season) == score.end())
            score[m.season] = 0;

        if (m.home == "Arsenal"){
            if (m.homeScore > m.awayScore)
                score[m.season] += 3;
            else if (m.homeScore == m.awayScore)
                score[m.season] += 1;
        } else {
            if (m.awayScore > m.homeScore)
                score[m.season] += 3;
            else if (m.homeScore == m.awayScore)
                score[m.season] += 1;
        }
    }

    // sort
    vector<pair<string,int>> vec;
    for (auto p : score)
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

    cout << "TOP 5 mua giai cao diem nhat:\n";
    for (int i = 0; i < 5; ++i){
        cout << vec[i].first << " - " << vec[i].second << " pt\n";
    }

    return 0;
}
