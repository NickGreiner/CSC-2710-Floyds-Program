/*
Name: Floyd's Algorithm Project
Author:  Nick Greiner
Class:  CSC-2710-01
Date:   10/16/2020

Description:  Program to implement Floyd's Algorithm.

https://github.com/NickGreiner/CSC-2710-Floyds-Program
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> floyd(vector<vector<int>> matrix);

vector<vector<int>> loadMatrix(string matrixFile);
void displayMatrix(vector<vector<int>> matrix);
// void writeMatrix(vector<vector<int>> matrix);

int main {
  string matrixFile;
  vector<vector<int>> initial;
  vector<vector<int>> final;

  cout << "Enter matrix file: ";
  cin >> matrixFile;
  cout << endl;

  initial = loadMatrix(matrixFile);

  final = floyd(initial);

  cout << "Initial Matrix:" << endl;
  displayMatrix(inital);

  cout << "Final Matrix:" << endl;
  displayMatrix(final);

}

vector<vector<int>> floyd(vector<vector<int>> matrix) {
  vector<vector<int>> testMatrix = vector<vector<int>> matrix;

  int i, j, k;
  int n = testMatrix.size();

  for (k = 1; k <= n; k++) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        testMatrix[i][j] = min(testMatrix[i][j], testMatrix[i][k] + testMatrix[k][j]);
      }
    }
  }

  return testMatrix;
}

vector<vector<int>> loadMatrix(string matrixFile) {
  
}
