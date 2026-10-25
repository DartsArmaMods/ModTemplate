class RscControlsGroupNoScrollbars;
class RscText;
class ctrlToolbox;

class RscDisplayAttributes {
    class Controls {
        class Background;
        class Title;
        class Content;
        class ButtonOK;
        class ButtonCancel;
    };
};

class GVAR(AttributeToolbox): RscControlsGroupNoScrollbars {
    idc = -1;
    onSetFocus = "";
    x = 0;
    y = 0;
    w = QUOTE(W_PART(26));
    h = QUOTE(H_PART(1.1));
    class Controls {
        class Label: RscText {
            idc = IDC_LABEL;
            text = "";
            tooltip = "";
            x = 0;
            y = 0;
            w = QUOTE(W_PART(LABEL_W));
            h = QUOTE(H_PART(1));
            colorBackground[] = {0, 0, 0, 0.5};
        };
        class Toolbox: ctrlToolbox {
            idc = IDC_VALUE;
            x = QUOTE(W_PART(LABEL_W + LABEL_SPACING));
            y = 0;
            w = QUOTE(W_PART(15.9));
            h = QUOTE(H_PART(1));
            rows = 1;
            columns = 1;
            strings[] = {};
        };
    };
};

class GVAR(RscExample): RscDisplayAttributes {
    onLoad = QUOTE([ARR_3('onLoad',_this,QQGVAR(RscExample))] call ace_zeus_fnc_modulesAttributes);
    onUnload = QUOTE([ARR_3('onUnload',_this,QQGVAR(RscExample))] call ace_zeus_fnc_modulesAttributes);
    class Controls: Controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                // ...
            };
        };

        class ButtonOK: ButtonOK {
            onSetFocus = QUOTE(call FUNC(ui_example));
        };
        class ButtonCancel: ButtonCancel {};
    };
};
