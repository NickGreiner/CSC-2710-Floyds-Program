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

using namespace std;

void floyd(vector<vector<int>> &matrix, vector<vector<int>> &returnMatrix, vector<vector<int>> &pathMatrix);

vector<vector<int>> loadMatrix(string matrixFile);
void displayMatrix(vector<vector<int>> &matrix);
void printPaths(int q, int r, vector<vector<int>> &pathMatrix);

vector<vector<int>> paths;

#define INFINITY 2000

int main() {
  string matrixFile;
  vector<vector<int>> initial;
  vector<vector<int>> final;

  cout << "Enter matrix file: ";
  cin >> matrixFile;
  cout << endl;

  initial = loadMatrix(matrixFile);

  vector<int> pathRow(initial.size(), 0);
  vector<vector<int>> path(initial.size(), pathRow);

  cout << "Initial Matrix:" << endl;
  displayMatrix(initial);

  floyd(initial, final, path);

  cout << "Final Matrix:" << endl;
  displayMatrix(final);

  if (paths.size() > 0) {
    cout << "Paths:" << endl;
    for (int z = 0; z < paths.size(); z++) {
      cout << "Path from v" << paths[z][0] << " to v" << paths[z][1] << " ==> ";
      cout << "v" << paths[z][0] << " ";
      printPaths(paths[z][0] - 1, paths[z][1] - 1, path);
      cout << "v" << paths[z][1];
      cout << endl;
    }
  }

  return 0;
}

void floyd(vector<vector<int>> &matrix, vector<vector<int>> &returnMatrix, vector<vector<int>> &pathMatrix) {
  int i, j, k;
  int n = matrix.size();

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      pathMatrix[i][j] = 0;
    }
  }

  returnMatrix = matrix;

  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (returnMatrix[i][k] + returnMatrix[k][j] < returnMatrix[i][j]) {
          pathMatrix[i][j] = k;
          returnMatrix[i][j] = returnMatrix[i][k] + returnMatrix[k][j];
        }
      }
    }
  }
}

vector<vector<int>> loadMatrix(string matrixFile) {
  vector<vector<int>> matrix;

  ifstream infile(matrixFile);

  int vertices, edges;

  string v1, v2;
  int weight;

  infile >> vertices;
  infile >> edges;

  for (int j = 0; j < vertices; j++) {
    vector<int> matrixRow;
    for (int k = 0; k < vertices; k++) {
      if (j == k) {
        matrixRow.push_back(0);
      }
      else {
        matrixRow.push_back(INFINITY);
      }
    }
    matrix.push_back(matrixRow);
  }

  for (int i = 0; i < edges; i++) {
    infile >> v1 >> v2 >> weight;

    int intv1 = v1[1] - 48;
    int intv2 = v2[1] - 48;

    matrix[intv1 - 1][intv2 - 1] = weight;
  }

  if (infile.eof()) {
    return matrix;
  }

  else {
    int pathsToPrint;

    infile >> pathsToPrint;

    for (int i = 0; i < pathsToPrint; i++) {
      vector<int> p;
      infile >> v1 >> v2;

      int intv1 = v1[1] - 48;
      int intv2 = v2[1] - 48;

      p.push_back(intv1);
      p.push_back(intv2);
      paths.push_back(p);
    }
  }

  return matrix;
}

void displayMatrix(vector<vector<int>> &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

void printPaths(int q, int r, vector<vector<int>> &pathMatrix) {
  if (pathMatrix[q][r] != 0) {
    printPaths(q, pathMatrix[q][r], pathMatrix);
    cout << "v" << pathMatrix[q][r] + 1 << " ";
    printPaths(pathMatrix[q][r], r, pathMatrix);
  }
}
