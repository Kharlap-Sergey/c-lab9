// task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Train {
    char destinationName[20];
    int number;
    char departingTime[20];
    char arrivingTime[20];
};

char outFile[] = "3.dat";
ofstream out;

Train readTrain() {
    Train train;
    cout << "enter Name of destination...";
    getchar();
    cin.getline(train.destinationName, 20);
    cout << "enter departed time...";

    cin.getline(train.departingTime, 20);

    cout << "enter arrived time...";
    cin.getline(train.arrivingTime, 20);
  
    cout << "enter train number...";
    cin >> train.number;

    return train;
}

void Print(Train *train) {
    char buf[1000];
    snprintf(buf, sizeof(buf), "Name of destenition - %s\ndeparting time - %s\n\
arriving time - %s\ntrain's number - %d\n", train->destinationName,
train->departingTime, train->arrivingTime, train->number);
    puts(buf);
}

void PrintToFile(Train* train){
    char buf[1000];  
    snprintf(buf, sizeof(buf), "%s\n%s\n%s\n%d\n", train->destinationName,
        train->departingTime, train->arrivingTime, train->number);
    out << buf;
}

int main()
{
    out.open(outFile);

    cout << "enter amount pathes";
    int *n = new int;
    cin >> *n;
    out << *n << endl;

    Train* trainList = new Train[*n];

    for (int i = 0; i < *n; i++) {
        trainList[i] = readTrain();
        Print(&trainList[i]);
        PrintToFile(&trainList[i]);
    }

    delete[] trainList;
    delete n;
    out.close();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
