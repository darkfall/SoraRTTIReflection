/*
 *  SoraRTTITypedecl.h
 *
 *  Created by Griffin Bu on 5/22/11.
 *  Copyright 2011 Studio GameMaster(www.gamemastercn.com). All rights reserved.
 **/

/*
 This software is provided 'as-is', without any express or implied
 warranty. In no event will the authors be held liable for any
 damages arising from the use of this software.
 
 Permission is granted to anyone to use this software for any
 purpose, including commercial applications, and to alter it and
 redistribute it freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must
 not claim that you wrote the original software. If you use this
 software in a product, an acknowledgment in the product documentation
 would be appreciated but is not required.
 
 2. Altered source versions must be plainly marked as such, and
 must not be misrepresented as being the original software.
 
 3. This notice may not be removed or altered from any source
 distribution.
 */


#ifndef SORA_RTTI_TYPE_DECL_H_
#define SORA_RTTI_TYPE_DECL_H_

#include "SoraRTTIType.h"

namespace sora {

#ifdef _MSC_VER
	typedef signed __int64         int64;
	typedef unsigned __int64       uint64;
#else
	typedef int64_t int64;
	typedef uint64_t uint64;
#endif
	
	template<class __C>
	class RTTIClassTypeHelper {
	public:
		static SoraRTTIType* getRTTIType();
	};
	
	template<class __C>
	inline SoraRTTIType* RTTITypeOf(__C&) {
		return RTTIClassTypeHelper<__C>::getRTTIType();
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(char&) {
		return &SoraRTTIType::int8Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(std::string&) {
		return &SoraRTTIType::stringType;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(std::wstring&) {
		return &SoraRTTIType::wstringType;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(unsigned char&) {
		return &SoraRTTIType::uint8Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(short&) {
		return &SoraRTTIType::int16Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(unsigned short&) {
		return &SoraRTTIType::uint16Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(int&) {
		return &SoraRTTIType::int32Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(unsigned int&) {
		return &SoraRTTIType::uint32Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(long&) {
		return &SoraRTTIType::long32Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(unsigned long&) {
		return &SoraRTTIType::ulong32Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(int64&) {
		return &SoraRTTIType::int64Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(uint64&) {
		return &SoraRTTIType::uint64Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(float&) {
		return &SoraRTTIType::floatType;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(double&) {
		return &SoraRTTIType::doubleType;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(void*) {
		return &SoraRTTIType::voidType;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(std::string*) {
		return &SoraRTTIType::stringType;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(std::wstring*) {
		return &SoraRTTIType::wstringType;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(char*) {
		return &SoraRTTIType::int8Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(unsigned char*) {
		return &SoraRTTIType::uint8Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(short*) {
		return &SoraRTTIType::int16Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(unsigned short*) {
		return &SoraRTTIType::uint16Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(int*) {
		return &SoraRTTIType::int32Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(unsigned int*) {
		return &SoraRTTIType::uint32Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(long*) {
		return &SoraRTTIType::long32Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(unsigned long*) {
		return &SoraRTTIType::ulong32Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(int64*) {
		return &SoraRTTIType::int64Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(uint64*) {
		return &SoraRTTIType::uint64Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(float*) {
		return &SoraRTTIType::floatType;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(double*) {
		return &SoraRTTIType::doubleType;
	}
	
	template<class __C>
	inline SoraRTTIType* RTTITypeOfPtr(__C const* const*) {
		return new SoraRTTIPtrType(new SoraRTTIType(RTTI_CLASS));
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(char const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::int8Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(unsigned char const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::uint8Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(short const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::int16Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(unsigned short const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::uint16Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(int const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::int32Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(unsigned int const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::uint32Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(long const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::long32Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(unsigned long const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::ulong32Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(int64 const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::int64Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(uint64 const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::uint64Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(float const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::floatType);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(double const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::doubleType);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(std::string const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::stringType);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(std::wstring const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::wstringType);
	}
}


#endif // SORA_RTTI_TYPE_DECL_H_