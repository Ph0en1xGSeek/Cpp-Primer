#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>

using namespace std;

int sum_i(vector<string> &nums) {
    int sum = 0;
    for(string &str: nums) {
        sum += stoi(str);
    }
    return sum;
}

float sum_f(vector<string> &nums) {
    float sum = 0.0;
    for(string &str: nums) {
        sum += stof(str);
    }
    return sum;
}


int main() {
    vector<string> nums_i = {"1", "2", "3", "4", "5"};
    vector<string> nums_f = {"1.1", "2.2", "3.3"};
    int i_sum = sum_i(nums_i);
    float f_sum = sum_f(nums_f);
    cout << i_sum << ' ' << f_sum << endl;
    return 0;
}