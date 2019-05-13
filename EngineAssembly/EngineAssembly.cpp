#include "EngineAssembly\FuelEngines.h"

shared_ptr<Engine> EngineAssembly::GetEngine(const string &type)
{
    return CreateEngine(type);
}
