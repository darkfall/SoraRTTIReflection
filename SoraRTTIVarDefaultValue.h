/*
 *  SoraRTTIVarDefaultValue.h
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/22/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
 */

#ifndef SORA_RTTI_VAR_DEFAULT_VALUE_H_
#define SORA_RTTI_VAR_DEFAULT_VALUE_H_

#include <string>

namespace sora {
	
	template<class __T>
	class RTTIDefaultValue {
	public:
		static __T Default() {
			return *(__T*)NULL;
		}
	};
	
	template<class __T>
	class RTTIDefaultValue<__T*> {
	public:
		static __T* Default() {
			return NULL;
		}
	};
	
	template<class __T>
	class RTTIDefaultValue<__T&> {
	public:
		static __T& Default() {
			return *(__T*)NULL;
		}
	};
	
	template<>
	class RTTIDefaultValue<std::string> {
	public:
		static std::string Default() {
			return "";
		}
	};
	
	template<>
	class RTTIDefaultValue<std::wstring> {
	public:
		static std::wstring Default() {
			return L"";
		}
	};
	
	template<>
	class RTTIDefaultValue<char> {
	public:
		static char Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<unsigned char> {
	public:
		static unsigned char Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<short> {
	public:
		static short Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<unsigned short> {
	public:
		static unsigned short Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<int> {
	public:
		static int Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<unsigned int> {
	public:
		static unsigned int Default() {
			return 0;
		}
	};
	
	
	template<>
	class RTTIDefaultValue<long> {
	public:
		static long Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<unsigned long> {
	public:
		static unsigned long Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<int64_t> {
	public:
		static int64_t Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<uint64_t> {
	public:
		static uint64_t Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<bool> {
	public:
		static bool Default() {
			return false;
		}
	};
	
	template<>
	class RTTIDefaultValue<float> {
	public:
		static float Default() {
			return 0.f;
		}
	};
	
	template<>
	class RTTIDefaultValue<double> {
	public:
		static double Default() {
			return 0.0;
		}
	};
}


#endif // SORA_RTTI_VAR_DEFAULT_VALUE_H_