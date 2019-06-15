#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

void println(vector<string> &vec){
    for(auto item: vec) {
        cout << item << ' ';
    }
    cout << endl;
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &vec) {
    stable_sort(vec.begin(), vec.end());
    unique(vec.begin(), vec.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    println(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) -> bool {
        return a.size() < b.size();
    });
    println(words);
    auto wc = partition(words.begin(), words.end(), [sz](const string &a) -> bool {
        return a.size() >= sz;
    });
    for_each(words.begin(), wc, 
        [](const string & s){
            cout << s << " ";
        });
    cout << endl;
}

void biggies_stable(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    println(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) -> bool {
        return a.size() < b.size();
    });
    println(words);
    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &a) -> bool {
        return a.size() >= sz;
    });
    for_each(words.begin(), wc, 
        [](const string & s){
            cout << s << " ";
        });
    cout << endl;
}


int main() {
    vector<string> vec = {"aaa", "b", "b", "ccdccccc", "sdfjhsdgf", "aaa", "dfdfdd", "abcs"};
    println(vec);
    biggies_stable(vec, 4);
}
 
 