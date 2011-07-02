/*
 *  SoraRTTIFunctor.h
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

#ifndef SORA_RTTI_FUNCTOR_H_
#define SORA_RTTI_FUNCTOR_H_

#include "SoraRTTITypeDecl.h"
#include "SoraRTTIType.h"

namespace sora {
	
	// functors for RTTI Class Methods
	
	template <class __RT, class __C>
	class SoraRTTIMethodFunctor0: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)();
		SoraRTTIMethodFunctor0(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 0;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj) {
			return (obj->*mMethod)();
		}

	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C>
	class SoraRTTIMethodFunctor0Const: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)() const;
		SoraRTTIMethodFunctor0Const(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 0;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj) {
			return (obj->*mMethod)();
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C>
	class SoraRTTIMethodFunctor0<void, __C>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)();
		SoraRTTIMethodFunctor0(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 0;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj) {
			return (obj->*mMethod)();
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1>
	class SoraRTTIMethodFunctor1: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1);
		SoraRTTIMethodFunctor1(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 1;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[1];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, *(__P1*)params[0]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1) {
			return (obj->*mMethod)(p1);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1>
	class SoraRTTIMethodFunctor1Const: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1) const;
		SoraRTTIMethodFunctor1Const(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 1;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[1];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, *(__P1*)params[0]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1) {
			return (obj->*mMethod)(p1);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, class __P1>
	class SoraRTTIMethodFunctor1<void, __C, __P1>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1);
		SoraRTTIMethodFunctor1(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 1;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[1];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, *(__P1*)params[0]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, __P1 p1) {
			return (obj->*mMethod)(p1);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1, class __P2>
	class SoraRTTIMethodFunctor2: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, __P2);
		SoraRTTIMethodFunctor2(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 2;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[2];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, *(__P1*)params[0], *(__P2*)params[1]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1, __P2 p2) {
			return (obj->*mMethod)(p1, p2);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, class __P1, class __P2>
	class SoraRTTIMethodFunctor2<void, __C, __P1, __P2>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, __P2);
		SoraRTTIMethodFunctor2(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 2;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[1];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, *(__P1*)params[0], *(__P2*)params[1]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, __P1 p1, __P2 p2) {
			return (obj->*mMethod)(p1, p2);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1, class __P2, class __P3>
	class SoraRTTIMethodFunctor3: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, __P2, __P3);
		SoraRTTIMethodFunctor3(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 3;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[3];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3) {
			return (obj->*mMethod)(p1, p2, p3);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, class __P1, class __P2, class __P3>
	class SoraRTTIMethodFunctor3<void, __C, __P1, __P2, __P3>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, __P2, __P3);
		SoraRTTIMethodFunctor3(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 3;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[3];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3) {
			return (obj->*mMethod)(p1, p2, p3);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1, class __P2, class __P3, class __P4>
	class SoraRTTIMethodFunctor4: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, __P2, __P3, __P4);
		SoraRTTIMethodFunctor4(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 4;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[4];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4) {
			return (obj->*mMethod)(p1, p2, p3, p4);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, class __P1, class __P2, class __P3, class __P4>
	class SoraRTTIMethodFunctor4<void, __C, __P1, __P2, __P3, __P4>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, __P2, __P3, __P4);
		SoraRTTIMethodFunctor4(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 4;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[4];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4) {
			return (obj->*mMethod)(p1, p2, p3, p4);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5>
	class SoraRTTIMethodFunctor5: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, __P2, __P3, __P4, __P5);
		SoraRTTIMethodFunctor5(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 5;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[5];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3],
											*(__P5*)params[4]));
				return var;
															   
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, class __P1, class __P2, class __P3, class __P4, class __P5>
	class SoraRTTIMethodFunctor5<void, __C, __P1, __P2, __P3, __P4, __P5>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, __P2, __P3, __P4, __P5);
		SoraRTTIMethodFunctor5(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 5;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[5];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3],
					*(__P5*)params[4]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6>
	class SoraRTTIMethodFunctor6: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, __P2, __P3, __P4, __P5, __P6);
		SoraRTTIMethodFunctor6(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 6;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[6];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3],
											*(__P5*)params[4],
											*(__P6*)params[5]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6>
	class SoraRTTIMethodFunctor6<void, __C, __P1, __P2, __P3, __P4, __P5, __P6>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, __P2, __P3, __P4, __P5, __P6);
		SoraRTTIMethodFunctor6(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 6;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[6];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3],
					*(__P5*)params[4],
					*(__P6*)params[5]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7>
	class SoraRTTIMethodFunctor7: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, __P2, __P3, __P4, __P5, __P6, __P7);
		SoraRTTIMethodFunctor7(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 7;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[7];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3],
											*(__P5*)params[4],
											*(__P6*)params[5],
											*(__P6*)params[6]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7>
	class SoraRTTIMethodFunctor7<void, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, __P2, __P3, __P4, __P5, __P6, __P7);
		SoraRTTIMethodFunctor7(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 7;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[7];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3],
					*(__P5*)params[4],
					*(__P6*)params[5],
					*(__P7*)params[6]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7, class __P8>
	class SoraRTTIMethodFunctor8: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8);
		SoraRTTIMethodFunctor8(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 8;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[8];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3],
											*(__P5*)params[4],
											*(__P6*)params[5],
											*(__P6*)params[6],
											*(__P7*)params[7]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7, __P8 p8) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7, class __P8>
	class SoraRTTIMethodFunctor8<void, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8);
		SoraRTTIMethodFunctor8(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 8;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[8];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3],
					*(__P5*)params[4],
					*(__P6*)params[5],
					*(__P7*)params[6],
					*(__P8*)params[7]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, __P1 p1, __P2 p2, __P3 p3, __P4 p4, __P5 p5, __P6 p6, __P7 p7, __P8 p8) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, 
			class __C, 
			class __P1, 
			class __P2, 
			class __P3, 
			class __P4, 
			class __P5, 
			class __P6, 
			class __P7, 
			class __P8, 
			class __P9>
	class SoraRTTIMethodFunctor9: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, 
									   __P2, 
									   __P3, 
									   __P4, 
									   __P5, 
									   __P6, 
									   __P7, 
									   __P8, 
									   __P9);
		SoraRTTIMethodFunctor9(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 9;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[9];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
			mParamTypes[8] = RTTITypeOfPtr((__P9*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3],
											*(__P5*)params[4],
											*(__P6*)params[5],
											*(__P6*)params[6],
											*(__P7*)params[7],
											*(__P8*)params[8]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, 
						__P1 p1, 
						__P2 p2, 
						__P3 p3, 
						__P4 p4, 
						__P5 p5, 
						__P6 p6, 
						__P7 p7, 
						__P8 p8, 
						__P9 p9) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, 
			class __P1, 
			class __P2, 
			class __P3, 
			class __P4, 
			class __P5, 
			class __P6, 
			class __P7, 
			class __P8, 
			class __P9>
	class SoraRTTIMethodFunctor9<void, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, 
									   __P2, 
									   __P3, 
									   __P4, 
									   __P5, 
									   __P6, 
									   __P7, 
									   __P8, 
									   __P9);
		SoraRTTIMethodFunctor9(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 9;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[9];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
			mParamTypes[8] = RTTITypeOfPtr((__P9*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3],
					*(__P5*)params[4],
					*(__P6*)params[5],
					*(__P7*)params[6],
					*(__P8*)params[7],
					*(__P9*)params[8]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, 
						__P1 p1, 
						__P2 p2, 
						__P3 p3, 
						__P4 p4, 
						__P5 p5, 
						__P6 p6, 
						__P7 p7, 
						__P8 p8, 
						__P9 p9) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, 
			class __C, 
			class __P1,		
			class __P2, 
			class __P3, 
			class __P4, 
			class __P5, 
			class __P6, 
			class __P7, 
			class __P8, 
			class __P9,
			class __P10>
	class SoraRTTIMethodFunctor10: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, 
									   __P2, 
									   __P3, 
									   __P4, 
									   __P5, 
									   __P6, 
									   __P7, 
									   __P8,
									   __P9,
									   __P10);
		SoraRTTIMethodFunctor10(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 10;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[10];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
			mParamTypes[8] = RTTITypeOfPtr((__P9*)0);
			mParamTypes[9] = RTTITypeOfPtr((__P10*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3],
											*(__P5*)params[4],
											*(__P6*)params[5],
											*(__P6*)params[6],
											*(__P7*)params[7],
											*(__P8*)params[8],
											*(__P9*)params[9]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, 
						__P1 p1,
						__P2 p2,
						__P3 p3,
						__P4 p4,
						__P5 p5,
						__P6 p6,
						__P7 p7,
						__P8 p8,
						__P9 p9,
						__P10 p10) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, 
			class __P1,		
			class __P2, 
			class __P3, 
			class __P4, 
			class __P5, 
			class __P6, 
			class __P7, 
			class __P8, 
			class __P9,
			class __P10>
	class SoraRTTIMethodFunctor10<void, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, 
									   __P2, 
									   __P3, 
									   __P4, 
									   __P5, 
									   __P6, 
									   __P7, 
									   __P8,
									   __P9,
									   __P10);
		SoraRTTIMethodFunctor10(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 10;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[10];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
			mParamTypes[8] = RTTITypeOfPtr((__P9*)0);
			mParamTypes[9] = RTTITypeOfPtr((__P10*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3],
					*(__P5*)params[4],
					*(__P6*)params[5],
					*(__P7*)params[6],
					*(__P8*)params[7],
					*(__P9*)params[8],
					*(__P10*)params[9]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, 
						__P1 p1,
						__P2 p2,
						__P3 p3,
						__P4 p4,
						__P5 p5,
						__P6 p6,
						__P7 p7,
						__P8 p8,
						__P9 p9,
						__P10 p10) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, 
			class __C, 
			class __P1,		
			class __P2,		
			class __P3, 
			class __P4, 
			class __P5, 
			class __P6, 
			class __P7, 
			class __P8, 
			class __P9,
			class __P10,
			class __P11>
	class SoraRTTIMethodFunctor11: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, 
									   __P2, 
									   __P3, 
									   __P4, 
									   __P5, 
									   __P6, 
									   __P7, 
									   __P8,
									   __P9,
									   __P10,
									   __P11);
		SoraRTTIMethodFunctor11(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 11;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[11];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
			mParamTypes[8] = RTTITypeOfPtr((__P9*)0);
			mParamTypes[9] = RTTITypeOfPtr((__P10*)0);
			mParamTypes[10] = RTTITypeOfPtr((__P11*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3],
											*(__P5*)params[4],
											*(__P6*)params[5],
											*(__P6*)params[6],
											*(__P7*)params[7],
											*(__P8*)params[8],
											*(__P9*)params[9],
											*(__P10*)params[10]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, 
						__P1 p1,
						__P2 p2,
						__P3 p3,
						__P4 p4,
						__P5 p5,
						__P6 p6,
						__P7 p7,
						__P8 p8,
						__P9 p9,
						__P10 p10,
						__P11 p11) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, 
			class __P1,		
			class __P2,		
			class __P3, 
			class __P4, 
			class __P5, 
			class __P6, 
			class __P7, 
			class __P8, 
			class __P9,
			class __P10,
			class __P11>
	class SoraRTTIMethodFunctor11<void, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, 
									   __P2, 
									   __P3, 
									   __P4, 
									   __P5, 
									   __P6, 
									   __P7, 
									   __P8,
									   __P9,
									   __P10,
									   __P11);
		SoraRTTIMethodFunctor11(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 11;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[11];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
			mParamTypes[8] = RTTITypeOfPtr((__P9*)0);
			mParamTypes[9] = RTTITypeOfPtr((__P10*)0);
			mParamTypes[10] = RTTITypeOfPtr((__P11*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3],
					*(__P5*)params[4],
					*(__P6*)params[5],
					*(__P7*)params[6],
					*(__P8*)params[7],
					*(__P9*)params[8],
					*(__P10*)params[9],
					*(__P11*)params[10]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, 
						__P1 p1,
						__P2 p2,
						__P3 p3,
						__P4 p4,
						__P5 p5,
						__P6 p6,
						__P7 p7,
						__P8 p8,
						__P9 p9,
						__P10 p10,
						__P11 p11) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __RT, 
			class __C, 
			class __P1,		
			class __P2,		
			class __P3, 
			class __P4, 
			class __P5, 
			class __P6, 
			class __P7, 
			class __P8, 
			class __P9,
			class __P10,
			class __P11,
			class __P12>
	class SoraRTTIMethodFunctor12: public SoraRTTIMethodType {
	public:
		typedef __RT (__C::*MethodPtr)(__P1, 
									   __P2, 
									   __P3, 
									   __P4, 
									   __P5, 
									   __P6, 
									   __P7, 
									   __P8,
									   __P9,
									   __P10,
									   __P11,
									   __P12);
		SoraRTTIMethodFunctor12(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 12;
			
			mReturnType = RTTITypeOfPtr((__RT*)0);
			mParamTypes = new SoraRTTIType*[11];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
			mParamTypes[8] = RTTITypeOfPtr((__P9*)0);
			mParamTypes[9] = RTTITypeOfPtr((__P10*)0);
			mParamTypes[10] = RTTITypeOfPtr((__P11*)0);
			mParamTypes[11] = RTTITypeOfPtr((__P12*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			{
				SoraRTTIVar<__RT>* var = new SoraRTTIVar<__RT>((*this)((__C*)obj, 
											*(__P1*)params[0], 
											*(__P2*)params[1], 
											*(__P3*)params[2],
											*(__P4*)params[3],
											*(__P5*)params[4],
											*(__P6*)params[5],
											*(__P6*)params[6],
											*(__P7*)params[7],
											*(__P8*)params[8],
											*(__P9*)params[9],
											*(__P10*)params[10],
											*(__P11*)params[11]));
				return var;
			}
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		__RT operator()(__C* obj, 
						__P1 p1,
						__P2 p2,
						__P3 p3,
						__P4 p4,
						__P5 p5,
						__P6 p6,
						__P7 p7,
						__P8 p8,
						__P9 p9,
						__P10 p10,
						__P11 p11,
						__P12 p12) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template <class __C, 
			class __P1,		
			class __P2,		
			class __P3, 
			class __P4, 
			class __P5, 
			class __P6, 
			class __P7, 
			class __P8, 
			class __P9,
			class __P10,
			class __P11,
			class __P12>
	class SoraRTTIMethodFunctor12<void, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11, __P12>: public SoraRTTIMethodType {
	public:
		typedef void (__C::*MethodPtr)(__P1, 
									   __P2, 
									   __P3, 
									   __P4, 
									   __P5, 
									   __P6, 
									   __P7, 
									   __P8,
									   __P9,
									   __P10,
									   __P11,
									   __P12);
		SoraRTTIMethodFunctor12(MethodPtr memFn): mMethod(memFn) {
			mClass = &__C::RTTIDescriptor;
			
			nParams = 12;
			
			mReturnType = RTTITypeOfPtr((void*)0);
			mParamTypes = new SoraRTTIType*[11];
			mParamTypes[0] = RTTITypeOfPtr((__P1*)0);
			mParamTypes[1] = RTTITypeOfPtr((__P2*)0);
			mParamTypes[2] = RTTITypeOfPtr((__P3*)0);
			mParamTypes[3] = RTTITypeOfPtr((__P4*)0);
			mParamTypes[4] = RTTITypeOfPtr((__P5*)0);
			mParamTypes[5] = RTTITypeOfPtr((__P6*)0);
			mParamTypes[6] = RTTITypeOfPtr((__P7*)0);
			mParamTypes[7] = RTTITypeOfPtr((__P8*)0);
			mParamTypes[8] = RTTITypeOfPtr((__P9*)0);
			mParamTypes[9] = RTTITypeOfPtr((__P10*)0);
			mParamTypes[10] = RTTITypeOfPtr((__P11*)0);
			mParamTypes[11] = RTTITypeOfPtr((__P12*)0);
		}
		
		virtual SoraRTTIType* invoke(void* obj, void* params[]) {
			(*this)((__C*)obj, 
					*(__P1*)params[0], 
					*(__P2*)params[1], 
					*(__P3*)params[2],
					*(__P4*)params[3],
					*(__P5*)params[4],
					*(__P6*)params[5],
					*(__P7*)params[6],
					*(__P8*)params[7],
					*(__P9*)params[8],
					*(__P10*)params[9],
					*(__P11*)params[10],
					*(__P12*)params[11]);
			return NULL;
		}
		
		virtual SoraRTTIType* invoke(void* obj, const std::string& params) {
			return NULL;
		}
		
		void operator()(__C* obj, 
						__P1 p1,
						__P2 p2,
						__P3 p3,
						__P4 p4,
						__P5 p5,
						__P6 p6,
						__P7 p7,
						__P8 p8,
						__P9 p9,
						__P10 p10,
						__P11 p11,
						__P12 p12) {
			return (obj->*mMethod)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
		}
		
	private:
		MethodPtr mMethod;
	};
	
	template<class __RT, class __C>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) () ) {
		return new SoraRTTIMethodFunctor0<__RT, __C>(Method);
	}
	
	template<class __RT, class __C>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) () const ) {
		return new SoraRTTIMethodFunctor0Const<__RT, __C>(Method);
	}
	
	template<class __RT, class __C, class __P1>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1) ) {
		return new SoraRTTIMethodFunctor1<__RT, __C, __P1>(Method);
	}
	
	template<class __RT, class __C, class __P1>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1) const ) {
		return new SoraRTTIMethodFunctor1Const<__RT, __C, __P1>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2) ) {
		return new SoraRTTIMethodFunctor2<__RT, __C, __P1, __P2>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3) ) {
		return new SoraRTTIMethodFunctor3<__RT, __C, __P1, __P2, __P3>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4) ) {
		return new SoraRTTIMethodFunctor4<__RT, __C, __P1, __P2, __P3, __P4>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4, __P5) ) {
		return new SoraRTTIMethodFunctor5<__RT, __C, __P1, __P2, __P3, __P4, __P5>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4, __P5, __P6) ) {
		return new SoraRTTIMethodFunctor6<__RT, __C, __P1, __P2, __P3, __P4, __P5, __P6>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4, __P5, __P6, __P7) ) {
		return new SoraRTTIMethodFunctor7<__RT, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7, class __P8>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8) ) {
		return new SoraRTTIMethodFunctor8<__RT, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7, class __P8, class __P9>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9) ) {
		return new SoraRTTIMethodFunctor9<__RT, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7, class __P8, class __P9, class __P10>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10) ) {
		return new SoraRTTIMethodFunctor10<__RT, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7, class __P8, class __P9, class __P10, class __P11>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11) ) {
		return new SoraRTTIMethodFunctor11<__RT, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11>(Method);
	}
	
	template<class __RT, class __C, class __P1, class __P2, class __P3, class __P4, class __P5, class __P6, class __P7, class __P8, class __P9, class __P10, class __P11, class __P12>
	inline SoraRTTIMethodType* MethodTypeOf( __RT (__C::*Method) (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11, __P12) ) {
		return new SoraRTTIMethodFunctor12<__RT, __C, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11, __P12>(Method);
	}
	

} // namespace sora

#endif // SORA_RTTI_FUNCTOR_H_