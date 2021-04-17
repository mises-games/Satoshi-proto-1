#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <queue>
#include "StringHandler.h"

#ifdef ST_PLATFORM_WINDOWS
	#include <windows.h>
#endif


namespace Satoshi {
	class SATOSHI_API FileHandler
	{
	public:
		
		template <typename T>
		inline static size_t ReadFile(std::string filepath, T* storage);
		template <>
		inline static size_t ReadFile<std::string>(std::string filepath, std::string* storage);
		template <>
		inline static size_t ReadFile<std::u16string>(std::string filepath, std::u16string* storage);
		template <>
		inline static size_t ReadFile<std::u32string>(std::string filepath, std::u32string* storage);
		
		template <typename T>
		inline static size_t WriteFile(std::string filepath, T content);
		template <>
		inline static size_t WriteFile<std::string>(std::string filepath, std::string content);
		template <>
		inline static size_t WriteFile<std::u16string>(std::string filepath, std::u16string content);
		template <>
		inline static size_t WriteFile<std::u32string>(std::string filepath, std::u32string content);
		
		inline static std::queue<std::string> ExtractPathFromFile(std::string filepath, std::string filterPattern = "((?:[^/]*/)*)");
		inline static void CreateFilepath(std::string filepath);
	};
}

template<typename T>
inline size_t Satoshi::FileHandler::ReadFile(std::string filepath, T* storage)
{
	static_assert(false);
	return 0;
}

template<>
inline size_t Satoshi::FileHandler::ReadFile<std::string>(std::string filepath, std::string* storage)
{
	std::stringstream fileBuffer;
	std::ifstream fileStream;
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

template<>
inline size_t Satoshi::FileHandler::ReadFile<std::u16string>(std::string filepath, std::u16string* storage)
{
	std::basic_stringstream<char16_t> fileBuffer;
	std::basic_ifstream<char16_t> fileStream;
	try
	{
		fileStream.open(filepath);
	}
	catch (const std::ifstream::failure& e)
	{
		throw e.what();
	}
	std::basic_string<char16_t> line;
	while (getline(fileStream, line))
		fileBuffer << line << '\n';
	fileStream.close();
	*storage = fileBuffer.str();
	return storage->size();
}

template<>
inline size_t Satoshi::FileHandler::ReadFile<std::u32string>(std::string filepath, std::u32string* storage)
{
	std::basic_stringstream<char32_t> fileBuffer;
	std::basic_ifstream<char32_t> fileStream;
	try
	{
		fileStream.open(filepath);
	}
	catch (const std::ifstream::failure& e)
	{
		throw e.what();
	}
	std::basic_string<char32_t> line;
	while (getline(fileStream, line))
		fileBuffer << line << '\n';
	fileStream.close();
	*storage = fileBuffer.str();
	return storage->size();
}

template<typename T>
inline size_t Satoshi::FileHandler::WriteFile(std::string FileName, T content)
{
	static_assert(false);
	return 0;
}

template<>
inline size_t Satoshi::FileHandler::WriteFile<std::string>(std::string filepath, std::string content)
{
	CreateFilepath(filepath);
	std::ofstream fileStream;
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

template<>
inline size_t Satoshi::FileHandler::WriteFile<std::u16string>(std::string filepath, std::u16string content)
{
	CreateFilepath(filepath);
	std::basic_ofstream<char16_t> fileStream;
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

template<>
inline size_t Satoshi::FileHandler::WriteFile<std::u32string>(std::string filepath, std::u32string content)
{
	CreateFilepath(filepath);
	std::basic_ofstream<char32_t> fileStream;
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

#ifdef ST_PLATFORM_WINDOWS

inline void Satoshi::FileHandler::CreateFilepath(std::string filepath)
{
	
	std::queue<std::string> directories = ExtractPathFromFile(filepath);
	std::wstring w_filepath;
	size_t rootDirectoryDifference = 0;

	while (directories.size() > 0) 
	{
		w_filepath = Satoshi::StringHandler::ConvertStringToWString(directories.front());
		LPCWSTR convert = w_filepath.c_str();
		CreateDirectory(convert, NULL);
		int status = _wchdir(Satoshi::StringHandler::Concatenate<std::wstring>(L"./",w_filepath).c_str());
		rootDirectoryDifference++;
		directories.pop();
	}
	for (size_t i = 0; i < rootDirectoryDifference; i++)
		int status = _wchdir(L"..");	
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