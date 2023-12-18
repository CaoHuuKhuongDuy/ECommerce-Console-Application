#include "HandleStringData.h"

string HandleStringData::loadString(ifstream &file) {
    int length;
    file.read((char*)&length, sizeof(int));
    char *str = new char[length + 1];
    file.read(str, length);
    str[length] = '\0';
    string result = str;
    delete[] str;
    return result;
}

void HandleStringData::saveString(ofstream &file, string &str) {
    int length = str.size();
    file.write((char*)&length, sizeof(int));
    file.write(str.c_str(), length);
}