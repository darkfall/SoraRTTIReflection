/*
 *  SoraRTTITypedecl.h
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/22/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
 */

#ifndef SORA_RTTI_TYPE_DECL_H_
#define SORA_RTTI_TYPE_DECL_H_

#include "SoraRTTIType.h"

namespace sora {
	
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
	inline SoraRTTIType* RTTITypeOf(int64_t&) {
		return &SoraRTTIType::int64Type;
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOf(uint64_t&) {
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
	
	inline SoraRTTIType* RTTITypeOfPtr(int64_t*) {
		return &SoraRTTIType::int64Type;
	}
	
	inline SoraRTTIType* RTTITypeOfPtr(uint64_t*) {
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
	inline SoraRTTIType* RTTITypeOfPtr(int64_t const*const*) {
		return new SoraRTTIPtrType(&SoraRTTIType::int64Type);
	}
	
	template<>
	inline SoraRTTIType* RTTITypeOfPtr(uint64_t const*const*) {
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