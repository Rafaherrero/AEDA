#pragma once
#include <exception> 

namespace exception{
    class mem_error;
    class out_of_range;
    class length_error;
    class overflow_error;
    class underflow_error;
    class error_precision;
}

class exception::mem_error:public std::exception
{
    private:
    const char* what_;
    
    public:
    mem_error(void): what_("Memory error"){}
    mem_error(const char* what_arg): what_(what_arg){}
    
    const char* what() const throw(){return what_;}
};

class exception::out_of_range:public std::exception
{
    private:
    const char* what_;
    
    public:
    out_of_range(void): what_("Out of range error"){}
    out_of_range(const char* what_arg): what_(what_arg){}
    
    const char* what() const throw(){return what_;}
};

class exception::length_error:public std::exception
{
    private:
    const char* what_;
    
    public:
    length_error(void): what_("Length error"){}
    length_error(const char* what_arg): what_(what_arg){}
    
    const char* what() const throw(){return what_;}
};

class exception::overflow_error:public std::exception
{
    private:
    const char* what_;
    
    public:
    overflow_error(void): what_("Overflow error"){}
    overflow_error(const char* what_arg): what_(what_arg){}
    
    const char* what() const throw(){return what_;}
};

class exception::underflow_error:public std::exception
{
    private:
    const char* what_;
    
    public:
    underflow_error(void): what_("Underflow error"){}
    underflow_error(const char* what_arg): what_(what_arg){}
    
    const char* what() const throw(){return what_;}
};

class exception::error_precision:public std::exception
{
    private:
    const char* what_;
    
    public:
    error_precision(void): what_("Error de precision"){}
    error_precision(const char* what_arg): what_(what_arg){}
    
    const char* what() const throw(){return what_;}
};