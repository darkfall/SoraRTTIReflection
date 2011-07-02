/*
 *  SoraRTTIClassManager.h
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/24/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
 */

#ifndef SORA_RTTI_CLASS_MANAGER_H_
#define SORA_RTTI_CLASS_MANAGER_H_

#include "SoraSingleton.h"
#include "SoraRTTIClass.h"

#include <map>

namespace sora {
	
	class SoraRTTIClassManager: public SoraSingleton<SoraRTTIClassManager> {
	protected:
		friend class SoraSingleton<SoraRTTIClassManager>;
		
		SoraRTTIClassManager();
		~SoraRTTIClassManager();
		
	public:
		
		void addClass(SoraRTTIClassDescriptor* pclass);
		
		SoraRTTIClassDescriptor* findClass(const std::string& className);
		
		void* constructClass(const std::string& className, void** params, unsigned int paramSize, const char* signature);
		
	protected:
		typedef std::map<std::string, SoraRTTIClassDescriptor*> CLASS_MAP;
		CLASS_MAP mRTTIClasses;
	};
	
	template<typename __C>
	__C* RTTIConstructClass(const std::string& className, void** params, unsigned int paramSize, const char* signature) {
		return (__C*)SoraRTTIClassManager::Instance()->constructClass(className, params, paramSize, signature);
	}
	
}

#endif // SORA_RTTI_CLASS_MANAGER_H_