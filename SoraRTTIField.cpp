/*
 *  SoraRTTIField.cpp
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/22/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
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