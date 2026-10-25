class CfgVehicles {
    class Module_F;
    class MODULE(Base): Module_F {
        scope = 0;
        scopeCurator = 2;
        author = AUTHOR;

        category = QUOTE(ADDON);
        function = "ace_common_fnc_dummy";
        functionPriority = 1;
        isGlobal = GLOBAL;
        isTriggerActivated = 0;
        curatorCanAttach = 0;
    };

    class MODULE(Example): MODULE(Base) {
        scope = 2;
        scopeCurator = 0;
        author = AUTHOR;
        displayName = "Example";
        // function = QFUNC(moduleExample);
    };

    class MODULE(Example_zeus): MODULE(Base) {
        scope = 1;
        author = AUTHOR;
        displayName = "Example";
        curatorCanAttach = 1;
        // curatorInfoType = QGVAR(RscExample)
    };
};
