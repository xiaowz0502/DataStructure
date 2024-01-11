/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include "p1_library.h"
#include <cmath>
#include <limits>
using namespace std;

void test_sum_small_data_set();
void test_summarize_function();
void test_count_function();
void test_sum_function();
void test_mean_function();
void test_median_function();
void test_mode_function();
void test_max_function();
void test_min_function();
void test_stdev_function();
void test_percentile_function();
// Add prototypes for you test functions here.

int main() {
    test_sum_small_data_set();
  // Call your test functions here
    test_summarize_function();
    test_count_function();
    test_sum_function();
    test_mean_function();
    test_median_function();
    test_mode_function();
    test_max_function();
    test_min_function();
    test_stdev_function();
    test_percentile_function();
  return 0;
}

void test_sum_small_data_set() {
    cout << "test_sum_small_data_set" << endl;

    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);

    assert(sum(data) == 6);

    cout << "PASS!" << endl;
  }


void test_summarize_function(){
    cout << "test_summarize_fuction start" << endl;
    vector<double> v1 = {2, 2, 2, 2, 2};
    vector<vector<double>> test1 = summarize(v1);
    vector<vector<double>> test1expected = {{2,5}};
    assert(test1 == test1expected);
    
    vector<double> v2 = {1, 2, 3, 4, 5};
    vector<vector<double>> test2 = summarize(v2);
    vector<vector<double>> test2expected = {{1,1}, {2,1}, {3,1}, {4,1}, {5,1}};
    assert(test2 == test2expected);
    
    vector<double> v3 = {1, 2, 2, 2, 5};
    vector<vector<double>> test3 = summarize(v3);
    vector<vector<double>> test3expected = {{1,1}, {2,3}, {5,1}};
    assert(test3 == test3expected);

     vector<double> v4 = {1, 2, 2, 5, 5};
     vector<vector<double>> test4 = summarize(v4);
     vector<vector<double>> test4expected = {{1,1}, {2,2}, {5,2}};
     assert(test4 == test4expected);


    vector<double> v5 = {5,1,2,5,2};
    vector<vector<double>> test5 = summarize(v5);
    vector<vector<double>> test5expected = {{1,1}, {2,2}, {5,2}};
    assert(test5 == test5expected);
    
    vector<double> v6 = {5,5,4.5,3,2.4,6,7.8,54};
    vector<vector<double>> test6 = summarize(v6);
    vector<vector<double>> test6expected = {{2.4, 1}, {3, 1},{4.5, 1}, {5, 2}, {6, 1}, {7.8,1},{54, 1}};
    assert(test6 == test6expected);
    
    vector<double> v7 = {5,69,4.5,3,2.4,6,7.8,54,-12};
    vector<vector<double>> test7 = summarize(v7);
    vector<vector<double>> test7expected = {{-12,1},{2.4, 1}, {3, 1},{4.5, 1}, {5, 1}, {6, 1}, {7.8,1},{54, 1},{69,1}};
    assert(test7 == test7expected);
    
    vector<double> v8 = {-12,-5.6,-7,-13,-54,-7,-1,-7,-13};
    vector<vector<double>> test8 = summarize(v8);
    vector<vector<double>> test8expected = {{-54,1},{-13, 2}, {-12, 1},{-5.6, 1}, {-7, 3}, {-1, 1}};
    assert(test7 == test7expected);
    
    cout << "PASS!" << endl;
}

void test_count_function(){
    cout<<"test_count_function start"<<endl;
    vector<double> v1 = {};
    assert(count(v1) == 0);
    
    vector<double> v2 = {1,2,3,4,5,6};
    assert(count(v2) == 6);
    
    vector<double> v3 = {2,2,2,2,2,2,2,2};
    assert(count(v3) == 8);
    
    cout << "PASS!" << endl;
    
}

void test_sum_function(){
    cout << "test_sum_function start"<<endl;
    const double epsilon = 0.00001;
    
    vector<double> v1 = {0,0,0,0,0};
    assert(sum(v1) == 0);
    
    vector<double> v2 = {-1.2,-5,-98,-1.8,-12};
    assert(sum(v2) - (-118) < epsilon);
    
    vector<double> v3 = {5,5.9,2490,3,5};
    assert(sum(v3) - 2508.9 < epsilon);
    
    vector<double> v4 = {5,-9.8,13,-20.5,5};
    assert(sum(v4) - (-7.3) < epsilon);
    
    vector<double> v5 = {5, 23.4, -19.7, 8.6 ,5};
    assert(sum(v5) - 22.3 < epsilon);
    
}

void test_mean_function(){
    cout << "test_mean_function start" << endl;
    const double epsilon = 0.00001;
    vector<double> v1 = {0,0,0,0,0};
    assert(mean(v1) == 0);
    
    vector<double> v2 = {-1.2,-5,-98,-1.8,-12};
    assert(mean(v2) - (23.6) < epsilon);
    
    vector<double> v3 = {5,5.9,2490,3,5};
    assert(mean(v3) - 501.78 < epsilon);
    
    vector<double> v4 = {5,-9.8,13,-20.5,5};
    assert(mean(v4) - (-1.46) < epsilon);
    
    vector<double> v5 = {5, 23.4, -19.7, 8.6 ,5};
    assert(mean(v5) - 4.46 < epsilon);
    
    vector<double> v6 = {0.5, 0.4, 0.1};
    assert(mean(v6) - 0.333333 < epsilon);
    
    cout << "PASS!" << endl;
}

