﻿#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FMiniJam155EditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
