#include <iostream>
#include <string>
#include <vector>
#include "MARSHRUT.h"
using namespace std;

int n = 6;
vector<MARSHRUT>marsh;

void add_6_struct () {
    MARSHRUT s;
    cout << "Форма для заполнения данных о 6 маршрутах" << endl;
    string start, end;
    int length, number;
    for (int i = 0; i < n; i++) {
        cout << "Введите номер маршрута: " << endl;
        cin >> number;
        cout << "Введите начальный пункт маршрута: " << endl;
        cin >> start;
        cout << "Введите конечный пункт маршрута: " << endl;
        cin >> end;
        cout << "Введите длину маршрута: " << endl;
        cin >> length;
        cout << endl;

        s.RouteNumber = number;
        s.StartOfTheRoute = start;
        s.EndOfTheRoute = end;
        s.RouteLength = length;
        marsh.push_back(s);
    }
}

    void print(MARSHRUT str){
        cout << "Номер маршрута: " << str.RouteNumber << endl;
        cout << "Начало маршрута: " << str.StartOfTheRoute << endl;
        cout << "Конечная точка маршрута: " << str.EndOfTheRoute << endl;
        cout << "Длина маршрута: " << str.RouteLength << endl;
        cout << "***************************" << endl;
        cout << endl;
    }

    void informationAboutRoutes () {
        string destination;
        cout << "_________Введите пункт, чтобы узнать сведения о маршрутах_________ "<<endl;
        cin >> destination;
        for(int i = 0; i < n; i++){
            if((marsh[i].StartOfTheRoute == destination) || (marsh[i].EndOfTheRoute == destination)){
                print(marsh[i]);
            }
            else {
                cout<<"Маршруты не найдены"<<endl<<endl;
                break;
            }
        }
    }


    void ascendingRouteNum() {
        cout<<"_________Запись по возрастанию номеров маршрутов__________________"<<endl;
        vector<int> numMarsh;
        for(int i = 0; i< marsh.size(); ++i){
            numMarsh.push_back(marsh[i].RouteNumber);
        }
        sort(numMarsh.begin(), numMarsh.end());
        numMarsh.resize(unique(numMarsh.begin(),numMarsh.end())-numMarsh.begin());

        for(int i = 0; i < numMarsh.size();++i){
            for(int j = 0; j < marsh.size();++j){
                if(numMarsh[i] == marsh[j].RouteNumber){
                    cout << "Номер маршрута: " << marsh[j].RouteNumber << endl;
                    cout << "Начало маршрута: " << marsh[j].StartOfTheRoute << endl;
                    cout << "Конечная точка маршрута: " << marsh[j].EndOfTheRoute << endl;
                    cout << "Длина маршрута: " << marsh[j].RouteLength << endl;
                    cout << "***************************" << endl;
                    cout << endl;
                }
            }
        }
    }


 void routeMax() {
    int max = marsh[0].RouteLength;
    for (int i = 0; i < n; i++) {
            if ( marsh[i].RouteLength > max) {
                max = marsh[i].RouteLength;
            }
        }
    cout <<"_________Максимальная длина маршрута равна = "<< max << "__________________" << endl;
}

