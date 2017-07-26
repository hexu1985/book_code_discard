#pragma once

#define TRY_STATIC_VARIABLE_SCENARIO
class Singleton
{
public:
    static Singleton& GetInstance(void);
    
public:
    ~Singleton();
    int DoSomething(void);
    
private:
    Singleton();
    Singleton(Singleton const &);     // purposefully not implemented
    void operator=(Singleton const&); // purposefully not implemented
    
#ifdef TRY_STATIC_VARIABLE_SCENARIO
private:
    static Singleton* m_pInstance;
#endif // TRY_STATIC_VARIABLE_SCENARIO
};
