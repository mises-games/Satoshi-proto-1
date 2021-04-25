#ifndef STRING_HANDLER_H
#define STRING_HANDLER_H

#include <stpch.h>
#include <Satoshi/Core.h>
#include "AssertionHandler.h"

namespace Satoshi
{
	class StringHandler
	{
	public:
		template <typename String>
		inline static std::queue<String> Split(const String&, const String&);
		
		template <typename String, typename StringPrimitive>
		inline static String Concatenate(const String&, const String&);

		template<typename String, typename StringPrimitive, typename Number>
		inline static String ParseNumber(Number);
	};
	
}

template<typename String>
inline std::queue<String> Satoshi::StringHandler::Split(const String& arg, const String& param)
{
	bool functionIsValid = Satoshi::AssertionHandler::IsValidString<String>();

	assert(functionIsValid);

	std::queue<String> members;

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

template<typename String, typename StringPrimitive>
inline String Satoshi::StringHandler::Concatenate(const String& string1, const String& string2)
{
	bool functionIsValid =
	(
		Satoshi::AssertionHandler::IsValidString<String>() &&
		Satoshi::AssertionHandler::IsValidPrimitive<String, StringPrimitive>()
	);

	assert(functionIsValid);

	std::basic_stringstream<StringPrimitive> buffer;

	buffer << string1 << string2;

	return buffer.str();
}

template<typename String, typename StringPrimitive, typename Number>
inline String Satoshi::StringHandler::ParseNumber(Number variable)
{
	bool functionIsValid =
	(		
		Satoshi::AssertionHandler::IsValidNumber<Number>() &&
		Satoshi::AssertionHandler::IsValidString<String>() &&
		Satoshi::AssertionHandler::IsValidPrimitive<String, StringPrimitive>()
	);

	assert(functionIsValid);

	std::basic_stringstream<StringPrimitive> buffer;
	buffer << variable;
	return buffer.str();
}

#endif
