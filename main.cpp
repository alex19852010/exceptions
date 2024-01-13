#include <iostream>
#include <cassert>
#include <exception>
#include <vector>

using namespace std;

struct Message
{
   char * data;

   Message(char * indata) : data(indata)
   {}

   void print()
   {
    cout << data << endl;
   }
};

int main()
{

Message m("hello skillbox");
m.print();

  

    return 0;
}