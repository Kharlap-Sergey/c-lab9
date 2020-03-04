﻿#include <iostream>
#include <fstream>
using namespace std;

ifstream in;
char readFile[] = "3.dat";

struct Train {
    char destinationName[20];
    int number;
    char departingTime[20];
    char arrivingTime[20];
};

Train readTrain() {
    Train train;
    char boof[2];
    in.getline(boof, 2);
    //cout << "enter Name of destination...";
    //in.getchar();
    in.getline(train.destinationName, 20);
    //cout << "enter departed time...";

    in.getline(train.departingTime, 20);

    //cout << "enter arrived time...";
    in.getline(train.arrivingTime, 20);

    //cout << "enter train number...";
    in >> train.number;

    return train;
}

void Print(Train* train) {
    char buf[1000];
    snprintf(buf, sizeof(buf), "Name of destenition - %s\ndeparting time - %s\n\
arriving time - %s\ntrain's number - %d\n", train->destinationName,
train->departingTime, train->arrivingTime, train->number);
    puts(buf);
}

void GetherByDestinatio(Train *trains, int *n) {

    bool* used = new bool[*n];
    //cout << *n;
    for (int i = 0; i < *n; i++) used[i] = false;

    for (int i = 0; i < *n; i++) {
        if (used[i]) continue;

        cout << trains[i].destinationName << endl;
        for (int j = i; j < *n; j++) {
            if (strcmp(trains[i].destinationName, trains[j].destinationName) == 0) {
                used[j] = true;
                Print(&trains[j]);
            }
        }
        cout << endl;
    }

    delete[] used;
}

int main()
{
    in.open(readFile);

    int *n = new int;
    in >> *n;
    //cout << *n;
    Train* trainList = new Train[*n];

    for (int i = 0; i < *n; i++) {
        trainList[i] = readTrain();
        //Print(&trainList[i]);
    }

    GetherByDestinatio(trainList, n);

    in.close();
    delete n;
    delete[] trainList;
    return 0;
}

