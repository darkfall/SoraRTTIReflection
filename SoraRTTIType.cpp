/*
 *  SoraRTTIType.cpp
 *
 *  Created by Griffin Bu on 5/22/11.
 *  Copyright 2011 Studio GameMaster(www.gamemastercn.com). All rights reserved.
 *
 *  This file is part of SoraRTTIReflection which belongs to Hoshizora.
 *
 *  SoraRTTIReflection is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SoraRTTIReflection is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with PixelLight. If not, see <http://www.gnu.org/licenses/>.
 **/


#include <cassert>

#include "SoraRTTIType.h"
#include "SoraRTTIClass.h"

namespace sora {
	
	SoraRTTIType SoraRTTIType::unknownType(RTTI_UNKNOWN);
	SoraRTTIType SoraRTTIType::voidType(RTTI_VOID);
	SoraRTTIType SoraRTTIType::boolType(RTTI_BOOL);
	SoraRTTIType SoraRTTIType::int8Type(RTTI_INT8);
	SoraRTTIType SoraRTTIType::uint8Type(RTTI_UINT8);
	SoraRTTIType SoraRTTIType::int16Type(RTTI_INT16);
	SoraRTTIType SoraRTTIType::uint16Type(RTTI_UINT16);
	SoraRTTIType SoraRTTIType::int32Type(RTTI_INT32);
	SoraRTTIType SoraRTTIType::uint32Type(RTTI_UINT32);
	SoraRTTIType SoraRTTIType::long32Type(RTTI_LONG32);
	SoraRTTIType SoraRTTIType::ulong32Type(RTTI_ULONG32);
	SoraRTTIType SoraRTTIType::int64Type(RTTI_INT64);
	SoraRTTIType SoraRTTIType::uint64Type(RTTI_UINT64);
	SoraRTTIType SoraRTTIType::floatType(RTTI_FLOAT);
	SoraRTTIType SoraRTTIType::doubleType(RTTI_DOUBLE);
	SoraRTTIType SoraRTTIType::stringType(RTTI_STRING);
	SoraRTTIType SoraRTTIType::wstringType(RTTI_WSTRING);

	std::string SoraRTTIType::getName() {
		if(RTTIName.size() != 0)
			return RTTIName;
			
		switch (RTTITag) {
			case RTTI_UNKNOWN: RTTIName = "???"; break;
			case RTTI_VOID: RTTIName = "void"; break;
			case RTTI_BOOL: RTTIName = "bool"; break;
			case RTTI_INT8: RTTIName = "char"; break;
			case RTTI_UINT8: RTTIName = "unsigned char"; break;
			case RTTI_INT16: RTTIName = "short"; break;
			case RTTI_UINT16: RTTIName = "unsigned short"; break;
			case RTTI_INT32: RTTIName = "int"; break;
			case RTTI_UINT32: RTTIName = "unsigned int"; break;
			case RTTI_LONG32: RTTIName = "long"; break;
			case RTTI_ULONG32: RTTIName = "unsigned long"; break;
			case RTTI_INT64: RTTIName = "int64_t"; break;
			case RTTI_UINT64: RTTIName = "uint64_t"; break;
			case RTTI_FLOAT: RTTIName = "float"; break;
			case RTTI_DOUBLE: RTTIName = "double"; break;	
			case RTTI_STRING: RTTIName = "string"; break;
			case RTTI_WSTRING: RTTIName = "wstring"; break;
		}
		
		return RTTIName;
	}
	
	unsigned int SoraRTTIArrayType::getArraySize() const {
		return mArraySize;
	}
	
	SoraRTTIType* SoraRTTIArrayType::getArrayType() const {
		return mArrayType;
	}
	
	std::string SoraRTTIArrayType::getName() {
		char buf[128];
		sprintf(buf, "%s[%d]", mArrayType->getName().c_str(), mArraySize);
		return buf;
	}
	
	std::string SoraRTTIPtrType::getName() {
		return mPointeeType->getName()+"*";
	}
	
	SoraRTTIType* SoraRTTIPtrType::getPointeeType() const {
		return mPointeeType;
	}

} // namespace sora