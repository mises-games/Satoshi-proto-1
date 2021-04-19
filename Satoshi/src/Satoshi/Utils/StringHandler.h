#ifndef STRING_HANDLER_H
#define STRING_HANDLER_H

#include <stpch.h>
#include <Satoshi/Core.h>

namespace Satoshi
{
	class StringHandler
	{
	public:
		template <typename T>
		static std::queue<T> Split(const T&, const T&);
		template <>
		static std::queue<std::string> Split(const std::string&, const std::string&);
		template <>
		static std::queue<std::u16string> Split(const std::u16string&, const std::u16string&);
		template <>
		static std::queue<std::u32string> Split(const std::u32string&, const std::u32string&);
		template <>
		static std::queue<std::wstring> Split(const std::wstring&, const std::wstring&);

		template <typename T>
		static T Concatenate(size_t, const T& ...);
		template <>
		static std::string Concatenate(size_t, const std::string& ...);
		template <>
		static std::u16string Concatenate(size_t, const std::u16string& ...);
		template <>
		static std::u32string Concatenate(size_t, const std::u32string& ...);
		template <>
		static std::wstring Concatenate(size_t, const std::wstring& ...);

		template <typename T, typename S>
		static T Parse(S);
		template <typename S>
		static std::string Parse(S);
		template <typename S>
		static std::u16string Parse(S);
		template <typename S>
		static std::u32string Parse(S);
		template <typename S>
		static std::wstring Parse(S);

		inline static std::wstring ConvertStringToWString(const std::string&);
	};
	
}

template<typename T>
inline std::queue<T> Satoshi::StringHandler::Split(const T& arg, const T& param)
{
	static_assert(false);
	return std::queue<T>();
}

template<>
inline std::queue<std::string> Satoshi::StringHandler::Split(const std::string& arg, const std::string& param)
{
	std::queue<std::string> members;

	size_t start = 0;
	size_t end = 0;

	for (size_t find = 0; find != arg.npos; )
	{
		find = arg.find(param, start);
		if (find != arg.npos)
			end = find;
		else
			end = arg.size();
		if (end > start)
			members.push(arg.substr(start, end - start));
		start = end + 1;
	}

	return members;
}

template<>
inline std::queue<std::u16string> Satoshi::StringHandler::Split(const std::u16string& arg, const std::u16string& param)
{
	std::queue<std::u16string> members;

	size_t start = 0;
	size_t end = 0;

	for (size_t find = 0; find != arg.npos; find = end)
	{
		find = arg.find(param, start);
		if (find != arg.npos)
			end = find;
		else
			end = arg.size();
		if (end > start)
			members.push(arg.substr(start, end - start));
		start = end + 1;
	}

	return members;
}

template<>
inline std::queue<std::u32string> Satoshi::StringHandler::Split(const std::u32string& arg, const std::u32string& param)
{
	std::queue<std::u32string> members;

	size_t start = 0;
	size_t end = 0;

	for (size_t find = 0; find != arg.npos; find = end)
	{
		find = arg.find(param, start);
		if (find != arg.npos)
			end = find;
		else
			end = arg.size();
		if (end > start)
			members.push(arg.substr(start, end - start));
		start = end + 1;
	}

	return members;
}

template<>
inline std::queue<std::wstring> Satoshi::StringHandler::Split(const std::wstring& arg, const std::wstring& param)
{
	std::queue<std::wstring> members;

	size_t start = 0;
	size_t end = 0;

	for (size_t find = 0; find != arg.npos; find = end)
	{
		find = arg.find(param, start);
		if (find != arg.npos)
			end = find;
		else
			end = arg.size();
		if (end > start)
			members.push(arg.substr(start, end - start));
		start = end + 1;
	}

	return members;
}

template<typename T>
inline T Satoshi::StringHandler::Concatenate(size_t numberOfArgs, const T&... )
{
	static_assert(false);
	return T();
}

template<>
inline std::string Satoshi::StringHandler::Concatenate(size_t numberOfArgs, const std::string& ...)
{
	std::stringstream buffer;

	va_list arguments;
	va_start(arguments, numberOfArgs);

	for (size_t i = 0; i < numberOfArgs; i++)
		buffer << va_arg(arguments, std::string);

	return buffer.str();
}

template<>
inline std::u16string Satoshi::StringHandler::Concatenate(size_t numberOfArgs, const std::u16string& ...)
{
	std::basic_stringstream<char16_t> buffer;

	va_list arguments;
	va_start(arguments, numberOfArgs);
	
	for (size_t i = 0; i < numberOfArgs; i++)
		buffer << va_arg(arguments, std::u16string);

	return buffer.str();
}

template<>
inline std::u32string Satoshi::StringHandler::Concatenate(size_t numberOfArgs, const std::u32string& ...)
{
	std::basic_stringstream<char32_t> buffer;

	va_list arguments;
	va_start(arguments, numberOfArgs);

	for (size_t i = 0; i < numberOfArgs; i++)
		buffer << va_arg(arguments, std::u32string);

	return buffer.str();
}

template<>
inline std::wstring Satoshi::StringHandler::Concatenate(size_t numberOfArgs, const std::wstring& ...)
{
	std::wstringstream buffer;

	va_list arguments;
	va_start(arguments, numberOfArgs);

	for (size_t i = 0; i < numberOfArgs; i++)
		buffer << va_arg(arguments, std::wstring);

	return buffer.str();
}

template<typename T, typename S>
inline T Satoshi::StringHandler::Parse(S variable)
{
	return T();
}

template<typename S>
inline std::string Satoshi::StringHandler::Parse(S variable)
{
	std::stringstream buffer;
	buffer << variable;
	return buffer.str();
}

template<typename S>
inline std::u16string Satoshi::StringHandler::Parse(S variable)
{
	std::basic_stringstream<char16_t> buffer;
	buffer << variable;
	return buffer.str();
}

template<typename S>
inline std::u32string Satoshi::StringHandler::Parse(S variable)
{
	std::basic_stringstream<char32_t> buffer;
	buffer << variable;
	return buffer.str();
}

template<typename S>
inline std::wstring Satoshi::StringHandler::Parse(S variable)
{
	std::wstringstream buffer;
	buffer << variable;
	return buffer.str();
}

inline std::wstring Satoshi::StringHandler::ConvertStringToWString(const std::string& stringToConvert)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring result;
	result = converter.from_bytes(stringToConvert);
	return result;
}

#endif
