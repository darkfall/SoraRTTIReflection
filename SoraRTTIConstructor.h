/*
 *  SoraRTTIConstructor.h
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/24/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
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