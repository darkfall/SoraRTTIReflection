#include <iostream>

#include <vector>
#include <fstream>

#include "SoraRTTI.h"

#include <cassert>

using namespace std;

class Foo {
public:
	Foo():i(1), j(22) {
		fp = new float;
		*fp = 10.f;
	}
	Foo(int _i, int _j): i(_i), j(_j) {}
	Foo(int _i): i(_i), j(10) {}
	
	DESCRIBE_CLASS(Foo, (RTTI_DESCRIBED_FIELD(i, int, sora::RTTI_FLAG_PRIVATE), 
						 RTTI_DESCRIBED_FIELD(j, int, sora::RTTI_FLAG_PRIVATE), 
						 RTTI_DESCRIBED_PTR(fp, float*, sora::RTTI_FLAG_PRIVATE)), 
						 
						(RTTI_METHOD(foo, sora::RTTI_FLAG_PUBLIC), 
						 RTTI_METHOD(bar, sora::RTTI_FLAG_PUBLIC | sora::RTTI_FLAG_VIRTUAL), 
						 RTTI_METHOD(geti, sora::RTTI_FLAG_PUBLIC),
						 RTTI_METHOD(getfp, 0)), 
				   
						RTTI_NO_BASE_CLASS,
				   
						(RTTI_DEFAULT_CONSTRUCTOR(),
						 RTTI_CONSTRUCTOR_1(int),
						 RTTI_CONSTRUCTOR_2(int, int)));
	
	
	DESCRIBE_FIELD(i, int);
	DESCRIBE_FIELD(j, int);
	DESCRIBE_FIELD(fp, float*);
        
	void foo() {
		std::cout<<"Hello World!"<<std::endl;
	}
	
	virtual int bar(int i) {
		return i;
	}
	
	float* getfp() {
		return fp;
	}
	
	int geti() const {
		return i;
	}
	
private:
	int i;
	int j;
	float* fp;
	char* lalala;
};


class Bar: public Foo {
public:
	Bar() {
		ii[0] = 1111;
		ii[1] = 2222;
	}
	virtual int bar(int i) {
		return i*2;
	}
	
	Foo newFoo() {
		return Foo(9999);
	}
	
	void printFoo(Foo* pppp) {
		std::cout<<"foo.i = "<<pppp->geti()<<std::endl;
		std::cout<<"foo.i.Address = "<<&*pppp<<std::endl;
	}
	
	void print(int a) {
		std::cout<<"int: "<<a<<std::endl;
	}
	void print(float a) {
		std::cout<<"float: "<<a<<std::endl;
	}
	
	DESCRIBE_CLASS(Bar, 
				   (RTTI_DESCRIBED_ARRAY(ii, int, 5, sora::RTTI_FLAG_PUBLIC)),
				   (RTTI_METHOD(bar, sora::RTTI_FLAG_PUBLIC | sora::RTTI_FLAG_VIRTUAL),
					RTTI_METHOD(newFoo, sora::RTTI_FLAG_PUBLIC),
					RTTI_OVERLOAD_METHOD_1(print, void, int, sora::RTTI_FLAG_PUBLIC),
					RTTI_OVERLOAD_METHOD_1(print, void, float, sora::RTTI_FLAG_PUBLIC),
					RTTI_METHOD(printFoo, sora::RTTI_FLAG_PUBLIC)),
				    RTTI_BASE_CLASS(Foo, sora::RTTI_FLAG_PUBLIC),
					RTTI_NO_CONSTRUCTOR);
	
	DESCRIBE_ARRAY(ii, int);
    
    int* getii() { return &ii[0]; }
	
private:
	int ii[5];
};

REGISTER_CLASS(Foo, 0, 0);
REGISTER_CLASS(Bar, 0, 0);


Foo foo;
Bar bar;
sora::SoraRTTIClassDescriptor* fooDes;
sora::SoraRTTIClassDescriptor* barDes;
sora::SoraRTTIClassManager* database;

void init() {
    database = sora::SoraRTTIClassManager::Instance();	
}

