#ifndef LOGICAL_H
#define LOGICAL_H

class OneArg {
    public:
        virtual int result(bool val) const = 0;
};

class TwoArg {
    public:
    virtual int result(bool val1, bool val2) const = 0;
};

class OR : public TwoArg {
    public:
    int result(bool val1, bool val2) const override;
};

class AND : public TwoArg {
    public:
    int result(bool val1, bool val2) const override;
};

class NOT : public OneArg {
    public:
    int result(bool val1) const override;
};

namespace Logical {
    int eval(const TwoArg& op, bool arg1, bool arg2);
    int eval(const OneArg& op, bool arg);
}

#endif