/*
 *  SoraRTTIField.cpp
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


#include "SoraRTTIField.h"
#include "SoraRTTIClass.h"

namespace sora {
	
	SoraRTTIFieldDescriptor::SoraRTTIFieldDescriptor(const std::string& name,
													 int flags,
													 SoraRTTIType* type,
													 SoraRTTIFieldHelper* fieldHelper,
													 SoraRTTIClassDescriptor* RTTIClass):
	mName(name),
	mFlags(flags),
	mType(type),
	mFieldHelper(fieldHelper),
	mFieldClass(RTTIClass) {
		RTTIClass->addField(this);
	}
	
	SoraRTTIFieldDescriptor::~SoraRTTIFieldDescriptor() {
		if(mFieldHelper) {
			delete mFieldHelper;
			mFieldHelper = NULL;
		}
		if(mType->isPointer() || mType->isArray()) {
			delete mType;
			mType = NULL;
		}
	}
	
	void SoraRTTIFieldDescriptor::set(void* obj, SoraRTTIType* buffer) {
		if(mFieldHelper)
			mFieldHelper->set(obj, buffer);
	}
	
	SoraRTTIType* SoraRTTIFieldDescriptor::get(void* obj) {
		if(mFieldHelper)
			return mFieldHelper->get(obj);
		return NULL;
	}
	
	int SoraRTTIFieldDescriptor::getFlags() const {
		return mFlags;
	}
	
	std::string SoraRTTIFieldDescriptor::getName() const {
		return mName;
	}
	
	std::string SoraRTTIFieldDescriptor::getDecl() const {
		return RTTI_FLAG_TO_STR(mFlags) + mType->getName()+" "+mName+";";
	}
	
	SoraRTTIType* SoraRTTIFieldDescriptor::getType() const {
		return mType;
	}
	
	SoraRTTIClassDescriptor* SoraRTTIFieldDescriptor::getDescriptorClass() const {
		return mFieldClass;
	}

}