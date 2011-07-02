/*
 *  SoraRTTIException.h
 *  PartitionTree
 *
 *  Created by Griffin Bu on 5/24/11.
 *  Copyright 2011 Studio Symphonie. All rights reserved.
 *
 */

#ifndef SORA_RTTI_EXCEPTION_H_
#define SORA_RTTI_EXCEPTION_H_

#include <string>

namespace sora {
	
	class SoraRTTIException {
	public:
		SoraRTTIException(const std::string& message): mMessage(message) {}
		
		std::string get() const { return mMessage; }
		
	private:
		std::string mMessage;
	};
	
} // namespace sora


#endif // SORA_RTTI_EXCEPTION_H_