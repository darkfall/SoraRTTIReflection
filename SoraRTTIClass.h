/*
 *  SoraRTTIClass.h
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


#ifndef SORA_RTTI_CLASS_H_
#define SORA_RTTI_CLASS_H_

#include "SoraRTTIType.h"
#include "SoraRTTIMethod.h"
#include "SoraRTTIField.h"
#include "SoraRTTIConstructor.h"

#include <list>
#include <vector>

namespace sora {

	class SoraRTTIClassDescriptor;
	
	class SoraRTTIDerivedType: public SoraRTTIType {
	public:
		SoraRTTIDerivedType(SoraRTTIClassDescriptor* derviedClass,
							SoraRTTIClassDescriptor* baseClass,
							int flags);
		
		std::string getDecl();
		virtual std::string getName();
		SoraRTTIDerivedType& operator, (SoraRTTIDerivedType&);
		
		int getFlag() const;
		SoraRTTIClassDescriptor* getBaseClass() const;
		
	private:
		int mFlag;
		SoraRTTIClassDescriptor* mBaseClass;
	};
	
	class SoraRTTIConstructorDescriptor {
	public:
		SoraRTTIConstructorDescriptor(const std::string& signature,
									  SoraRTTIClassDescriptor* parentClass, 
									  SoraRTTIConstructor* constructor);
		
		~SoraRTTIConstructorDescriptor();
		
		void* operator()(void** params);
		
		int getParamNum() const;
		
		std::string getSignature() const;
		
	private:
		std::string mSignature;
		
		SoraRTTIConstructor* mConstructor;
		SoraRTTIClassDescriptor* mClass;
	};	
	
	class SoraRTTIClassDescriptorHelper {
	public:
		SoraRTTIClassDescriptorHelper(
									  SoraRTTIMethodDescriptor*,
									  SoraRTTIFieldDescriptor*,
									  SoraRTTIDerivedType*,
									  SoraRTTIConstructorDescriptor*
									  ) {
		}
	};
	
	class SoraRTTIClassDescriptor: public SoraRTTIType {
	public:
		SoraRTTIClassDescriptor(const std::string& name,
								unsigned int size,
								int flags,
								const char* ns=NULL);
		virtual ~SoraRTTIClassDescriptor();
		
		typedef std::list<SoraRTTIMethodDescriptor*> METHOD_LIST;
		typedef std::list<SoraRTTIFieldDescriptor*> FIELD_LIST;
		typedef std::list<SoraRTTIDerivedType*> BASE_CLASS_LIST;
		typedef std::list<SoraRTTIConstructorDescriptor*> CONSTRUCTOR_LIST;
		
		std::string getDecl();
		virtual std::string getName();
		
		std::string getNamespace() const;
		std::string getDescription() const;
		
		void* constructClass(void** params, unsigned int paramsize, const char* signature=NULL);
        SoraRTTIType* invoke(const std::string& name, void* obj, void* params[]);
		
		METHOD_LIST&		getMethods();
		FIELD_LIST&			getFields();
		BASE_CLASS_LIST&	getBaseClasses();
		CONSTRUCTOR_LIST&	getConstructors();
		
		SoraRTTIMethodDescriptor*		findMethod(const std::string& name);
		SoraRTTIFieldDescriptor*		findField(const std::string& name);
		SoraRTTIClassDescriptor*		findBaseClass(const std::string& name);
		SoraRTTIConstructorDescriptor*	findConstructor(const std::string& name);
		
		void addMethod(SoraRTTIMethodDescriptor* descriptor);
		void addField(SoraRTTIFieldDescriptor* field);
		void addBaseClass(SoraRTTIDerivedType* baseClass);
		void addConstructor(SoraRTTIConstructorDescriptor* constructor);
		
	protected:
		inline void buildDecl();
		
		struct MethodComparer: public std::binary_function<SoraRTTIMethodDescriptor*, std::string, bool> {
			bool operator()(SoraRTTIMethodDescriptor* descriptor, const std::string& name) const {
				return descriptor->getName() == name;
			}
		};
		
		struct FieldComparer: public std::binary_function<SoraRTTIFieldDescriptor*, std::string, bool> {
			bool operator()(SoraRTTIFieldDescriptor* descriptor, const std::string& name) const {
				return descriptor->getName() == name;
			}
		};
		
		struct BaseClassComparer: public std::binary_function<SoraRTTIDerivedType*, std::string, bool> {
			bool operator()(SoraRTTIDerivedType* descriptor, const std::string& name) const {
				return descriptor->getBaseClass()->getName() == name;
			}
		};
		
		struct ConstructorComparer: public std::binary_function<SoraRTTIConstructorDescriptor*, std::string, bool> {
			bool operator()(SoraRTTIConstructorDescriptor* descriptor, const std::string& name) const {
				return descriptor->getSignature() == name;
			}
		};
		
		std::string mClassName;
		std::string mNamespace;
		std::string mDescription;
		
		unsigned int mClassSize;
		
		METHOD_LIST			mMethods;
		FIELD_LIST			mFields;
		BASE_CLASS_LIST		mBaseClasses;
		CONSTRUCTOR_LIST	mConstructors;
	};
	
} // namespace sora


#endif // SORA_RTTI_CLASS_H_