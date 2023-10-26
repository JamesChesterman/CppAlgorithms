#include <iostream>
#include <string>

using namespace std;

int naiveMatch(string text, string pattern){
    int textLen = text.length();
    int patternLen = pattern.length();
    for(int i=0; i<(textLen - patternLen); i++){
        int j = 0;
        while(j < patternLen && (text.at(i+j) == pattern.at(j))){
            j++;
        }
        if(j == patternLen){
            return i;
        }
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
    int index = naiveMatch(text, pattern);
    if(index == -1){
        cout << "No match found!";
    }else{
        cout << "Match found at position: " << index;
    }
}