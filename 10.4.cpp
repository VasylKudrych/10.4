//#include <cstdlib>  // for the definition of EXIT_FAILURE
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;


// Associate stream objects with external file names

void Cars() {
    ofstream myfile; // outs is an output stream
    string line;
    ifstream myfilein; // myfilein is an input stream        
    myfilein.open("cars.txt"); // connect myfilein to file Input File
    ofstream outfile("cars_new.txt");

    vector<vector<string>> stringarray;

    if (myfilein.is_open())
    {
        int i = 0;
        while (getline(myfilein, line))
        {

            stringarray.push_back(vector<string>());
            stringstream ss(line);
            string temp;
            while (ss >> temp) {
                stringarray[i].push_back(temp);
            }
            i++;
        }
        myfile.close();  // close output file stream
    }

    sort(stringarray.begin(), stringarray.end());
    for (int i = 0; i < stringarray.size(); ++i) {
        for (int j = 0; j < stringarray[i].size(); ++j) {
            outfile << stringarray[i][j] << " " << ends;
        }
        outfile << endl;
    }

    double b = 0;
    for (int i = 0; i < stringarray.size(); i++) {
        b += stoi(stringarray[i][2]);
    }

    outfile << "Середнiй пробiг усiх авто : " << b / stringarray.size() << " км" << endl;  ///outfile <<....
    int count = 1;
    int a = 0;

    for (int k = 0; k < 100; k++) {
        count = 1;
        for (int i = 0; i < stringarray.size() - 1; i++) {

            if (stringarray[i][0] == stringarray[i + 1][0]) {

                count++;
                stringarray[i][1] = to_string(count);
                a = stoi(stringarray[i][2]) + stoi(stringarray[i + 1][2]);
                stringarray[i][2] = to_string(a);
                stringarray.erase(stringarray.begin() + i + 1);
                i--;
            }
            else if (stringarray[i][0] != stringarray[i + 1][0]) {

                //       a = stoi(stringarray[i][2]);
                //       int count1 = stoi(stringarray[i][1]);
                //       stringarray[i][2] = to_string(a);
                count = 1;
            }

        }

    }

    for (int i = 0; i < stringarray.size(); i++) {
        int avarage = 0;
        int count_auto = stoi(stringarray[i][1]);
        int distance = stoi(stringarray[i][2]);
        avarage = distance / count_auto;
        stringarray[i][2] = to_string(avarage);
    }



    for (int i = 0; i < stringarray.size(); ++i) {
        for (int j = 0; j < stringarray[i].size(); ++j) {
            if (j != 1) {
                outfile << stringarray[i][j] << " " << ends;
            }
        }
        outfile << " км" << endl;
    }
    outfile << "Кiлькiсть унiкальних авто : " << stringarray.size() << " шт";
}
int main() {
    setlocale(LC_ALL, "Russian");




    char ch;
    do {
        cout << "Головне меню " << endl;
        cout << "1. Створення файлу i сортування " << endl;
        cout << "2. Вихiд" << endl;
        cout << "Виберiть меню :" << endl;
        cin >> ch;
        switch (ch)
        {
        case '0':
            cout << endl;
            cout << "Прощавай!";
            break;
        case '1':
            Cars();
            cout << "Файл 'cars_new.txt' створений" << endl;
            break;
        default:
            return 0;
            break;
        }


    } while (ch != 0);

}
