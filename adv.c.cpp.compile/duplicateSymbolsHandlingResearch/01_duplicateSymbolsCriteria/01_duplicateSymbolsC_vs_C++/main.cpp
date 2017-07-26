#include <iostream>
using namespace std;

class CTest
{
public:
    CTest(){ x = 0;};
    ~CTest(){};
    
public:
    int runTest(void){ return x;};
  
private:
    int x;
};

int function_with_duplicated_name(int x)
{
    cout << __FUNCTION__ << "(x)" << endl;
    return 0;	
}

float function_with_duplicated_name(int x)
{
    cout << __FUNCTION__ << "(x)" << endl;
    return 0.0f;		
}

int function_with_duplicated_name(int x, int y)
{
    cout << __FUNCTION__ << "(x,y)" << endl;
    return 0;	
}

int main(int argc, char* argv[])
{
    CTest test;
    int x = test.runTest();
	
    function_with_duplicated_name(x);
    function_with_duplicated_name(x,1);
    return 0;	
}
