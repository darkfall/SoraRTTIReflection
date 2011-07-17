/*
 *  SoraRTTIVarDefaultValue.h
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
	class RTTIDefaultValue<int64> {
	public:
		static int64 Default() {
			return 0;
		}
	};
	
	template<>
	class RTTIDefaultValue<uint64> {
	public:
		static uint64 Default() {
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