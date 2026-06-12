#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        authors[] = {"DartRuffian"};
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            #include "addons.hpp"
        };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};
