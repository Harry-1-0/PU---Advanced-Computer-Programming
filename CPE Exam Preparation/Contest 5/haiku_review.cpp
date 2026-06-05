#include <bits/stdc++.h>
using namespace std;

int countSyllables(const string& word) {
    int count = 0;
    bool inVowel = false;
    string vowels = "aeiouy";
    for(char c : word) {
        if(vowels.find(c) != string::npos) {
            if(!inVowel) { count++; inVowel = true; }
        } else {
            inVowel = false;
        }
    }
    return count;
}

int countLineSyllables(const string& line) {
    int total = 0;
    istringstream iss(line);
    string word;
    while(iss >> word) total += countSyllables(word);
    return total;
}

int main() {
    string line;
    while(getline(cin, line)) {
        // split by '/'
        vector<string> parts;
        string cur = "";
        for(char c : line) {
            if(c == '/') { parts.push_back(cur); cur = ""; }
            else cur += c;
        }
        parts.push_back(cur);
        
        // end condition
        if(parts.size() == 3 && parts[0]=="e" && parts[1]=="o" && parts[2]=="i") break;
        
        int expected[] = {5, 7, 5};
        int wrong = -1;
        for(int i = 0; i < 3; i++) {
            if(countLineSyllables(parts[i]) != expected[i]) {
                wrong = i+1;
                break;
            }
        }
        if(wrong == -1) cout << "Y\n";
        else cout << wrong << "\n";
    }
}