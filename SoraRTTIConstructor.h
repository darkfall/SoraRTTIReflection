/*
 *  SoraRTTIConstructor.h
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


#ifndef SORA_RTTI_CONSTRUCTOR_H_
#define SORA_RTTI_CONSTRUCTOR_H_

#include "SoraRTTIType.h"
#include "SoraRTTIFunctor.h"

namespace sora {
	
	class SoraRTTIConstructor: public SoraRTTIType {
	public:
		SoraRTTIConstructor(): SoraRTTIType(RTTI_CONSTRUCTOR), nParams(0), mClass(NULL) {
			
		}
		
		int getParamNum() const {
			return nParams;
		}
		
		SoraRTTIClassDescriptor* getClass() {
			return mClass;
		}
		
		virtual void* operator()(void** params) = 0;
		
	protected:
		int nParams;
		SoraRTTIClassDescriptor* mClass;
	};
	
	template<class __C>
	class SoraRTTIConstructor0: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor0() {
			nParams = 0;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C();
		}
	};
	
	template<class __C, class __P1>
	class SoraRTTIConstructor1: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor1() {
			nParams = 1;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C(*(__P1*)params[0]);
		}
	};
	
	template<class __C, class __P1, class __P2>
	class SoraRTTIConstructor2: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor2() {
			nParams = 2;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C(*(__P1*)params[0], *(__P2*)params[1]);
		}
	};
	
	template<class __C, class __P1, class __P2, class __P3>
	class SoraRTTIConstructor3: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor3() {
			nParams = 3;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C(*(__P1*)params[0], *(__P2*)params[1], *(__P3*)params[2]);
		}
	};
	
	template<class __C, class __P1, class __P2, class __P3, class __P4>
	class SoraRTTIConstructor4: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor4() {
			nParams = 4;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C(*(__P1*)params[0], *(__P2*)params[1], *(__P3*)params[2], *(__P4*)params[3]);
		}
	};
	
	template<class __C, class __P1, class __P2, class __P3, class __P4, class __P5>
	class SoraRTTIConstructor5: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor5() {
			nParams = 5;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C(*(__P1*)params[0], 
						   *(__P2*)params[1], 
						   *(__P3*)params[2], 
						   *(__P4*)params[3], 
						   *(__P5*)params[4]);
		}
	};
	
	template<class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6>
	class SoraRTTIConstructor6: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor6() {
			nParams = 6;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C(*(__P1*)params[0], 
						   *(__P2*)params[1], 
						   *(__P3*)params[2], 
						   *(__P4*)params[3], 
						   *(__P5*)params[4],
						   *(__P6*)params[5]);
		}
	};
	
	template<class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7>
	class SoraRTTIConstructor7: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor7() {
			nParams = 7;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C(*(__P1*)params[0], 
						   *(__P2*)params[1], 
						   *(__P3*)params[2], 
						   *(__P4*)params[3], 
						   *(__P5*)params[4],
						   *(__P6*)params[5],
						   *(__P7*)params[6]);
		}
	};
	
	template<class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7, class __P8>
	class SoraRTTIConstructor8: public SoraRTTIConstructor {
	public:
		SoraRTTIConstructor8() {
			nParams = 8;
			
			mClass = &__C::RTTIDescriptor;
		}
		
		virtual void* operator()(void** params) {
			return new __C(*(__P1*)params[0], 
						   *(__P2*)params[1], 
						   *(__P3*)params[2], 
						   *(__P4*)params[3], 
						   *(__P5*)params[4],
						   *(__P6*)params[5],
						   *(__P7*)params[6],
						   *(__P8*)params[7]);
		}
	};
} // namespace sora

#endif