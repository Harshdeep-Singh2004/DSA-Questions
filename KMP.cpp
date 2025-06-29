#include <bits/stdc++.h>
using namespace std;

void fillLPS(vector<int> &LPS, string &pattern) {

    int n = pattern.size();
    int i = 1;

    int len = 0;
    LPS[0] = 0;
    
    while(i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            LPS[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = LPS[len-1];
            } 
            else {
                i++;
            }
        }
    }
    
}

bool KMP(string &text, string &pattern, vector<int> &LPS) {
    int nt = text.size();
    int np = pattern.size();

    int i = 0; // text iterator
    int j = 0; // pattern iterator

    while (i < nt) {
        if (text[i] == pattern[j]) {
            i++;
            j++;

            if (j == np) {
                return 1;
            }
        }
        else {
            if (j != 0) {
                j = LPS[j-1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {
    string text = "geekdforgeeks";
    string pattern = "geeks";

    int np = pattern.size();

    // Find the LPS on pattern
    vector<int> LPS(np, 0);
    fillLPS(LPS, pattern);

    if (KMP(text, pattern, LPS)) {
        cout << "Pattern Found";
    }
    else {
        cout << "Pattern not Found";
    }
    
    return 0;
}
