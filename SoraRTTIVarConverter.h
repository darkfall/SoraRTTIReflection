/*
 *  SoraRTTIVarConverter.h
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/22/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
 */

#ifndef SORA_RTTI_VAR_CONVERTER_H_
#define SORA_RTTI_VAR_CONVERTER_H_

#include "SoraRTTIType.h"
#include "SoraRTTITypeDecl.h"
#include "SoraRTTIVarDefaultValue.h"

namespace sora {
	
	template<class __IN, class __TO>
	class RTTIVarConvertTo {
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, bool> {
	public:
		bool operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
					return static_cast<bool>(value);
					break;
			}
			
			return RTTIDefaultValue<bool>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, int> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<int>(value);
					break;
					
				case RTTI_STRING:
					return atoi(value.c_str());
					break;
			}
			
			return RTTIDefaultValue<int>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, short> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<short>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<short>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<short>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, unsigned short> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<unsigned short>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<unsigned short>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<unsigned short>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, unsigned char> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
					return static_cast<unsigned char>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<unsigned char>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<unsigned char>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, long> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<long>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<long>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<long>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, unsigned long> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<unsigned long>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<unsigned long>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<unsigned long>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, int64_t> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<int64_t>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<int64_t>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<int64_t>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, uint64_t> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<uint64_t>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<uint64_t>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<uint64_t>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, unsigned int> {
	public:
		int operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<unsigned int>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<unsigned int>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<unsigned int>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, char> {
	public:
		char operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
					return static_cast<char>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<char>(atoi(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<char>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, float> {
	public:
		float operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<float>(value);
					break;
					
				case RTTI_STRING:
					return static_cast<float>(atof(value.c_str()));
					break;
			}
			
			return RTTIDefaultValue<float>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, double> {
	public:
		float operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT:
				case RTTI_DOUBLE:
					return static_cast<double>(value);
					break;
					
				case RTTI_STRING:
					return atof(value.c_str());
					break;
			}
			
			return RTTIDefaultValue<double>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, std::string> {
	public:
		float operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8: {
					char buffer[8];
					sprintf(buffer, "%c", value);
					return std::string(buffer);
					break;
				}
								
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT8:  {
					char buffer[16];
					sprintf(buffer, "%c", (int)value);
					return std::string(buffer);
					break;
				}
				case RTTI_UINT32: {
					char buffer[16];
					sprintf(buffer, "%u", value);
					return std::string(buffer);
				}
					
				case RTTI_INT64: {
					char buffer[32];
					sprintf(buffer, "%ll", value);
					return std::string(buffer);
					break;
				}
					
				case RTTI_UINT64: {
					char buffer[32];
					sprintf(buffer, "%llu", value);
					return std::string(buffer);
					break;
				}
					
				case RTTI_LONG32: {
					char buffer[32];
					sprintf(buffer, "%l", value);
					return std::string(buffer);
					break;
				}
					
				case RTTI_ULONG32: {
					char buffer[32];
					sprintf(buffer, "%lu", value);
					return std::string(buffer);
					break;
				}
					
				case RTTI_FLOAT: {
					char buffer[32];
					sprintf(buffer, "%.8f", value);
					return std::string(buffer);
					break;
				}
					
				case RTTI_DOUBLE: {
					char buffer[32];
					sprintf(buffer, "%.8f", value);
					return std::string(buffer);
					break;
				}
				
				case RTTI_STRING:
					return value;
					break;
					
				case RTTI_WSTRING: {
					std::string buffer(value.length(), ' ');
					std::copy(value.begin(), value.end(), buffer.begin());
					return buffer;
					break;
				}
			}
			
			return RTTIDefaultValue<std::string>::Default();
		}
	};
	
	template<class __IN>
	class RTTIVarConvertTo<__IN, std::wstring> {
	public:
		float operator()(__IN value) {
			SoraRTTIType* type = RTTITypeOfPtr((__IN*)0);
			int typeTag = type->getTag();
			
			switch (typeTag) {
				case RTTI_INT8:
				case RTTI_UINT8:
				case RTTI_INT16:
				case RTTI_UINT16:
				case RTTI_INT32:
				case RTTI_UINT32:
				case RTTI_INT64:
				case RTTI_UINT64:
				case RTTI_LONG32:
				case RTTI_ULONG32:
				case RTTI_FLOAT: 
				case RTTI_DOUBLE: {
					std::string strConverted = RTTIVarConvertTo<__IN, std::string>(value);
					std::wstring buffer(strConverted.length(), L' ');
					std::copy(strConverted.begin(), strConverted.end(), buffer.begin());
					return buffer;
					break;
				}
					
				case RTTI_STRING: {
					std::wstring buffer(value.length(), L' ');
					std::copy(value.begin(), value.end(), buffer.begin());
					return buffer;
				}
					
				case RTTI_WSTRING:
					return value;
					break;
			}
			
			return RTTIDefaultValue<std::wstring>::Default();
		}
	};
}

#endif // SORA_RTTI_VAR_CONVERTER_H_