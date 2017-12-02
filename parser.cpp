#include "parser.h"
#include <algorithm>
#include <iostream>
#include <fstream>

void parser::parseConfigFile(string file)
{
	ifstream cFile(file);
	if(cFile.is_open())
	{
		string line;

		while(getline(cFile, line))
		{
			line.erase(remove_if(line.begin(), line.end(), isspace),
            line.end());
			
            if(line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            cout << name << " " << value << '\n';
        }
        cFile.close();
    }
    else
        cout << "Unable to open config file." << '\n';

};
	