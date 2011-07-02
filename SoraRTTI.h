/*
 *  SoraRTTI.h
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


#ifndef SORA_RTTI_H_
#define SORA_RTTI_H_

#include "SoraRTTIType.h"
#include "SoraRTTITypeDecl.h"
#include "SoraRTTIClass.h"
#include "SoraRTTIFunctor.h"
#include "SoraRTTIConstructor.h"
#include "SoraRTTIVar.h"
#include "SoraRTTIClassManager.h"

namespace sora {
	
#define RTTI_METHOD(method, flags) \
	*new sora::SoraRTTIMethodDescriptor(#method, \
										flags, \
										sora::MethodTypeOf(&self::method), \
										&self::RTTIDescriptor)
	
#define RTTI_OVERLOAD_METHOD(method, __RET, signature, flags) \
	*new sora::SoraRTTIMethodDescriptor(#method #signature, \
										flags | sora::RTTI_FLAG_OVERLOADED, \
										sora::MethodTypeOf((__RET (self::*)signature)&self::method), \
										&self::RTTIDescriptor)
	
#define RTTI_OVERLOAD_METHOD_1(method, __RET, __P1, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1), flags) 
	
#define RTTI_OVERLOAD_METHOD_2(method, __RET, __P1, __P2, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2), flags)
	
#define RTTI_OVERLOAD_METHOD_3(method, __RET, __P1, __P2, __P3, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3), flags)

#define RTTI_OVERLOAD_METHOD_4(method, __RET, __P1, __P2, __P3, __P4, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4), flags)

#define RTTI_OVERLOAD_METHOD_5(method, __RET, __P1, __P2, __P3, __P4, __P5, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4, __P5), flags)

#define RTTI_OVERLOAD_METHOD_6(method, __RET, __P1, __P2, __P3, __P4, __P5, __P6, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4, __P5, __P6), flags)

#define RTTI_OVERLOAD_METHOD_7(method, __RET, __P1, __P2, __P3, __P4, __P5, __P6, __P7, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4, __P5, __P6, __P7), flags)
	
#define RTTI_OVERLOAD_METHOD_8(method, __RET, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8), flags)
	
#define RTTI_OVERLOAD_METHOD_9(method, __RET, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9), flags)
	
#define RTTI_OVERLOAD_METHOD_10(method, __RET, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10), flags)

#define RTTI_OVERLOAD_METHOD_11(method, __RET, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11), flags)

#define RTTI_OVERLOAD_METHOD_12(method, __RET, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11, __P12, flags) \
	RTTI_OVERLOAD_METHOD(method, __RET, (__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8, __P9, __P10, __P11, __P12), flags)
	
#define RTTI_FIELD(field, type, flags) \
	*new sora::SoraRTTIFieldDescriptor(#field, \
										flags, \
										sora::RTTITypeOfPtr((type*)0), \
										NULL, \
										&self::RTTIDescriptor)
	
#define RTTI_DESCRIBED_FIELD(field, type, flags) \
	*new sora::SoraRTTIFieldDescriptor(#field, \
										flags, \
										sora::RTTITypeOfPtr((type*)0), \
										new self::RTTIFieldHelper##field(), \
										&self::RTTIDescriptor)
	
#define RTTI_PTR(field, type, flags) \
	*new sora::SoraRTTIFieldDescriptor(#field, \
										flags, \
										sora::RTTITypeOfPtr((type*)0), \
										NULL, \
										&self::RTTIDescriptor)
	
#define RTTI_DESCRIBED_PTR(field, type, flags) \
	*new sora::SoraRTTIFieldDescriptor(#field, \
										flags, \
										sora::RTTITypeOfPtr((type*)0), \
										new self::RTTIFieldHelper##field(), \
										&self::RTTIDescriptor)
	
#define RTTI_ARRAY(field, type, size, flags) \
	*new sora::SoraRTTIFieldDescriptor(#field, \
										flags, \
										new sora::SoraRTTIArrayType(sora::RTTITypeOfPtr((type*)0), size), \
										NULL, \
										&self::RTTIDescriptor)
	
#define RTTI_DESCRIBED_ARRAY(field, type, size, flags) \
	*new sora::SoraRTTIFieldDescriptor(#field, \
										flags, \
										new sora::SoraRTTIArrayType(sora::RTTITypeOfPtr((type*)0), size), \
										new self::RTTIFieldHelper##field(size), \
										&self::RTTIDescriptor)
	
#define RTTI_BASE_CLASS(T, flags) \
	*new sora::SoraRTTIDerivedType(&self::RTTIDescriptor, \
									&T::RTTIDescriptor, \
									flags)
	
#define RTTI_NO_METHOD (*(sora::SoraRTTIMethodDescriptor*)0)
#define RTTI_NO_FIELD  (*(sora::SoraRTTIFieldDescriptor*)0)
#define RTTI_NO_BASE_CLASS (*(sora::SoraRTTIDerivedType*)0)
	
#define RTTI_CONSTRUCTOR(sig, constructor) \
	*new sora::SoraRTTIConstructorDescriptor(#sig,\
											 &self::RTTIDescriptor,\
											 constructor)\
	
#define RTTI_DEFAULT_CONSTRUCTOR() \
	RTTI_CONSTRUCTOR((void), (new sora::SoraRTTIConstructor0<self>())) 
	
#define RTTI_CONSTRUCTOR_1(__P1) \
	RTTI_CONSTRUCTOR((__P1), (new sora::SoraRTTIConstructor1<self, __P1>()))
	
#define RTTI_CONSTRUCTOR_2(__P1, __P2) \
	RTTI_CONSTRUCTOR((__P1, __P2), (new sora::SoraRTTIConstructor2<self, __P1, __P2>()))
	
#define RTTI_CONSTRUCTOR_3(__P1, __P2, __P3) \
	RTTI_CONSTRUCTOR((__P1, __P2, __P3), (new sora::SoraRTTIConstructor3<self, __P1, __P2, __P3>()))
	
#define RTTI_CONSTRUCTOR_4(__P1, __P2, __P3, __P4) \
	RTTI_CONSTRUCTOR((__P1, __P2, __P3, __P4), (new sora::SoraRTTIConstructor4<self, __P1, __P2, __P3, __P4>()))
	
#define RTTI_CONSTRUCTOR_5(__P1, __P2, __P3, __P4, __P5) \
	RTTI_CONSTRUCTOR((__P1, __P2, __P3, __P4, __P5), (new sora::SoraRTTIConstructor4<self, __P1, __P2, __P3, __P4, __P5>()))
	
#define RTTI_CONSTRUCTOR_6(__P1, __P2, __P3, __P4, __P5, __P6) \
	RTTI_CONSTRUCTOR((__P1, __P2, __P3, __P4, __P5, __P6), (new sora::SoraRTTIConstructor4<self, __P1, __P2, __P3, __P4, __P5, __P6>()))

#define RTTI_CONSTRUCTOR_7(__P1, __P2, __P3, __P4, __P5, __P6, __P7) \
	RTTI_CONSTRUCTOR((__P1, __P2, __P3, __P4, __P5, __P6, __P7), (new sora::SoraRTTIConstructor4<self, __P1, __P2, __P3, __P4, __P5, __P6, __P7>()))

#define RTTI_CONSTRUCTOR_8(__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8) \
	RTTI_CONSTRUCTOR((__P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8), (new sora::SoraRTTIConstructor4<self, __P1, __P2, __P3, __P4, __P5, __P6, __P7, __P8>()))

	
#define RTTI_NO_CONSTRUCTOR (*(sora::SoraRTTIConstructorDescriptor*)0)
	
#define DESCRIBE_FIELD(field, type) \
	type RTTIGet##field() {\
		return field;\
	}\
	void RTTISet##field(type* value) {\
		field = *value;\
	}\
	class RTTIFieldHelper##field: public sora::SoraRTTIFieldHelper {\
	public: \
		RTTIFieldHelper##field(unsigned int arrSize=0): mArraySize(arrSize) {}\
		virtual void set(void* obj, sora::SoraRTTIType* val) {\
			sora::SoraRTTIVar<type>* rval = dynamic_cast<sora::SoraRTTIVar<type>*>(val); \
			if(rval) { \
				self* realobj = (self*)obj; \
				type vval = rval->get(); \
				realobj->RTTISet##field(&vval); \
			} else { \
				sora::SoraRTTIType* RTTIType = sora::RTTITypeOfPtr((type*)0); \
				throw sora::SoraRTTIException("SoraRTTIFieldGet: Invalid RTTI Var Type, should be "+RTTIType->getName()+", but token "+val->getName()); \
			} \
		}\
		virtual sora::SoraRTTIVar<type>* get(void* obj) {\
			self* realobj = (self*)obj; \
			sora::SoraRTTIVar<type>* var = new sora::SoraRTTIVar<type>(realobj->RTTIGet##field()); \
			return var;\
		}\
	\
	private:\
		unsigned int mArraySize; \
	};\

#define DESCRIBE_ARRAY(field, type) \
	type* RTTIGet##field() {\
		return &field[0];\
	}\
	void RTTISet##field(type** value, unsigned int arraySize, unsigned int valueSize) {\
		for(int i=0; i<valueSize>arraySize?arraySize:valueSize; ++i)\
			field[i] = *value[i];\
	}\
	class RTTIFieldHelper##field: public sora::SoraRTTIFieldHelper {\
	public: \
		RTTIFieldHelper##field(unsigned int arrSize=0): mArraySize(arrSize) {}\
		virtual void set(void* obj, sora::SoraRTTIType* val) {\
			sora::SoraRTTIVar<type*>* rval = dynamic_cast<sora::SoraRTTIVar<type*>*>(val); \
			if(rval && rval->isArray()) { \
				self* realobj = (self*)obj; \
				type* vval = rval->get(); \
				realobj->RTTISet##field(&vval, mArraySize, rval->getArraySize()); \
			} else { \
				sora::SoraRTTIType* RTTIType = sora::RTTITypeOfPtr((type*)0); \
				throw sora::SoraRTTIException("SoraRTTIFieldGet: Invalid RTTI Var Type, should be "+RTTIType->getName()+", but token "+val->getName()); \
			} \
		} \
		virtual sora::SoraRTTIVar<type*>* get(void* obj) {\
			self* realobj = (self*)obj; \
			var = (realobj->RTTIGet##field()); \
			var.setArray(mArraySize); \
			return &var;\
		}\
	\
	private:\
		unsigned int mArraySize; \
		sora::SoraRTTIVar<type*> var; \
	};\
	
#define DESCRIBE_CLASS(T, fields, methods, baseclasses, constructors) \
	typedef T self; \
	static sora::SoraRTTIClassDescriptor RTTIDescriptor; \
	static sora::SoraRTTIClassDescriptorHelper RTTIDescriptorHelper; \
	\
	static sora::SoraRTTIMethodDescriptor* RTTIMethodDescriptor() { \
		return &methods; \
	} \
	static sora::SoraRTTIDerivedType* RTTIBaseClassDescriptor() { \
		return &baseclasses; \
	} \
	static sora::SoraRTTIFieldDescriptor* RTTIFieldDescriptor() {\
		return &fields; \
	} \
	static sora::SoraRTTIConstructorDescriptor* RTTIConstructor(){\
		return &constructors; \
	}
	
#define REGISTER_CLASS(T, ns, flags) \
	static sora::SoraRTTIMethodDescriptor* RTTIMethod_##T() {\
		return T::RTTIMethodDescriptor(); \
	} \
	static sora::SoraRTTIDerivedType* RTTIBaseClass_##T() {\
		return T::RTTIBaseClassDescriptor(); \
	}\
	static sora::SoraRTTIFieldDescriptor* RTTIField_##T() {\
		return T::RTTIFieldDescriptor(); \
	} \
	static sora::SoraRTTIConstructorDescriptor* RTTIConstructor_##T() {\
		return T::RTTIConstructor(); \
	}\
	namespace sora { \
		template<> \
		SoraRTTIType* RTTIClassTypeHelper<T>::getRTTIType() { \
			return &T::RTTIDescriptor; \
		} \
	} \
	sora::SoraRTTIClassDescriptor T::RTTIDescriptor( \
		#T, \
		sizeof(T), \
		flags, \
		ns \
	); \
	sora::SoraRTTIClassDescriptorHelper T::RTTIDescriptorHelper(RTTIMethod_##T(), \
																RTTIField_##T(), \
																RTTIBaseClass_##T(),\
																RTTIConstructor_##T()); \
	
}

#endif // SORA_RTTI_H_