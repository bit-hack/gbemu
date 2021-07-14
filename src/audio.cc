#include "audio.h"
#include "util/log.h"


u8 Audio::read(const Address& address) {

    if (!address.in_range(0xFF10, 0xFF3F)) {
        fatal_error("Error");
        return;
    }

    switch (address.value()) {
        /* TODO: Audio - Channel 1: Tone & Sweep */
        case 0xFF10:
        case 0xFF11:
        case 0xFF12:
        case 0xFF13:
        case 0xFF14:
            return 0xFF;

        /* TODO: Audio - Channel 2: Tone */
        case 0xFF16:
        case 0xFF17:
        case 0xFF18:
        case 0xFF19:
            return 0xFF;

        /* TODO: Audio - Channel 3: Wave Output */
        case 0xFF1A:
        case 0xFF1B:
        case 0xFF1C:
        case 0xFF1D:
        case 0xFF1E:
            return 0xFF;

        /* TODO: Audio - Channel 4: Noise */
        case 0xFF20:
        case 0xFF21:
        case 0xFF22:
        case 0xFF23:
            return 0xFF;

        /* TODO: Audio - Sound Control Registers */
        case 0xFF24:
            /* TODO */
            return 0xFF;

        case 0xFF25:
            /* TODO */
            return 0xFF;

        case 0xFF26:
            /* TODO */
            return 0xFF;
    }

    /* TODO: Audio - Wave Pattern RAM */
    if (address.in_range(0xFF30, 0xFF3F)) {
        return pattern[address.value() & 0xf];
    }

    return 0xff;
}

void Audio::write(const Address& address, u8 byte) {

    if (!address.in_range(0xFF10, 0xFF3F)) {
        fatal_error("Error");
        return;
    }

    switch (address.value()) {
        /* TODO: Audio - Channel 1: Tone & Sweep */
        case 0xFF10:
        case 0xFF11:
        case 0xFF12:
        case 0xFF13:
        case 0xFF14:
            return;

        /* TODO: Audio - Channel 2: Tone */
        case 0xFF16:
        case 0xFF17:
        case 0xFF18:
        case 0xFF19:
            return;

        /* TODO: Audio - Channel 3: Wave Output */
        case 0xFF1A:
        case 0xFF1B:
        case 0xFF1C:
        case 0xFF1D:
        case 0xFF1E:
            return;

        /* TODO: Audio - Channel 4: Noise */
        case 0xFF20:
        case 0xFF21:
        case 0xFF22:
        case 0xFF23:
            return;

        /* TODO: Audio - Sound Control Registers */
        case 0xFF24:
            /* TODO */
            return;

        case 0xFF25:
            /* TODO */
            return;

        case 0xFF26:
            /* TODO */
            return;
    }

    /* TODO: Audio - Wave Pattern RAM */
    if (address.in_range(0xFF30, 0xFF3F)) {
        pattern[address.value() & 0xf] = byte;
        return;
    }
}
