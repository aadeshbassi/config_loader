#include "load_config.h"
#include <fstream>
#include <cstdlib>
load_config::load_config() :key_value{} {}

void load_config::load_config_parameter(string filename)
{
	ifstream in_file;
	in_file.open(filename);
	if (in_file.is_open())
	{
		string line{};
		while (!in_file.eof())
		{
			string key{}, value{};
			bool skip_flag{};
			getline(in_file,line,'=');
			for (char c : line)
			{
				if (c == '#')
				{
					skip_flag = true;
					break;
				}
				else if (isalnum(c)||c=='_')
					key += c;
				
			}
			getline(in_file,line);
			for (char c : line)
			{
				if ((value.empty() && c == '#') )
				{
					skip_flag = true;
					break;
				}
				else if (c == '#')
				{
					break;
				}
				else if(isalnum(c) ||c=='_')
					value+= c;
				
			}

			if (skip_flag)
			{
				cout << "Skipping !!!" << endl;
				continue;
			}
			int result = add_key_value(key, value);
			if (result)	cout << "Key Value pair added : "<<key<<"\t"<<value<< endl;
			else cout << "Key Already exists" << endl;
		}
	}
	else
	{
		cout << "File does not Exists !!!" << endl;
	}

}
int load_config::get_value_int(string key) 
{
	if (key_value[key].empty())
	{
		cout << "Value does not exists" << endl;
		return 0;
	}
	else
	{
		return stoi(key_value[key]);
	}
}
string load_config::get_value_string(string key) 
{
	if (key_value[key].empty())
	{
		cout << "Value does not exists" << endl;
		return " ";
	}
	else
	{
		return key_value[key];
	}
}
int load_config::add_key_value(string key,string value)
{
	if (key_value[key].empty())
	{
		key_value[key] = value;
		return 1;
	}
	else
	{
		return 0;
	}
}
void load_config::display()
{
	cout << "THe Key Value pair is:" << endl;
	for (auto i : key_value)
	{
		cout <<"Key :" <<i.first << "\tValue :"<<i.second << endl;
	}
}

load_config::~load_config() {
	key_value.clear();
}