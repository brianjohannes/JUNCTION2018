#pragma once
// Copyright (c) Suunto Oy 2016. All rights reserved.

#include "whiteboard/LaunchableModule.h"

namespace whiteboard
{
namespace services
{

/**
* Class to instantiate bypass service in 'application' context.
* This class implements launchable module interface (LaunchableModule).
*
* We could implement LaunchableModule directly in BypassProvider, 
* but use separate class so that toggling WB_HAVE_BYPASS is cleaner
* on the application side.
*/
class WB_API BypassService FINAL : private LaunchableModule
{
public:
    /** Name of this class. Used in StartupProvider list. */
    static const char* const LAUNCHABLE_NAME;

    /** Constructor
    */
    BypassService();

    /** Destructor */
    ~BypassService();

private:
    /// @see whiteboard::ILaunchableModule::initModule
    virtual bool initModule() OVERRIDE;
    /// @see whiteboard::ILaunchableModule::deinitModule
    virtual void deinitModule() OVERRIDE;
    /// @see whiteboard::ILaunchableModule::startModule
    virtual bool startModule() OVERRIDE;
    /// @see whiteboard::ILaunchableModule::stopModule 
    virtual void stopModule() OVERRIDE;
};

}   // namespace services
}   // namespace whiteboard
