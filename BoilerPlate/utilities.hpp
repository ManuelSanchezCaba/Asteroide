#pragma once
#ifndef _UTILITIES_
#define _UTILITIES_
#include <string>
#include "dirent.h"
#include <fstream>
#include <iostream>

using namespace std;

class utilities
{
public: 
	void explore(char *dir_name)
	{
		dir = opendir(dir_name);
		if (!dir)
		{
			cout << "Directory was not found" << endl;
			return;
		}
		while ((entry = readdir(dir)) != NULL)
		{
			if (entry->d_name[0] != '.')
			{
				string path = string(dir_name) + "/" + string(entry->d_name);
				cout << "Entry: " << path << endl;
				file.open(path.c_str());
				if (file.good())
				{
					while (!file.eof())
					{
						getline(file, readString);
						cout << readString << endl;
					}
					cout << "" << endl;
				}
				file.close();
				stat(path.c_str(), &info); //
				if (S_ISDIR(info.st_mode))
				{
					explore((char *)path.c_str());
				}
			}
		}

		closedir(dir);
	}

private: DIR* dir;
		 struct dirent *entry;
		 struct stat info;
		 string readString;
		 fstream file;
};

#endif // !_UTILITIES_