void testContructor() {
    fooDes = database->findClass("Foo");
	if(fooDes != NULL) {
		std::cout<<fooDes->getDecl()<<std::endl;
		
	}
	barDes = database->findClass("Bar");
	if(barDes != NULL) {
		std::cout<<barDes->getDecl()<<std::endl;
	}
	
	Foo* newfoo1 = sora::RTTIConstructClass<Foo>("Foo", 0, 0, 0);
	std::cout<<"constructed new foo using default constructor, foo::i="<<newfoo1->geti()<<std::endl;
	
	void* params[2];
	int i = 10;
	params[0] = &i;
	Foo* newfoo2 = sora::RTTIConstructClass<Foo>("Foo", params, 1, 0);
	std::cout<<"constructed new foo using Foo::Foo(int i = 10), foo::i="<<newfoo2->geti()<<std::endl;
    
	int j=20;
	i = 33;
	params[1] = &j;
	Foo* newfoo3 = sora::RTTIConstructClass<Foo>("Foo", params, 2, 0);
	std::cout<<"constructed new foo using Foo::Foo(int i = 33, j=20), foo::i="<<newfoo3->geti()<<std::endl;
}

void testField() {
    sora::SoraRTTIFieldDescriptor* iDes = fooDes->findField("i");
    if(iDes != NULL) {
		try {
			int i = sora::SoraRTTIFieldGet<int>(iDes, &foo);
			std::cout<<"Foo::i = "<<i<<std::endl;
		} catch(sora::SoraRTTIException& excp) {
			std::cout<<excp.get()<<std::endl;
		}
	}
	
    // array field
	sora::SoraRTTIFieldDescriptor* iarrDes = barDes->findField("ii");
	if(iarrDes != NULL) {
		try {
			sora::SoraRTTIVar<int*> *pii = sora::SoraRTTIFieldVarGet<int*>(iarrDes, &bar);
			int* ppii = pii->get();
            std::cout<<"Foo::ii: adreess = "<<ppii<<std::endl;
			for(int i=0; i<pii->getArraySize(); ++i) {
				std::cout<<"	"<<*ppii<<std::endl;
				ppii++;
			}
		} catch(sora::SoraRTTIException& excp) {
			std::cout<<excp.get()<<std::endl;
		}
	}
}

void testFunction() {
    fooDes->invoke("foo", &fooDes, NULL);
    
    float* myFp = sora::ReturnValToVar<float*>(fooDes->invoke("getfp", &foo, NULL));
    if(myFp != NULL) {
        std::cout<<"Foo::fp = "<<*myFp<<std::endl;
    }
    
    // overloaded function
    void* overloadparams[1];
    int intparam = 5;
    float floatparam = 5.f;
    overloadparams[0] = &intparam;
    barDes->invoke("print(int)", &bar, overloadparams);
    
    overloadparams[0] = &floatparam;
    barDes->invoke("print(float)", &bar, overloadparams);
    
    
    // custom construction functions
	sora::SoraRTTIMethodDescriptor* nfooFn = barDes->findMethod("newFoo");
	if(nfooFn != NULL) {
		Foo newFoo;
		newFoo = sora::ReturnValToVar<Foo>(nfooFn->invoke(&foo, NULL));
		std::cout<<"newFoo.i = "<<newFoo.geti()<<std::endl;
		
		sora::SoraRTTIMethodDescriptor* printFoo = barDes->findMethod("printFoo");
		if(printFoo != NULL) {
			void* params[1];
			Foo* pnewFoo = &newFoo;
			params[0] = &pnewFoo;
			printFoo->invoke(&bar, params);
		}
	}
    
    // virtual functions
    sora::SoraRTTIMethodDescriptor* fooFn = fooDes->findMethod("bar");
	if(fooFn != NULL) {
		int retVal;
		void* params[1];
		int param = 5;
		params[0] = &param;
		retVal = sora::ReturnValToVar<int>(fooFn->invoke(&foo, params));
		std::cout<<"calling Foo::bar with i=5, @retval = "<<retVal<<std::endl;
	}
	
    {
		int retVal;
		void* params[1];
		int param = 5;
		params[0] = &param;
		retVal = sora::ReturnValToVar<int>(barDes->invoke("bar", &bar, params));
		std::cout<<"calling Bar::bar with i=5, @retval = "<<retVal<<std::endl;
	}
	
}

int main (int argc, char * const argv[]) {
	init();
    testContructor();
    testField();
    testFunction();
    return 0;
}
