#pragma once

#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include <map>
#include <fstream>
#include <vector>

#include "bot_reloaded.h"
#include <time.h>
#include <cstdlib> 

static std::map<std::string, std::string> kv_Estiques;

void checkForEstique(TgBot::Message::Ptr message);

typedef std::map<std::string, std::string> stringMap;

//TO-DO: support emoji (kv_Estiques holds a non-Unicode map; should populate differently using std::wstring.
/* static std::wstring ReadUTF16(const std::string &filename)
{
	std::ifstream file(filename.c_str(), std::ios::binary);
	std::stringstream ss;
	ss << file.rdbuf() << '\0';
	return std::wstring((wchar_t *)ss.str().c_str());
}*/

// Saves the map to a file.
static bool mapToFile(const std::string &filename, const stringMap &fileMap)
{
	std::ofstream ofile;

	ofile.open(filename.c_str());
	if (!ofile)
		return false;           //file does not exist and cannot be created.

	// Loop to iterate; everything before the "|" is the key, and everything after is the value.
	for (stringMap::const_iterator iter = fileMap.begin(); iter != fileMap.end(); ++iter)
	{
		ofile << iter->first << "|" << iter->second;
		ofile << "\n";
	}
	return true;
}

// Loads from file and populates the map.
static bool fileToMap(const std::string &filename, stringMap &fileMap) 
{
	std::ifstream ifile;
	std::string line;
	std::string value = "";
	std::string key = "";
	std::vector<std::string> vec;

	ifile.open(filename.c_str());
	if (!ifile)
		return false;   //could not read the file.

	while (std::getline(ifile, line))
	{
		std::vector<std::string> fields;
		boost::split(fields, line, boost::is_any_of("|")); // Split and insert into the vector.

		for (const auto& field : fields)
		{
			if (!boost::starts_with(field, "BQ"))
				key = field;
			else
				value = field;

			if (value != "" && key != "")
			{
				std::cout << "CARREGANDO STICKER -- Trigger: " << key << std::endl << "	FileID: " << value << std::endl;
				fileMap[key] = value;
				key = "";
				value = "";
			}
		}
	}
	return true;
}