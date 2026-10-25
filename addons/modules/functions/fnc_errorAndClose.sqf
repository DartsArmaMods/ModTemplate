#include "..\script_component.hpp"
/*
 * Authors: DartRuffian
 * Shows a message in the modules menu, and then deletes the given logic object and/or closes the given display.
 *
 * Please provide proper credits to those who participate in development.
 * This function was developed for Legion Studios: Core.
 * Do not place in any other mod without permission.
 *
 * Arguments:
 * 0: String or stringtable key <STRING>
 * 1: Logic (optional, default: objNull) <OBJECT>
 * 2: Display (optional, default: displayNull) <DISPLAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * ["message", _logic, _display] call MOD_PREFIX_modules_fnc_errorAndClose
 *
 * Public: No
 */

params ["_message", ["_logic", objNull], ["_display", displayNull]];
TRACE_3("fnc_errorAndClose",_message,_logic,_display);

if (isLocalized _message) then {
    _message = localize _message;
};
[objNull, _message] call BIS_fnc_showCuratorFeedbackMessage;

deleteVehicle _logic;
_display closeDisplay 2;
