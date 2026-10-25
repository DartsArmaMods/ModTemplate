#include "..\script_component.hpp"
/*
 * Author: DartRuffian
 * Initializes the <module name> module display.
 *
 * Arguments:
 * 0: Zeus module button <CONTROL>
 *
 * Return Value:
 * None
 *
 * Example:
 * _ctrl call MOD_PREFIX_modules_fnc_ui_example
 *
 * Public: No
*/

params ["_ctrl"];
TRACE_1("fnc_ui_example",_ctrl);

_ctrl ctrlRemoveAllEventHandlers "SetFocus";

private _display = ctrlParent _ctrl;
private _logic = GET_CURRENT_TARGET;
private _unit = attachedTo _logic;

private _exit = true;
switch (false) do {
    case (!isNull _unit): {
        ["$STR_ace_zeus_nothingSelected", _logic, _display] call FUNC(errorAndClose);
    };
    case (alive _unit): {
        ["$STR_ace_zeus_onlyAlive", _logic, _display] call FUNC(errorAndClose);
    };
    default {
        _exit = false;
    };
};

if (_exit) exitWith {};

// Display set up (if needed)

private _fnc_onUnload = {
    deleteVehicle GET_CURRENT_TARGET;
};

private _fnc_onConfirm = {
    params [["_ctrlButtonOK", controlNull, [controlNull]]];

    private _display = ctrlParent _ctrlButtonOK;
    private _logic = GET_CURRENT_TARGET;
    private _unit = attachedTo _logic;

    if (isNull _logic || isNull _display || !alive _unit) exitWith {};

    // Set variables onto logic object

    [QGVAR(moduleExample), [_logic, [_unit], true], _unit] call CBA_fnc_targetEvent;
};

_display displayAddEventHandler ["Unload", _fnc_onUnload];
_ctrl ctrlAddEventHandler ["ButtonClick", _fnc_onConfirm];
