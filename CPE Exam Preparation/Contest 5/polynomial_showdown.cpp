#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& c) {
    string result = "";
    bool first = true;
    bool allZero = true;
    for(int i = 0; i < 9; i++) if(c[i]) { allZero = false; break; }
    
    for(int i = 0; i < 9; i++) {
        int deg = 8 - i;
        int coef = c[i];
        if(coef == 0) {
            if(allZero && deg == 0) result += "0";
            continue;
        }
        int absCoef = abs(coef);
        bool neg = coef < 0;
        
        if(first) {
            if(neg) result += "-";
            first = false;
        } else {
            result += neg ? " - " : " + ";
        }
        
        if(deg == 0) {
            result += to_string(absCoef);
        } else if(deg == 1) {
            if(absCoef != 1) result += to_string(absCoef);
            result += "x";
        } else {
            if(absCoef != 1) result += to_string(absCoef);
            result += "x^" + to_string(deg);
        }
    }
    cout << result << "\n";
}

int main() {
    string line;
    int lineNum = 0;
    map<int, vector<int>> buckets; // key = lineNum % 2, accumulates coeffs
    map<int, int> counts;
    
    while(getline(cin, line)) {
        istringstream iss(line);
        int x;
        int bucket = lineNum % 2;
        while(iss >> x) {
            buckets[bucket].push_back(x);
        }
        // check if this bucket now has 9 coefficients
        if(buckets[bucket].size() >= 9) {
            solve(buckets[bucket]);
            buckets[bucket].clear();
        }
        lineNum++;
    }
}