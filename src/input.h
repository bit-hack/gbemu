#pragma once

#include "definitions.h"

enum class GbButton {
    Up,
    Down,
    Left,
    Right,
    A,
    B,
    Select,
    Start,
    None,
};

class Input {
public:
    void button_pressed(GbButton button);
    void button_released(GbButton button);
    void write(u8 set);

    u8 get_input() const;

private:
    void set_button(GbButton button, bool set);

    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool a = false;
    bool b = false;
    bool select = false;
    bool start = false;

    bool button_switch = false;
    bool direction_switch = false;
};
