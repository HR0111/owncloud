#include <iostream>
#include <map>
#include <string>
#include<bits/stdc++.h>
using namespace std;

map<string, string> knowledgeBase = {
    {"name", ""},
    {"age", ""},
    {"occupation", ""},
    {"hobby", ""},
};

void infer() {
    if (!knowledgeBase["name"].empty()) {
        cout << "Hello, " << knowledgeBase["name"] << "!" << endl;
    }
    if (!knowledgeBase["age"].empty()) {
        cout << "You are " << (stoi(knowledgeBase["age"]) >= 18 ? "an adult" : "a minor") << "." << endl;
    }
    if (!knowledgeBase["hobby"].empty()) {
        cout << "Your hobby is " << knowledgeBase["hobby"] << "." << endl; 
    }
}

int main() {
    cout << "Welcome to the Expert System for Information Management!" << endl;

    for (map<string, string>::iterator it = knowledgeBase.begin(); it != knowledgeBase.end(); ++it) {
        if (it->second.empty()) {
            cout << "What is your " << it->first << "? ";
            getline(cin, it->second);
        }
    }

    infer();

    cout << "Thank you for using the Expert System!" << endl;

    return 0;
}
