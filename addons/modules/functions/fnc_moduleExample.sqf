#include "..\script_component.hpp"
/*
 * Authors: DartRuffian
 * Example module.
 *
 * Arguments:
 * 0: Module <OBJECT>
 * 1: Affected units <ARRAY>
 * 2: Activated <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * player call MOD_PREFIX_modules_fnc_moduleExample
 *
 * Public: No
 */

if (canSuspend) exitWith {
    [FUNC(moduleExample), _this] call CBA_fnc_directCall;
};

params ["_logic", "_units", "_activated"];
TRACE_3("fnc_moduleExample",_logic,_units,_activated);

if (!_activated) exitWith {};

// ...
