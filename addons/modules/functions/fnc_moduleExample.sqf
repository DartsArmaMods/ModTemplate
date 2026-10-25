#include "..\script_component.hpp"
/*
 * Authors: DartRuffian
 * Example module.
 *
 * Arguments:
 * 0: Module <OBJECT>
 * 1: Affected units (unused) <ARRAY>
 * 2: Activated <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_logic, [], true] call MOD_PREFIX_modules_fnc_moduleExample
 *
 * Public: No
 */

if (canSuspend) exitWith {
    [FUNC(moduleExample), _this] call CBA_fnc_directCall;
};

params ["_logic", "", "_activated"];
TRACE_2("fnc_moduleExample",_logic,_activated);

private _unit = attachedTo _logic;
if !(local _unit && _activated) exitWith {};

if (!_activated) exitWith {};

private _exit = true;
switch (false) do {
    case (!isNull _unit): {
        ["$STR_ace_zeus_nothingSelected", _logic] call FUNC(errorAndClose);
    };
    case (_unit isKindOf "CAManBase"): {
        ["$STR_ace_zeus_onlyInfantry", _logic] call FUNC(errorAndClose);
    };
    case (alive _unit): {
        ["$STR_ace_zeus_onlyAlive", _logic] call FUNC(errorAndClose);
    };
    default { _exit = false };
};

if (_exit) exitWith {};

deleteVehicle _logic;
