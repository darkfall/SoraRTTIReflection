/*
 *  SoraRTTIClass.cpp
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



#include "SoraRTTIClass.h"
#include "SoraRTTIClassManager.h"

#include <algorithm>

namespace sora {
	
	SoraRTTIDerivedType::SoraRTTIDerivedType(SoraRTTIClassDescriptor* derviedClass,
											 SoraRTTIClassDescriptor* baseClass,
											 int flags): SoraRTTIType(RTTI_DERIVED),
	mFlag(flags),
	mBaseClass(baseClass) {
		derviedClass->addBaseClass(this);
	}
	
	std::string SoraRTTIDerivedType::getDecl() {
		if(RTTIName.size() != 0)
			return RTTIName;
		
		if(mFlag & RTTI_FLAG_PUBLIC) RTTIName = "public";
		if(mFlag & RTTI_FLAG_PRIVATE) RTTIName = "private";
		if(mFlag & RTTI_FLAG_PROTECTED) RTTIName = "protected";
		
		RTTIName += " "+mBaseClass->getName();
		return RTTIName;
	}
	
	std::string SoraRTTIDerivedType::getName() {
		return mBaseClass->getName();
	}
	
	SoraRTTIDerivedType& SoraRTTIDerivedType::operator, (SoraRTTIDerivedType&) {
		return *this;
	}
	
	SoraRTTIClassDescriptor* SoraRTTIDerivedType::getBaseClass() const {
		return mBaseClass;
	}
	
	int SoraRTTIDerivedType::getFlag() const {
		return mFlag;
	}
	
	SoraRTTIConstructorDescriptor::SoraRTTIConstructorDescriptor(const std::string& name,
																 SoraRTTIClassDescriptor* parentClass, 
																 SoraRTTIConstructor* constructor): 
	mSignature(name),
	mConstructor(constructor),
	mClass(parentClass) {
		mClass->addConstructor(this);
	}
	
	std::string SoraRTTIConstructorDescriptor::getSignature() const {
		return mSignature;
	}
	
	SoraRTTIConstructorDescriptor::~SoraRTTIConstructorDescriptor() {
		if(mConstructor) {
			delete mConstructor;
		}
	}
	
	void* SoraRTTIConstructorDescriptor::operator()(void** params) {
		return mConstructor->operator()(params);
	}
	
	int SoraRTTIConstructorDescriptor::getParamNum() const {
		return mConstructor->getParamNum();
	}
	
	SoraRTTIClassDescriptor::SoraRTTIClassDescriptor(const std::string& name,
													 unsigned int size,
													 int flags,
													 const char* ns): SoraRTTIType(RTTI_CLASS),
	mClassName(name),
	mClassSize(size) {
		SoraRTTIClassManager::Instance()->addClass(this);
		if(ns != NULL)
			mNamespace = ns;
	}
	
	SoraRTTIClassDescriptor::~SoraRTTIClassDescriptor() {
	}
	
	std::string SoraRTTIClassDescriptor::getDecl() {
		if(RTTIName.size() != 0)
			return RTTIName;
		
		buildDecl();
		return RTTIName;
	}
	
	void SoraRTTIClassDescriptor::buildDecl() {
		RTTIName = "class ";
		RTTIName += mClassName;
		if(mBaseClasses.size() != 0) {
			RTTIName += ": ";
			BASE_CLASS_LIST::const_iterator itBaseClass = mBaseClasses.begin();
			while(itBaseClass != mBaseClasses.end()) {
				RTTIName += (*itBaseClass)->getDecl();
				if((*itBaseClass) != mBaseClasses.back())
					RTTIName += ", ";
				
				++itBaseClass;
			}
		}
		RTTIName += " {\n";
		CONSTRUCTOR_LIST::iterator itConstructor = mConstructors.begin();
		while(itConstructor != mConstructors.end()) {
			RTTIName += "	"+getName()+(*itConstructor)->getSignature()+"\n";
			++itConstructor;
		}
		METHOD_LIST::iterator itMethod = mMethods.begin();
		while(itMethod != mMethods.end()) {
			RTTIName += "	"+(*itMethod)->getDecl()+"\n";
			++itMethod;
		}
		if(mFields.size() != 0)
			RTTIName += "\n";
		
		FIELD_LIST::iterator itField = mFields.begin();
		while(itField != mFields.end()) {
			RTTIName += "	"+(*itField)->getDecl()+"\n";
			++itField;
		}
		RTTIName += "};";
	}
	
	std::string SoraRTTIClassDescriptor::getName() {
		return mNamespace+mClassName;
	}
	
	std::string SoraRTTIClassDescriptor::getNamespace() const {
		return mNamespace;
	}
	
	std::string SoraRTTIClassDescriptor::getDescription() const {
		return mDescription;
	}
	
	SoraRTTIClassDescriptor::METHOD_LIST& SoraRTTIClassDescriptor::getMethods() { 
		return mMethods;
	}
	
	SoraRTTIClassDescriptor::FIELD_LIST&  SoraRTTIClassDescriptor::getFields()  { 
		return mFields;
	}
	
	SoraRTTIClassDescriptor::BASE_CLASS_LIST& SoraRTTIClassDescriptor::getBaseClasses() {
		return mBaseClasses;
	}
	
	void SoraRTTIClassDescriptor::addMethod(SoraRTTIMethodDescriptor* descriptor) {
		mMethods.push_back(descriptor);
	}
	
	void SoraRTTIClassDescriptor::addField(SoraRTTIFieldDescriptor* field ) {
		mFields.push_back(field);
	}
	
	void SoraRTTIClassDescriptor::addBaseClass(SoraRTTIDerivedType* baseClass){
		mBaseClasses.push_back(baseClass);
	}
	
	void SoraRTTIClassDescriptor::addConstructor(SoraRTTIConstructorDescriptor* constructor) {
		mConstructors.push_back(constructor);
	}
    
    SoraRTTIType* SoraRTTIClassDescriptor::invoke(const std::string& name, void* obj, void* params[]) {
        SoraRTTIMethodDescriptor* method = findMethod(name);
        if(method)
            return method->invoke(obj, params);
        return NULL;
    }
	
	SoraRTTIMethodDescriptor* SoraRTTIClassDescriptor::findMethod(const std::string& name) {
		METHOD_LIST::iterator itMethod = std::find_if(mMethods.begin(), mMethods.end(), std::bind2nd(MethodComparer(), name));
		if(itMethod != mMethods.end()) {
			return *itMethod;
		}
		if(mBaseClasses.size() != 0) {
			BASE_CLASS_LIST::iterator itBaseClass = mBaseClasses.begin();
			while(itBaseClass != mBaseClasses.end()) {
				SoraRTTIMethodDescriptor* descriptor = (*itBaseClass)->getBaseClass()->findMethod(name);
				if(descriptor != NULL) {
					return descriptor;
				}
				
				++itBaseClass;
			}
		}
		return NULL;
	}
	
	SoraRTTIFieldDescriptor* SoraRTTIClassDescriptor::findField(const std::string& name) {
		FIELD_LIST::iterator itField = std::find_if(mFields.begin(), mFields.end(), std::bind2nd(FieldComparer(), name));
		if(itField != mFields.end()) {
			return *itField;
		}
		if(mBaseClasses.size() != 0) {
			BASE_CLASS_LIST::iterator itBaseClass = mBaseClasses.begin();
			while(itBaseClass != mBaseClasses.end()) {
				SoraRTTIFieldDescriptor* descriptor = (*itBaseClass)->getBaseClass()->findField(name);
				if(descriptor != NULL) {
					return descriptor;
				}
				
				++itBaseClass;
			}
		}
		return NULL;
	}
	
	SoraRTTIClassDescriptor* SoraRTTIClassDescriptor::findBaseClass(const std::string& name) {
		BASE_CLASS_LIST::iterator itBaseClass = std::find_if(mBaseClasses.begin(), mBaseClasses.end(), std::bind2nd(BaseClassComparer(), name));
		if(itBaseClass != mBaseClasses.end()) {
			return (*itBaseClass)->getBaseClass();
		} else {
			BASE_CLASS_LIST::iterator itBaseClass = mBaseClasses.begin();
			while(itBaseClass != mBaseClasses.end()) {
				SoraRTTIClassDescriptor* descriptor = (*itBaseClass)->getBaseClass()->findBaseClass(name);
				if(descriptor != NULL) {
					return descriptor;
				}
				
				++itBaseClass;
			}
		}
		return NULL;
	}
	
	SoraRTTIConstructorDescriptor* SoraRTTIClassDescriptor::findConstructor(const std::string& name) {
		CONSTRUCTOR_LIST::iterator itConstructor = std::find_if(mConstructors.begin(), mConstructors.end(), std::bind2nd(ConstructorComparer(), name));
		if(itConstructor != mConstructors.end())
			return (*itConstructor);
		return NULL;
	}
	
	void* SoraRTTIClassDescriptor::constructClass(void** params, unsigned int paramsize, const char* signature) {
		CONSTRUCTOR_LIST::iterator itConstructor = mConstructors.begin();
		while(itConstructor != mConstructors.end()) {
			if(params == NULL && (*itConstructor)->getParamNum() == 0) 
				return (*itConstructor)->operator()(params);
			else if(params != NULL && signature == NULL) {
				if(paramsize == (*itConstructor)->getParamNum()) {
					return (*itConstructor)->operator()(params);
				}
			} else if(signature != NULL) {
				if((*itConstructor)->getSignature().compare(signature) == 0)
					return (*itConstructor)->operator()(params);
			}
			++itConstructor;
		}
		return NULL;
	}

} // namespace sora