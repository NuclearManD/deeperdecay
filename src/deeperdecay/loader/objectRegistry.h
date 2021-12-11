//
// Created by nuclaer on 12/11/21.
//

#ifndef DEEPERDECAY_OBJECTREGISTRY_H
#define DEEPERDECAY_OBJECTREGISTRY_H

#include "deeperdecay/objects/DynamicallyDefinedObject.h"


void loadObjects();
DynamicObjectDefinition* getObjectDefinitionById(const char* id);
GameObject* instantiateObjectById(const char* id);


#endif //DEEPERDECAY_OBJECTREGISTRY_H
