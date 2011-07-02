/*
 *  SoraRTTIVar.h
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/22/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
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