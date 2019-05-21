#ifndef ENGINE_ASSEMBLY_H
#define ENGINE_ASSEMBLY_H

#include "Engine\Engine.h"

class EngineAssembly
{
protected:
    virtual shared_ptr<Engine> CreateEngine(const string &type) = 0;

public:
    shared_ptr<Engine> GetEngine(const string &type);
};

#endif // ENGINE_ASSEMBLY_H
