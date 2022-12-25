#include <iostream>
#include "load_config.h"
using namespace std;

int main()
{
	string file_name{}, key{};
	cout << "Enter the File name of the config file :" << endl;
	cin >> file_name;
	load_config * c = new load_config();
	c->load_config_parameter(file_name);
	
	c->display();

	cout << "Enter the key :" << endl;
	cin >> key;
	string result =c->get_value_string(key);
	cout <<"value :"<< result<<endl;

	cout << "Enter the key :" << endl;
	cin >> key;
	int result_1 = c->get_value_int(key);
	cout << "value :" << result_1<<endl;

	delete c;
	return 0;
}