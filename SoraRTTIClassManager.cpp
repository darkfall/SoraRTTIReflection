/*
 *  SoraRTTIClassManager.cpp
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/24/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
 */


#include "SoraRTTIClassManager.h"

namespace sora {

	SoraRTTIClassManager::SoraRTTIClassManager() {
	}
	
	SoraRTTIClassManager::~SoraRTTIClassManager() {
	}
	
	void SoraRTTIClassManager::addClass(SoraRTTIClassDescriptor* pclass) {
		mRTTIClasses[pclass->getName()] = pclass;
	}
	
	SoraRTTIClassDescriptor* SoraRTTIClassManager::findClass(const std::string& className) {
		CLASS_MAP::iterator itClass = mRTTIClasses.find(className);
		if(itClass != mRTTIClasses.end()) {
			return itClass->second;
		}
		return NULL;
	}

	void* SoraRTTIClassManager::constructClass(const std::string& className, void** params, unsigned int paramSize, const char* signature) {
		CLASS_MAP::iterator itClass = mRTTIClasses.find(className);
		if(itClass != mRTTIClasses.end()) {
			return itClass->second->constructClass(params, paramSize, signature);
		} else 
			throw SoraRTTIException("SoraRTTIClassManager: no "+className+" found in RTTI database");
		return NULL;
	}

} // namespace sora