#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>

namespace Satoshi {
	class FileHandler
	{
	public:
		template <typename T>
		static size_t ReadFile(std::string filepath, T* storage);
		template <>
		static size_t ReadFile<std::string>(std::string filepath, std::string* storage);
		template <>
		static size_t ReadFile<std::u16string>(std::string filepath, std::u16string* storage);
		template <>
		static size_t ReadFile<std::u32string>(std::string filepath, std::u32string* storage);
		template <typename T>
		static size_t WriteFile(std::string FileName, T content);
		template <>
		static size_t WriteFile<std::string>(std::string FileName, std::string content);
		template <>
		static size_t WriteFile<std::u16string>(std::string FileName, std::u16string content);
		template <>
		static size_t WriteFile<std::u32string>(std::string FileName, std::u32string content);
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
	std::stringstream fileBuffer;
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

#endif