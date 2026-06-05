#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int tc = 1;

    while (cin >> s && s != "#") {
        string lang;

        if (s == "HELLO")
            lang = "ENGLISH";
        else if (s == "HOLA")
            lang = "SPANISH";
        else if (s == "HALLO")
            lang = "GERMAN";
        else if (s == "BONJOUR")
            lang = "FRENCH";
        else if (s == "CIAO")
            lang = "ITALIAN";
        else if (s == "ZDRAVSTVUJTE")
            lang = "RUSSIAN";
        else
            lang = "UNKNOWN";

        cout << "Case " << tc++ << ": " << lang << "\n";
    }

    return 0;
}