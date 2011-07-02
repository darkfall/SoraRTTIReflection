/*
 *  SoraSingleton.h
 *  Plugin Concept
 *
 *  Created by griffin clare on 8/24/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SORA_SINGLETON_H_
#define SORA_SINGLETON_H_

namespace sora {
	
	template<class T>
	class SoraSingleton {
	public:
		static T* Instance() {
			if(!pInstance) pInstance = new T;
			return pInstance;
		}
	
		static void Destroy() { if(pInstance) delete pInstance; }
	
	private:
		static T* pInstance;
		SoraSingleton(const SoraSingleton& singleton){}
		SoraSingleton& operator=(const SoraSingleton& singleton){}
	
	protected:
		SoraSingleton() {}
		virtual ~SoraSingleton() {}
		
	};

	template<class T>
	T* SoraSingleton<T>::pInstance = 0;
	
} // namespace sora

#endif // SORA_SINGLETON_H