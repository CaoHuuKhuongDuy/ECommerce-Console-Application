#pragma once 
#include <iostream>
#include <fstream>

using namespace std;

class HandleStringData {
    public:
        static string loadString(ifstream &file);
        static void saveString(ofstream &file, string &str);
};