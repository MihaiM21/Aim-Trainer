
#ifndef INIREADER_H
#define INIREADER_H

#include <iostream>
#include <fstream>

using namespace std;


class reader
{
public:
	ifstream f;
	float iniParseFloat(const string& KeyArgs);
    int iniParseInt(const string& KeyArgs);
    string iniParseString(const string KeyArgs);
	void _init_reader();
private:

};

void reader::_init_reader() {
	reader::f.open("config.ini");
}
string reader::iniParseString(const string KeyArgs) {
    string data, config = "";
    bool dif = false;
    while (getline(f, data)) {
        dif = false;
        if (data.find(KeyArgs) != string::npos) {
            size_t equalPos = data.find('=');
            config = data.substr(equalPos + 1);
            break;
        }
    }
    f.clear();
    f.seekg(0);
    return config;
    
}

float reader::iniParseFloat(const string& KeyArgs) {
    string data, config = "";
    bool dif = false;
    while (getline(f, data)) {
        dif = false;
        if (data.find(KeyArgs) != string::npos) {
            size_t equalPos = data.find('=');
            config = data.substr(equalPos + 1);
            break;
        }
    }
    f.clear();
    f.seekg(0);
    return stof(config);
}
int reader::iniParseInt(const string& KeyArgs) {
    string data, config = "";
    bool dif = false;
    while (getline(f, data)) {
        dif = false;
        if (data.find(KeyArgs) != string::npos) {
            size_t equalPos = data.find('=');
            config = data.substr(equalPos + 1);
            break;
        }
    }
    f.clear();
    f.seekg(0);
    return stoi(config);
}

#endif