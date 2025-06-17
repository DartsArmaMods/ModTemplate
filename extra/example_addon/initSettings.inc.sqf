// Can use localize "STR_ACE_Common_Enabled" for name if ACE is required
[
    QGVAR(enabled), "CHECKBOX",
    [LSTRING(enabled_name), LSTRING(enabled_tooltip)],
    _category, true, true
] call CBA_fnc_addSetting;
