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


#ifndef SORA_RTTI_VAR_ACCESS_H_
#define SORA_RTTI_VAR_ACCESS_H_

namespace sora {
	
	// helper classes
	class AccessReadWrite {};
	class AccessReadOnly {};
	
	template<class __T, class __ACCESS>
	class SoraRTTIVarAccess {
	};
	
	template<class __T>
	class SoraRTTIVarAccess<__T, AccessReadWrite> {
	public:
		SoraRTTIVarAccess(const __T& defaultValue):
		mValue(defaultValue) {
		}
		
		__T get() const {
			return mValue;
		}
		
		void set(__T val) {
			mValue = val; 
		}
		
	private:		
		__T mValue;
	};

	
	template<class __T>
	class SoraRTTIVarAccess<__T, AccessReadOnly> {
	public:
		SoraRTTIVarAccess(const __T& defaultValue):
		mValue(defaultValue) {
		}
		
		__T get() const {
			return mValue;
		}
		
		void set() {
		}
		
	private:		
		__T mValue;
	};
}


#endif // SORA_RTTI_VAR_H_