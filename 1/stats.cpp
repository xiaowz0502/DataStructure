//
//  stats.cpp
//  p1-stats
//
//  Created by 土豆 on 2022/1/15.
//

// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include "stats.h"
#include <cassert>
#include <vector>
#include "p1_library.h"
#include <cmath>
using namespace std;

vector<vector<double> > summarize(vector<double> v) {
  assert(!v.empty());
    vector<vector<double>> Summarized;
    sort(v);
    
    double Value;
    int i;
    int m;
    
    for (i = 0; i < static_cast<int>(v.size()); i++){
        Value = v.at(i);
        double Frequency = 1;
        for (m = i + 1; m < static_cast<int>(v.size()); m++){
            if (v.at(m) == v.at(i)){
                Frequency++;
                i++;
            }
        }
        Summarized.push_back({Value,Frequency});
        
    }
    
    return Summarized;
}

int count(vector<double> v) {
    int Number = static_cast<int>(v.size());
    return Number;
}

double sum(vector<double> v) {
    assert(!v.empty());
    double total = 0.0;
    for (int i = 0; i < static_cast<int>(v.size()); i++){
        total = total + v.at(i);
    }
    
    return total;
}

double mean(vector<double> v) {
    assert(!v.empty());
    double meanDouble = sum(v)/(double)count(v);
    return meanDouble;
}

double median(vector<double> v) {
    assert(!v.empty());
    
    sort(v);
    double medianDouble;
    
    if (static_cast<int>(v.size()) % 2 == 1){
        medianDouble = v.at((static_cast<int>(v.size()) + 1) / 2 - 1);
    }
    else{
        medianDouble = (v.at (static_cast<int>(v.size()) / 2 - 1) + v.at (static_cast<int>(v.size()) / 2)) / 2;
    }
    return medianDouble;
}

double mode(vector<double> v) {
    assert(!v.empty());
    sort(v);
    double modeDouble = v.at(0);
    double modeNumber;
    int MaxrepeatTime = 0;
    int repeatTime = 0;
    
    
    for (int i = 0; i < static_cast<int>(v.size()); i++){
        modeNumber = v.at(i);
        repeatTime = 0;
        for(int m = 0; m < static_cast<int>(v.size()); m++){
            if (v.at(m) == modeNumber){
                repeatTime++;
            }
        }
        
        if (repeatTime > MaxrepeatTime){
            modeDouble = v.at(i);
            MaxrepeatTime = repeatTime;
        }
    }
    return modeDouble;
}

double min(vector<double> v) {
    assert(!v.empty());
    sort(v);
    return v.at(0);
}

double max(vector<double> v) {
    assert(!v.empty());
    sort(v);
    return v.at(static_cast<int>(v.size()) - 1);
    
}

double stdev(vector<double> v) {
    assert(static_cast<int>(v.size()) >= 2);
    double stdevNumber;
    double total = 0;
    for (int i = 0; i < static_cast<int>(v.size()); i++){
        total = total + pow(v.at(i) - mean(v),2);
    }
    stdevNumber = sqrt((1.0 / (double)(static_cast<int>(v.size()) - 1)) * total);
    
    return stdevNumber;
}

double percentile(vector<double> v, double p) {
    assert(!v.empty());
    assert(p >= 0 && p <= 1);
    sort(v);
    double percentileNumber;
    double n;
    double fractpart = 0;
    double intpart = 0;
    
    if (p == 1){
        percentileNumber = v.at(static_cast<int>(v.size()) - 1);
    }
    else{
        n = p * (static_cast<int>(v.size()) - 1) + 1;
        fractpart = modf(n , &intpart);
        percentileNumber = v.at(intpart - 1) + fractpart * (v.at(intpart) - v.at(intpart - 1));
    }
   
    return percentileNumber;
}
