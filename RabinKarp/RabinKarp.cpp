#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getHashNum(const string& textToHash, const int& b, const int& q, const int& patternLen){
    int total = 0;
    for(int i=0; i<patternLen; i++){
        //cout << "Char num: " << (int)textToHash.at(i);
        //cout << "     Multiplier: " << patternLen-1 -i << "\n";
        int part = textToHash.at(i) * pow(b, patternLen-1 - i);
        total += part;
    }
    return total % q;
}


int rabinKarp(const string& text, const string& pattern, const int& b, const int& q){
    int textLen = text.length();
    int patternLen = pattern.length();
    int textNum = getHashNum(text, b, q, patternLen);
    int patternNum = getHashNum(pattern, b, q, patternLen);
    int i=0;
    while(i < (textLen - patternLen)){
        cout << "Pattern num: " << patternNum;
        cout << "Text num: " << textNum;
        if(textNum == patternNum){
            //We have a spurious match
            //Go through and see if they are actually the same string
            int j=0;
            while(j < patternLen && (text.at(i+j) == pattern.at(j))){
                j++;
            }
            if(j == patternLen){
                return i;
            }
        }
        //This seems to be overflowing - probably the power part?
        int intermediate = pow(b, patternLen-1);
        cout << "\n\n" << intermediate;
        textNum = ((textNum - (text.at(i) * (pow(b, patternLen-1))) * b) + text.at(i+patternLen) % q);        
        i++;    
    }
    return -1;
}

int main(){
    string text;
    string pattern;
    cout << "Type in text: \n";
    getline(cin, text);
    cout << "Type in a pattern: \n";
    getline(cin, pattern);
    //q set to big prime number
    int index = rabinKarp(text, pattern, 256, 75571);
    if(index == -1){
        cout << "No match!";
    }else{
        cout << "Match found at index: " << index;
    }
}