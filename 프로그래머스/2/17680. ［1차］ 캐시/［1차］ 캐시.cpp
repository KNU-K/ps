#include <deque>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string toUpperString(const std::string& str) {
    std::string upperStr = str;
    for (char& c : upperStr) {
        c = std::toupper(c);
    }
    return upperStr;
}

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) return cities.size() * 5;

    unordered_set<string> cacheSet;
    deque<string> cache;
    int answer = 0;

    for (auto city : cities) {
        string cityUpper = toUpperString(city);
        if (cacheSet.find(cityUpper) != cacheSet.end()) {
            // Cache hit
            answer += 1;
            // Move the accessed city to the end of the cache
            cache.erase(remove(cache.begin(), cache.end(), cityUpper), cache.end());
            cache.push_back(cityUpper);
        } else {
            // Cache miss
            answer += 5;
            if (cache.size() == cacheSize) {
                // Remove the least recently used item from the cache
                cacheSet.erase(cache.front());
                cache.pop_front();
            }
            cache.push_back(cityUpper);
            cacheSet.insert(cityUpper);
        }
    }

    return answer;
}