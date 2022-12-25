#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

class load_config
{
private:
	map <string, string> key_value;

public:
	load_config() ;
	void load_config_parameter(string filename);
	int get_value_int(string key);
	string get_value_string(string key);
	int add_key_value(string key,string value);
	void display();
	~load_config();
};

