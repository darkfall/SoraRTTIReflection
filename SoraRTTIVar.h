/*
 *  SoraRTTIVar.h
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


#ifndef SORA_RTTI_VAR_H_
#define SORA_RTTI_VAR_H_

#include "SoraRTTIVarAccess.h"
#include "SoraRTTIVarConverter.h"
#include "SoraRTTIType.h"

namespace sora {
	
	inline void RTTI_VAR_RELEASE(SoraRTTIType* var) {
		delete var;
	}
	
	template<class __T, class __ACCESS=AccessReadWrite>
	class SoraRTTIVar: public SoraRTTIType {
	public:
		SoraRTTIVar(): SoraRTTIType(0), mValue(RTTIDefaultValue<__T>::Default()), mArraySize(0) {
		}
		SoraRTTIVar(__T defaultVal): SoraRTTIType(0), mValue(defaultVal), mArraySize(0) {
		}
		virtual ~SoraRTTIVar() {
		}
		
		void operator= (__T val) {
			mValue.set(val);
		}
	
		__T operator() () {
			return mValue.get();
		}
		
		void set(__T val) {
			mValue.set(val);
		}
		
		__T get() const {
			return mValue.get();
		}
		
	public:
		void setArray(unsigned int arrSize) { 
			mArraySize = arrSize;
		}
		
		bool isArray() const {
			return mArraySize != 0;
		}
		
		unsigned int getArraySize() const {
			return mArraySize;
		}
		
	public:
		__T getDefaultValue() const {
			return RTTIDefaultValue<__T>::Default();
		}
		
	public:
		bool getBool() {
			return RTTIVarConvertTo<__T, bool>(mValue.get());
		}
		int getInt32() {
			return RTTIVarConvertTo<__T, int>(mValue.get());
		}
		unsigned int getUInt32() {
			return RTTIVarConvertTo<__T, unsigned int>(mValue.get());
		}
		char getInt8() {
			return RTTIVarConvertTo<__T, char>(mValue.get());
		}
		unsigned char getUInt8() {
			return RTTIVarConvertTo<__T, unsigned char>(mValue.get());
		}
		short getInt16() {
			return RTTIVarConvertTo<__T, short>(mValue.get());
		}
		unsigned short getUInt16() {
			return RTTIVarConvertTo<__T, unsigned short>(mValue.get());
		}
		long getLong() {
			return RTTIVarConvertTo<__T, long>(mValue.get());
		}
		unsigned long getULong() {
			return RTTIVarConvertTo<__T, unsigned long>(mValue.get());
		}
		int64 getInt64() {
			return RTTIVarConvertTo<__T, int64>(mValue.get());
		}
		uint64 getUInt64() {
			return RTTIVarConvertTo<__T, uint64>(mValue.get());
		}
		float getFloat() {
			return RTTIVarConvertTo<__T, float>(mValue.get());
		}
		double getDouble() {
			return RTTIVarConvertTo<__T, double>(mValue.get());
		}
		std::string getString() {
			return RTTIVarConvertTo<__T, std::string>(mValue.get());
		}
		std::wstring getWString() {
			return RTTIVarConvertTo<__T, std::wstring>(mValue.get());
		}
		
	public:
		operator bool() {
			return getBool();
		}
		operator int() {
			return getInt32();
		}
		operator char() {
			return getInt8();
		}
		operator unsigned char() {
			return getUInt8();
		}
		operator unsigned int() {
			return getUInt32();
		}
		operator short() {
			return getInt16();
		}
		operator unsigned short() {
			return getUInt16();
		}
		operator long() {
			return getLong();
		}
		operator unsigned long() {
			return getULong();
		}
		operator int64() {
			return getInt64();
		}
		operator uint64() {
			return getUInt64();
		}
		operator float() {
			return getFloat();
		}
		operator double() {
			return getDouble();
		}
		template<class __C>
		operator __C*() {
			return (__C*)mValue.get();
		}
		operator void*() {
			return (void*)mValue.get();
		}
		
	private:
		unsigned int mArraySize;
		
		SoraRTTIVarAccess<__T, __ACCESS> mValue;
	};

    
	template<class __T>
	inline SoraRTTIType* RTTIVarOf(__T&) {
		return new SoraRTTIVar<__T>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(char&) {
		return new SoraRTTIVar<char>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(bool&) {
		return new SoraRTTIVar<bool>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(unsigned char&) {
		return new SoraRTTIVar<unsigned char>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(short&) {
		return new SoraRTTIVar<short>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(unsigned short&) {
		return new SoraRTTIVar<unsigned short>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(int&) {
		return new SoraRTTIVar<int>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(unsigned int&) {
		return new SoraRTTIVar<unsigned int>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(long&) {
		return new SoraRTTIVar<long>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(unsigned long&) {
		return new SoraRTTIVar<unsigned long>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(int64&) {
		return new SoraRTTIVar<int64>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(uint64&) {
		return new SoraRTTIVar<uint64>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(float&) {
		return new SoraRTTIVar<float>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(double&) {
		return new SoraRTTIVar<double>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(std::string&) {
		return new SoraRTTIVar<std::string>();
	}
	
	template<>
	inline SoraRTTIType* RTTIVarOf(std::wstring&) {
		return new SoraRTTIVar<std::wstring>();
	}
} // namespace sora


#endif // SORA_RTTI_VAR_H_