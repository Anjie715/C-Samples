#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <future>
#include "e2.h"

//create shortcut
namespace sc = std::chrono;
e2 e2;

int main() {

    std::vector<int> myVec (50000000);
    std::srand(0);

    //another, better option would be to use std::generate and a c++11ish random generator
    for(int i = 0; i < myVec.capacity(); ++i) {
        myVec[i] = std::rand() % 1000;
    }

    //http://en.cppreference.com/w/cpp/chrono
    auto start = sc::high_resolution_clock::now();

    int minVal;
    int maxVal;
    long sum;
    double average;

    //todo:  insert code here to populate these values
    //       the final execution time must be faster
    //       than what can be achieved with a single thread
    //      bonus points will be rewarded for fastest times

    //minVal = *min_element(myVec.begin(),myVec.end());
    std::future<double> f4 = std::async(std::launch::async, [&] {return e2._CallAvg(myVec);});
    std::future<int> f3 = std::async(std::launch::async, [&] {return e2._CallmaxVal(myVec);});
    std::future<int> f2 = std::async(std::launch::async, [&] {return e2._CallminVal(myVec);});
    std::future<long> f1 = std::async(std::launch::async, [&] {return e2._CallSum(myVec);});
    sum = f1.get();
    minVal = f2.get();
    maxVal = f3.get();
    average = f4.get();
    //maxVal = *max_element(myVec.begin(),myVec.end());
    //sum = accumulate(myVec.begin(), myVec.end(),0);
    //average = sum/myVec.size();

    auto end = sc::high_resolution_clock::now();

    std::cout << "Min: " << minVal << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    std::cout << "Elapsed Time: " << sc::duration_cast<sc::milliseconds>(end - start).count() << "ms" << std::endl;
}