#include "..\script_component.hpp"
/*
 * Authors: DartRuffian
 * Example module.
 *
 * Arguments:
 * 0: Player <OBJECT>
 * 1: Sling mode <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * player call hoa_modules_fnc_moduleExample
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
