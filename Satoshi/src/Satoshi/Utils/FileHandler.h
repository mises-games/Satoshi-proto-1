#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stpch.h>
#include "StringHandler.h"

namespace Satoshi {
	class SATOSHI_API FileHandler
	{
	public:
		
		template <typename String, typename StringPrimitive>
		inline static size_t ReadFile(std::string filepath, String* storage);
		
		template <typename String, typename StringPrimitive>
		inline static size_t WriteFile(const std::string& filepath, const String& content);
		
		inline static std::queue<std::string> ExtractPathFromFile(std::string filepath, std::string filterPattern = "((?:[^/]*/)*)");
		inline static int CreateFilepath(std::string filepath);
	};
}

template<typename String, typename StringPrimitive>
inline size_t Satoshi::FileHandler::ReadFile(std::string filepath, String* storage)
{
	static_assert
	(
		Satoshi::AssertionHandler::IsValidString<String>() &&
		Satoshi::AssertionHandler::IsValidPrimitive<String, StringPrimitive>()
	);

	std::basic_stringstream<StringPrimitive> fileBuffer;
	std::basic_ifstream<StringPrimitive> fileStream;
	try
	{
		fileStream.open(filepath);
	}
	catch (const std::ifstream::failure& e)
	{
		throw e.what();
	}
	std::string line;
	while (getline(fileStream, line))
		fileBuffer << line << '\n';
	fileStream.close();
	*storage = fileBuffer.str();
	return storage->size();
}

template<typename String, typename StringPrimitive>
inline size_t Satoshi::FileHandler::WriteFile(const std::string& filepath, const String& content)
{
	static_assert
	(
		Satoshi::AssertionHandler::IsValidString<String>() &&
		Satoshi::AssertionHandler::IsValidPrimitive<String, StringPrimitive>()
	);

	CreateFilepath(filepath);
	std::basic_ofstream<StringPrimitive> fileStream;
	try
	{
		fileStream.open(filepath);
	}
	catch (const std::ofstream::failure& e)
	{
		throw e.what();
	}
	fileStream << content;
	fileStream.close();
	return content.size();
}

inline std::queue<std::string> Satoshi::FileHandler::ExtractPathFromFile(std::string filepath, std::string filterFilepathPattern)
{
	std::regex filterFilepath(filterFilepathPattern);
	std::smatch cleanedFilepath;
	
	std::regex_search(filepath, cleanedFilepath, filterFilepath);
	
	std::queue<std::string> Directories = Satoshi::StringHandler::Split<std::string>(cleanedFilepath[0],"/");

	if (Directories.front() == ".")
		Directories.pop();

	return Directories;
}

#ifdef ST_PLATFORM_MSDOS

inline int Satoshi::FileHandler::CreateFilepath(std::string filepath)
{
	int status = -1;
	std::queue<std::string> directories = ExtractPathFromFile(filepath);
	size_t numberOfDirectories = directories.size();
	std::string relativeFilepath;

	for (size_t i = 0; directories.size() > 0; i++)
	{
		if(i != 0)
			Satoshi::StringHandler::Concatenate<std::string, char>(relativeFilepath, "/");
		Satoshi::StringHandler::Concatenate<std::string, char>(relativeFilepath, directories.front());
		status = _mkdir(relativeFilepath.c_str());
		directories.pop();
	}

	return status;
}

#elif ST_PLATFORM_MAC

inline void Satoshi::FileHandler::CreateFilepath(std::string filepath)
{
	throw "Satoshi Doesn't Support Directory System on Mac";
}

#elif ST_PLATFORM_LINUX

inline void Satoshi::FileHandler::CreateFilepath(std::string filepath)
{
	throw "Satoshi Doesn't Support Directory System on Mac";
}

#else

inline void Satoshi::FileHandler::CreateFilepath(std::string filepath)
{
	throw "Satoshi Doesn't Support Directory System";
}

#endif

#endif