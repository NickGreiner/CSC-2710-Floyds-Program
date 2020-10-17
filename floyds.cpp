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
#include <iterator>
#include <sstream>

using namespace std;

vector<vector<int>> floyd(vector<vector<int>> matrix);

vector<vector<int>> loadMatrix(string matrixFile);
void displayMatrix(vector<vector<int>> matrix);
// void writeMatrix(vector<vector<int>> matrix);

int main() {
  string matrixFile;
  vector<vector<int>> initial;
  vector<vector<int>> final;

  cout << "Enter matrix file: ";
  cin >> matrixFile;
  cout << endl;

  initial = loadMatrix(matrixFile);

  final = floyd(initial);

  cout << "Initial Matrix:" << endl;
  displayMatrix(initial);

  cout << "Final Matrix:" << endl;
  displayMatrix(final);

}

vector<vector<int>> floyd(vector<vector<int>> matrix) {
  vector<vector<int>> testMatrix = matrix;

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
  vector<vector<int>> matrix;

  ifstream ifs(matrixFile);
  string tempstr;
  int tempint;

  int edges, vertices;

  ifs >> vertices;
  ifs >> edges;

  while (getline(ifs, tempstr)) {
    istringstream iss(tempstr);
    vector<int> tempMatrix;
    while (iss >> tempint) {
      tempMatrix.push_back(tempint);
    }
    matrix.push_back(tempMatrix);
  }

  for (auto row : matrix) {
    for (auto el : row) {
      cout << el << ' ';
    }
    cout << "\n";
  }

  return matrix;
}

void displayMatrix(vector<vector<int>> matrix) {
  for (auto row : matrix) {
    for (auto el : row) {
      cout << el << ' ';
    }
    cout << "\n";
  }
}
