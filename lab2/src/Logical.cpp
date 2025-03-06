#include "Logical.h"

int OR::result(bool val1, bool val2) const{
    if(val1 || val2){
        return 1;
    } else {
        return 0;
    }
}

int AND::result(bool val1, bool val2) const{
    if(val1 && val2){
        return 1;
    } else {
        return 0;
    }
}

int NOT::result(bool val1) const{
    if(val1){
        return 0;
    } else {
        return 1;
    }
}

int Logical::eval(const TwoArg& op, bool arg1, bool arg2){
    return op.result(arg1, arg2);
}

int Logical::eval(const OneArg& op, bool arg){
    return op.result(arg);
}