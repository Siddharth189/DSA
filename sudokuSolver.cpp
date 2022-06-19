#include <bits/stdc++.h>
using namespace std;

// BackTracking Sudoku Solver


bool isValid(vector<vector<int>> matrix,int i, int j, int k){
    if(i >= 9 || j >= 9) return 0;
    
    // Subgrid Boundries
    int n1 = (i/3) *3;
    int n2 = ((i+2)/3) *3;
    int m1 = (j/3) *3;
    int m2 = ((j+2)/3) *3;


    // Checking in subgrid
    for(int i = n1; i < n2; i++){
        for(int j = m1; j < m2; j++){
            if(matrix[i][j] == k) return 0;
        }
    }

    // Checking in row
    for(int i = 0; i < 9; i++){
        if(matrix[i][j] == k) return 0;
    }

    // Checking in col
    for(int j = 0; j < 9; j++){
        if(matrix[i][j] == k) return 0;
    }

    return 1;
}

void printMat(vector<vector<int>> matrix){
    for(auto u: matrix){
        for(auto x: u){
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool sudokuSolver(vector<vector<int>> matrix, int i,int j){
    // for changing the row
    if(j == 9){
        j = 0;
        i++;
    }

    // all the empty cells are filled
    if(i == 9) {
        printMat(matrix);
        return 1;
    }
    
    // if the cells is already filled we will skip to next position
    if((matrix[i][j] != 0)){
        return sudokuSolver(matrix,i,j+1);
    }
    

    // cells to be filled
    // we will try out all the possibility ---> 1...9
    for(int k = 1; k <= 9; k++){

        // check the subgrid, row, column
        if(isValid(matrix,i,j,k)){
            matrix[i][j] = k;
            bool success = sudokuSolver(matrix,i,j+1);
            if(success){
                return 1;
            }
        }
    }

    
    matrix[i][j] = 0;
    return 0;
}

int main(){

    int n = 9;
    vector<vector<int>> matrix{
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,0}
        };

    sudokuSolver(matrix,0,0);

    return 0;
}