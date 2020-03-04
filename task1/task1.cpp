// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int mas[] = { 16,78,99,6,-29,19,-52,65,-88,51,
    -79,-22,32,-25,-62,-69,-2,-59,-75,89,
    -87,95,-22,85,-49,-75,76,73,-59,-52,
    30,9,-28,-48,0,57,-6,-85,0,-18,
    -97,-21,-95,64,22,-2,69,-84,-1,-71,
    -25,47,72,43,15,-44,44,61,4,74,
    88,-61,0,-64,-83,97,0,90,15,8,
    -54,19,73,35,-67,-87,85,-99,-70,10,
    98,58,-10,-29,95,62,77,89,36,-32,
    78,60,-79,-18,30,-13,-34,-92,1,-38 };
    int* masPointer = mas;

    int n, m;
    cout << "eter n and m....";
    cin >> n >> m;

    int* (*pointer) = new int* [n];

    for (int i = 0; i < n; i++)
        pointer[i] = new int[m];

    int k = 0;
    bool breackPoint = false;
    for (int i = 0; i < n; i++) {
        if (breackPoint) {
            break;
        }
        for (int j = 0; j < m; j++) {
            if (k == n * m) {

                breackPoint = true;
                break;
            }

            if (k < 100) pointer[i][j] = *(masPointer + k);
            else pointer[i][j] = 0;
            k++;
        }
    }


    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += pointer[i][j];
        }

        double average = (double)sum / (double)m;
        cout << average << endl;
    }



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
