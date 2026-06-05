#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> dict;
    string word;
    while(cin >> word && word != "XXXXXX")
        dict.push_back(word);
    
    while(cin >> word && word != "XXXXXX") {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        
        vector<string> matches;
        for(auto& w : dict) {
            string sortedW = w;
            sort(sortedW.begin(), sortedW.end());
            if(sortedW == sortedWord) matches.push_back(w);
        }
        
        sort(matches.begin(), matches.end());
        if(matches.empty()) cout << "NOT A VALID WORD\n";
        else for(auto& m : matches) cout << m << "\n";
        cout << "******\n";
    }
}