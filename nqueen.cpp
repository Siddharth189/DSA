#include <bits/stdc++.h>
using namespace std;

// BackTracking N Queen
int n = 8;
vector<vector<bool>> matrix(n,vector<bool> (n,0));

bool isValid(int i1, int j1){
    int i = i1,j = j1;
    if(i >= n || j >= n) return 0;
    
    // checking left daigonal
    i = i1,j = j1;
    while(i >= 0){
        if(matrix[i--][j] != 0) return 0;
    }

    // checking column
    i = i1,j = j1;
    while(i >= 0 && j < n){
        if(matrix[i--][j++] != 0) return 0;
    }

    // checking right daigonal
    i = i1,j = j1;
    while(i >= 0 && j >= 0){
        if(matrix[i--][j--] != 0) return 0;
    }


    return 1;
}

void printMat(){
    for(auto u: matrix){
        for(auto x: u){
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool check_nqueen(int i){

	// Base Case 
    if(i == n) {
        printMat();
        return 1;
    }

    // filling the current row --> i
    for(int j = 0; j < n; j++){

    	// check the particular cell --> i,j 
        if(isValid(i,j)){
            matrix[i][j] = 1;
            bool success = check_nqueen(i+1);
            // Success will return that whether we will get the solution by putting a queen at (i,j) 
            // if we are getting the solution then okay other wise we will remove the q from this column and check for next columns
            if(success){
                return 1;
            }
            matrix[i][j] = 0;
        }
    }
    return 0;
}

int cnt = 0;

bool all_nqueen(int i){

	// Base Case 
    if(i == n) {
        cnt++;
        printMat();
        return 1;
    }

    // filling the current row --> i
    for(int j = 0; j < n; j++){

    	// check the particular cell --> i,j 
        if(isValid(i,j)){
            matrix[i][j] = 1;
            bool success = all_nqueen(i+1);
            // Success will return that whether we will get the solution by putting a queen at (i,j) 
            // if we are getting the solution then okay other wise we will remove the q from this column and check for next columns
            // if(success){
            //     return 1;
            // }
            matrix[i][j] = 0;
        }
    }
    return 0;
}

int main(){
    // int n;
    // cin >> n;

    if(check_nqueen(0)){
    	cout << "Yes " << n << " queens can be placed such that no queen is attacking other queens\n";
    }
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = 0;
		}
	}

    all_nqueen(0);
    cout << "\nTotal number of such positions are: " << cnt;

    return 0;
}
/******************************************************************************************************/
