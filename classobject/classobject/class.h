#if !defined(CLASS_H)
#define CLASS_H


class VSphereAPI
{
public:
    
    VSphereAPI(bool debug_ = false);

   	bool dbg;

private:
    //const bool debug;       // true == turn on the debug message logging
    bool debug;		// true == turn on the debug message logging

};

#endif