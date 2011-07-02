/*
 *  SoraRTTIField.h
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/22/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
 */

#ifndef SORA_RTTI_FIELD_H_
#define SORA_RTTI_FIELD_H_

#include "SoraRTTIType.h"
#include "SoraRTTIVar.h"

namespace sora {
	
	class SoraRTTIClassDescriptor;
	
	class SoraRTTIFieldHelper {
	public:
		virtual void set(void* obj, SoraRTTIType* buffer) = 0;
		virtual SoraRTTIType* get(void* obj) = 0;
	};
	
	class SoraRTTIFieldDescriptor {
	public:
		SoraRTTIFieldDescriptor(const std::string& name,
								int flags,
								SoraRTTIType* type,
								SoraRTTIFieldHelper* fieldHelper,
								SoraRTTIClassDescriptor* RTTIClass);
		~SoraRTTIFieldDescriptor();
		
		SoraRTTIFieldDescriptor& operator, (SoraRTTIFieldDescriptor&) {
			return *this;
		}

		void set(void* obj, SoraRTTIType* var);
		SoraRTTIType* get(void* obj);
			
		int getFlags() const;
		
		std::string getName() const;
		std::string getDecl() const;
		
		SoraRTTIType* getType() const;
		
		SoraRTTIClassDescriptor* getDescriptorClass() const;
		
	private:
		std::string mName;
		int mFlags;
		SoraRTTIType* mType;
		
		SoraRTTIFieldHelper* mFieldHelper;
		SoraRTTIClassDescriptor* mFieldClass;
	};
	
	template<typename __T>
	void SoraRTTIFieldSet(SoraRTTIFieldDescriptor* descriptor, void* obj, __T t) {
		SoraRTTIVar<__T> pvar = t;
		descriptor->set(obj, &pvar);
	}
	
	template<typename __T>
	__T SoraRTTIFieldGet(SoraRTTIFieldDescriptor* descriptor, void* obj) {
		SoraRTTIVar<__T>* pvar = dynamic_cast<SoraRTTIVar<__T>*>(descriptor->get(obj));
		if(pvar) {
			__T val = pvar->get();
			delete pvar;
			return val;
		} else {
			SoraRTTIType* type = RTTITypeOfPtr((__T*)0);
			throw SoraRTTIException("SoraRTTIFieldGet: Invalid RTTI Var Type, should be "+descriptor->getType()->getName()+", but token "+type->getName());
		}
		return RTTIDefaultValue<__T>::Default();
	}
	
	template<typename __T>
	void SoraRTTIFieldVarSet(SoraRTTIFieldDescriptor* descriptor, void* obj, SoraRTTIVar<__T>* t) {
		descriptor->set(obj, t);
	}
	
	template<typename __T>
	SoraRTTIVar<__T>* SoraRTTIFieldVarGet(SoraRTTIFieldDescriptor* descriptor, void* obj) {
		SoraRTTIVar<__T>* pvar = dynamic_cast<SoraRTTIVar<__T>*>(descriptor->get(obj));
		if(pvar) {
			return pvar;
		} else {
			SoraRTTIType* type = RTTITypeOfPtr((__T*)0);
			throw SoraRTTIException("SoraRTTIFieldGet: Invalid RTTI Var Type, should be "+descriptor->getType()->getName()+", but token "+type->getName());
		}
		return NULL;
	}
	
}


#endif // SORA_RTTI_FIELD_H_
