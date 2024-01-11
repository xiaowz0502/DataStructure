//
//  main.cpp
//  p1-stats
//
//  Created by 土豆 on 2022/1/15.
//

// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string filename;
    string columnName;
    
    cout << "enter a filename" << endl;
    cin >> filename;
    cout << "enter a column name" << endl;
    cin >> columnName;
    cout<< "reading column " << columnName << " from " << filename << endl;
    vector<double> extractedVector = extract_column(filename, columnName);
    cout << "Summary (value: frequency)" << endl;
    
    vector<vector<double> > summarizedVector = summarize(extractedVector);
    for (int i = 0; i < static_cast<int>(summarizedVector.size()); i++){
        cout << summarizedVector[i][0] << ": " << summarizedVector[i][1];
        cout << endl;
        }
    cout << endl;
    cout << "count = " << count(extractedVector) << endl;
    cout << "sum = " << sum(extractedVector) << endl;
    cout << "mean = " << mean(extractedVector) << endl;
    cout << "stdev = " << stdev(extractedVector) << endl;
    cout << "median = " << median(extractedVector) << endl;
    cout << "mode = " << mode(extractedVector) << endl;
    cout << "min = " << min(extractedVector) << endl;
    cout << "max = " << max(extractedVector) << endl;
    cout << "  0th percentile = " << percentile(extractedVector, 0) << endl;
    cout << " 25th percentile = " << percentile(extractedVector, 0.25) << endl;
    cout << " 50th percentile = " << percentile(extractedVector, 0.5) << endl;
    cout << " 75th percentile = " << percentile(extractedVector, 0.75) << endl;
    cout << "100th percentile = " << percentile(extractedVector, 1) << endl;

    }