void test_median_function(){
    cout << "test_median_function start" << endl;
    const double epsilon = 0.00001;
    vector<double> v1 = {0,0,0,0,0};
    assert(median(v1) == 0);
    
    vector<double> v2 = {-1.2,-5,-98,-1.8,-12};
    assert(median(v2) == -5);
    
    vector<double> v3 = {1, 2, 3, 4, 5, 6};
    assert(median(v3) - 3.5 < epsilon);
    
    vector<double> v4 = {5};
    assert(median(v4) == 5);
    
    vector<double> v5 = {1, 2};
    assert(median(v5) - 1.5 < epsilon);
    
    vector<double> v6 = {1.5, 2.5};
    assert(median(v6) - 2.0 < epsilon);
    
    vector<double> v7 = {11,189,1.5, 2.5, 4.8,};
    assert(median(v7) - 4.8 < epsilon);
    cout << "PASS!" << endl;
}

void test_mode_function(){
    cout << "test_mode_function start" << endl;
    vector<double> v1 = {0,0,0,0,0};
    assert(mode(v1) == 0);
    
    vector<double> v2 = {1,2,1,2};
    assert(mode(v2) == 1);
    
    vector<double> v3 = {1,2,2,2,1};
    assert(mode(v3) == 2);
    
    vector<double> v4 = {1,2,3};
    assert(mode(v4) == 1);
    
    vector<double> v5 = {2,2,1,1};
    assert(mode(v5) == 1);
    
    vector<double> v6 = {1,1,2,2};
    assert(mode(v6) == 1);
    
    vector<double> v7 = {5};
    assert(mode(v7) == 5);
    
    vector<double> v8 = {3,4,5,9,9,9,12,12,12,1234,1,1,1,1,1,1};
    assert(mode(v8) == 1);
    
    vector<double> v9 = {2,1,2,1};
    assert(mode(v9) == 1);
    cout << "PASS!" << endl;
}

void test_max_function(){
    cout << "test_max_function start" << endl;
    vector<double> v1 = {0,0,0,0,0};
    assert(max(v1) == 0);
    
    vector<double> v2 = {-1.2,-5,-98,-1.8,-12};
    assert(max(v2) == -1.2);
    
    vector<double> v3 = {5,5.9,2490,3,5};
    assert(max(v3) == 2490);
    
    vector<double> v4 = {5,-9.8,13,-20.5,5};
    assert(max(v4) == 13);
    
    vector<double> v5 = {5, 23.4, -19.7, 8.6 ,5};
    assert(max(v5) == 23.4);
    cout << "PASS!" << endl;
    
}
void test_min_function(){
    cout << "test_min_function start" << endl;
    vector<double> v1 = {0,0,0,0,0};
    assert(min(v1) == 0);
    
    vector<double> v2 = {-1.2,-5,-98,-1.8,-12};
    assert(min(v2) == -98);
    
    vector<double> v3 = {5,5.9,2490,3,5};
    assert(min(v3) == 3);
    
    vector<double> v4 = {5,-9.8,13,-20.5,5};
    assert(min(v4) == -20.5);
    
    vector<double> v5 = {5, 23.4, -19.7, 8.6 ,5};
    assert(min(v5) == -19.7);
    cout << "PASS!" << endl;
}

void test_stdev_function(){
    cout << "stdev_min_function start" << endl;
    const double epsilon = 0.00001;
    
    vector<double> v1 = {0,0,0,0,0};
    assert(stdev(v1) == 0);
    
    vector<double> v2 = {-1.2,-5,-98,-1.8,-12};
    assert(stdev(v2) - 41.811720844758 < epsilon);
    
    vector<double> v3 = {5,5.9,2490,3,5};
    assert(stdev(v3) - 1111.4492754957 < epsilon);
    
    vector<double> v4 = {5,-9.8,13,-20.5,5};
    assert(stdev(v4) - 13.459494789924 < epsilon);
    
    vector<double> v5 = {5, 23.4, -19.7, 8.6 ,5};
    assert(stdev(v5) - 15.493159781013 < epsilon);
    
    vector<double> v6 = {5, 23, -19, 8 ,5};
    assert(stdev(v6) - 15.059880477613 < epsilon);
    
    vector<double> v7 = {5.8, 23.114, -19.768, 8.675, 5.86};
    assert(stdev(v7) - 15.460498801785 < epsilon);
    cout << "PASS!" << endl;
}

void test_percentile_function(){
    cout << "percentile_min_function start" << endl;
    const double epsilon = 0.00001;
    
    vector<double> v1 = {0,0,0,0,0};
    assert(percentile(v1, 0.7) == 0);
    
    vector<double> v2 = {-1.2,-5,-98,-1.8,-12};
    assert(percentile(v2, 0.89) - (-1.464) < epsilon);
    
    vector<double> v3 = {5,5.9,2490,3,5};
    assert(percentile(v3, 0.24) - 4.92 < epsilon);
    assert(percentile(v3, 0) - 3 < epsilon);
    assert(percentile(v3, 1) - 2490 < epsilon);
    
    vector<double> v4 = {5,-9.8,13,-20.5,5};
    assert(percentile(v4, 0.74) - (5) < epsilon);
    
    vector<double> v5 = {5, 23.4, -19.7, 8.6 ,5};
    assert(percentile(v5, 0) - (-19.7) < epsilon);
    
    vector<double> v6 = {54, 90.8, -100.46, 87.52, 43.99};
    assert(percentile(v6, 1) - ( 90.8) < epsilon);
    
    vector<double> v7 = {54, 90, -100, 87, 43};
    assert(percentile(v7, 0.95) - ( 89.4) < epsilon);
    
    cout << "PASS!" << endl;
}
// Add the test function implementations here.
