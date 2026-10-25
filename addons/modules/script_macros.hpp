#define MODULE(MODULE_NAME) GVARMAIN(module##MODULE_NAME)
#define QMODULE(MODULE_NAME) QUOTE(MODULE(MODULE_NAME))

#define GET_CURRENT_TARGET (missionNamespace getVariable ["BIS_fnc_initCuratorAttributes_target", objNull])

// For modules module UIs
#define SIZEX ((safeZoneW / safeZoneH) min 1.2)
#define SIZEY (SIZEX / 1.2)
#define W_PART(num) ((num) * (SIZEX / 40))
#define H_PART(num) ((num) * (SIZEY / 25))
#define X_PART(num) (W_PART(num) + (safeZoneX + (safeZoneW - SIZEX) / 2))
#define Y_PART(num) (H_PART(num) + (safeZoneY + (safeZoneH - SIZEY) / 2))
