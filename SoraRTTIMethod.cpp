/*
 *  SoraRTTIMethod.cpp
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


#include "SoraRTTIMethod.h"
#include "SoraRTTIClass.h"

#include <cassert>

namespace sora {
	
	SoraRTTIMethodType::SoraRTTIMethodType(): SoraRTTIType(RTTI_METHOD), 
		mParamTypes(NULL), mReturnType(NULL), mStatic(false), nParams(0) {
	}
	
	SoraRTTIMethodType::~SoraRTTIMethodType() {
		if(mParamTypes != NULL)
			delete []mParamTypes;
		if(mReturnType->isPointer())
			delete mReturnType;
	}

	std::string SoraRTTIMethodType::getName() {
		if(RTTIName.size() != 0)
			return RTTIName;
		
		if(mReturnType)
			RTTIName += mReturnType->getName();
		RTTIName += " (";
		for(unsigned int i=0; i<nParams; ++i) {
			RTTIName += mParamTypes[i]->getName();
			if(i != nParams-1)
				RTTIName += +", ";
		}
		RTTIName += ");";
		return RTTIName;
	}
	
	unsigned int SoraRTTIMethodType::getParamNum() const {
		return nParams;
	}
	
	SoraRTTIType* SoraRTTIMethodType::getParamType(unsigned int iIndex) const {
		assert(iIndex < nParams);
		
		return mParamTypes[iIndex];
	}
	
	SoraRTTIType** SoraRTTIMethodType::getParamTypes() const {
		return mParamTypes;
	}
	
	SoraRTTIType* SoraRTTIMethodType::getReturnType() const {
		return mReturnType;
	}
	
	SoraRTTIClassDescriptor* SoraRTTIMethodType::getClass() const {
		return mClass;
	}
	
	SoraRTTIMethodDescriptor::SoraRTTIMethodDescriptor(const std::string& name, 
													   int flags, 
													   SoraRTTIMethodType* type, 
													   SoraRTTIClassDescriptor* RTTIClass):
	mName(name), 
	mFlags(flags), 
	mType(type), 
	mIndex(-1),
	mClass(RTTIClass) {
		RTTIClass->addMethod(this);
	}
	
	SoraRTTIMethodDescriptor::~SoraRTTIMethodDescriptor() {
		if(mType)
			delete mType;
	}
	
	SoraRTTIMethodDescriptor& SoraRTTIMethodDescriptor::operator, (SoraRTTIMethodDescriptor& rhs) {
		return *this;
	}
	
	std::string SoraRTTIMethodDescriptor::getDecl() const {
		std::string strName = RTTI_FLAG_TO_STR(mFlags);
		strName += mType->getName();
		size_t spos = strName.rfind("(");
		strName.insert(spos, mName);
		return strName;
	}
	
	std::string SoraRTTIMethodDescriptor::getName() const {
		return mName;
	}
	
	SoraRTTIType* SoraRTTIMethodDescriptor::invoke(void* obj, void* params[]) {
		return mType->invoke(obj, params);
	}
	
	SoraRTTIType* SoraRTTIMethodDescriptor::invoke(void* obj, const std::string& params) {
		return mType->invoke(obj, params);
	}
	
	SoraRTTIClassDescriptor* SoraRTTIMethodDescriptor::getClass() const {
		return mClass;
	}

} // namespace sora