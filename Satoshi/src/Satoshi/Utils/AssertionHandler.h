#ifndef ASSERTION_HANDLER_H
#define ASSERTION_HANDLER_H

#include <stpch.h>

namespace Satoshi 
{
	class AssertionHandler 
	{
	public:
		template <typename T, typename S>
		inline static bool AssertTypeIDs();
		template<typename T>
		inline static bool IsValidString();
		template<typename T>
		inline static bool IsValidNumber();
		template<typename String, typename Primitive>
		inline static bool IsValidPrimitive();
	};
	
}

template<typename T, typename S>
inline bool Satoshi::AssertionHandler::AssertTypeIDs()
{
	return typeid(T) == typeid(S);
}

template<typename T>
inline bool Satoshi::AssertionHandler::IsValidString()
{
	bool isValidString = false;

	isValidString = isValidString || AssertTypeIDs<std::string, T>();
	isValidString = isValidString || AssertTypeIDs<std::u16string, T>();
	isValidString = isValidString || AssertTypeIDs<std::u32string, T>();
	isValidString = isValidString || AssertTypeIDs<std::wstring, T>();

	return isValidString;
}

template<typename T>
inline bool Satoshi::AssertionHandler::IsValidNumber()
{
	bool isValidNumber = false;

	isValidNumber = isValidNumber || AssertTypeIDs<int8_t, T>();
	isValidNumber = isValidNumber || AssertTypeIDs<int16_t, T>();
	isValidNumber = isValidNumber || AssertTypeIDs<int32_t, T>();
	isValidNumber = isValidNumber || AssertTypeIDs<int64_t, T>();

	isValidNumber = isValidNumber || AssertTypeIDs<uint8_t, T>();
	isValidNumber = isValidNumber || AssertTypeIDs<uint16_t, T>();
	isValidNumber = isValidNumber || AssertTypeIDs<uint32_t, T>();
	isValidNumber = isValidNumber || AssertTypeIDs<uint64_t, T>();

	isValidNumber = isValidNumber || AssertTypeIDs<float, T>();
	isValidNumber = isValidNumber || AssertTypeIDs<double, T>();
	isValidNumber = isValidNumber || AssertTypeIDs<bool, T>();

	return isValidNumber;
}

template<typename String, typename Primitive>
inline bool Satoshi::AssertionHandler::IsValidPrimitive()
{
	std::bitset<4> validStringTypes;

	validStringTypes[0] = AssertTypeIDs<String, std::string>();
	validStringTypes[1] = AssertTypeIDs<String, std::u16string>();
	validStringTypes[2] = AssertTypeIDs<String, std::u32string>();
	validStringTypes[3] = AssertTypeIDs<String, std::wstring>();

	uint64_t validStringMappedBits = validStringTypes.to_ullong();

	switch (validStringMappedBits)
	{
	case 1: 
		return Satoshi::AssertionHandler::AssertTypeIDs<char, Primitive>(); 
	case 2:
		return Satoshi::AssertionHandler::AssertTypeIDs<char16_t, Primitive>();
	case 4: 
		return Satoshi::AssertionHandler::AssertTypeIDs<char32_t, Primitive>();
	case 8:
		return Satoshi::AssertionHandler::AssertTypeIDs<wchar_t, Primitive>();
	}
	return false;
}

#endif
