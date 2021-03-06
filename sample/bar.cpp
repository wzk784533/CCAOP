//code generated by ccaop
//https://github.com/wzk784533/CCAOP
#include <iostream>
#include <string>
/*
you can comment the header files above,
if you don't need it in you aop library
*/
#include <dlfcn.h>
#include "foo.h"
/*
In some complex system, you might need some more other head files,which defines the class in your function paramater.
Before compling this code,you must include these head files, avoiding type declariton error complains in complier.
*/
using namespace std;

void Foo::showMessage()
{
   typedef void (*pFunc)(Foo *);
   static void *handle = NULL;
   static void *func = NULL;
   if(!func)
   {
      handle = dlopen("./libfoo.so", RTLD_LAZY);
      func=dlsym(handle,"_ZN3Foo11showMessageEv");
      dlclose(handle);
   }
   /* AOP before */
   /* your code starts here */

   cout<<"Before hook"<<endl;	
		
   //real function call
   pFunc realFunc=(pFunc)(func);
   realFunc(this);
		
   /* AOP after */
   /* your code starts here */ 
   cout<<"after hook"<<endl;
   return;
}
