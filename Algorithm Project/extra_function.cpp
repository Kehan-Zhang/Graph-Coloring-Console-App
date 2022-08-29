//
//  extra_function.cpp
//  Algorithm Project
//
//  Created by KEHAN ZHANG on 11/17/21.
//

#include "extra_function.hpp"
#include <iostream>
#include <random>
#include <array>

using namespace std;

void skewedRandomNumberGenerator(){
    default_random_engine generator;
    array<int,2> intervals {0, 10000};
    array<double,2> weights {10.0, 0.0};
    piecewise_linear_distribution<double> distribution (intervals.begin(),intervals.end(),weights.begin());
    
    int result[100] = {};
    for(int i = 0; i < 10000; i++) {
        int number = distribution(generator);
        result[number/100]++;
    }
    
    for (int i=0; i<100; i++) {
        cout << i << "-" << i+1 << ": ";
        cout << std::string(result[i]/10,'*') << endl;
    }
}
