//
// Created by Brian Swenson on 2/8/18.
//
#include <iostream>
#include <vector>
#include <algorithm>

#include "e2.h"

using namespace std;

int e2::_CallminVal(std::vector<int> myVec){
    min = *min_element(myVec.begin(),myVec.end());
    return min;
}

int e2::_CallmaxVal(std::vector<int> myVec){
    max = *max_element(myVec.begin(),myVec.end());
    return max;
}

long e2::_CallSum(std::vector<int> myVec){
    for (int i = 0; i < 50000000; i++) {
        sum += myVec[i];
    }
    return sum;
}

double e2::_CallAvg(std::vector<int> myVec) {
    for (int i = 0; i < 50000000; i++) {
        sum += myVec[i];
    }
    avg = sum/myVec.size();
    return avg;
}