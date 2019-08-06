#ifndef PROMISEDYNTRACER_SIDE_EFFECT_MODE_H
#define PROMISEDYNTRACER_SIDE_EFFECT_MODE_H

#include <string>

enum class SideEffectMode {
    SameEnvironment,
    LexicalEnvironment,
    OtherEnvironment
};

inline std::string to_string(const SideEffectMode side_effect_mode) {
    switch (side_effect_mode) {
    case SideEffectMode::SameEnvironment:
        return "S";
    case SideEffectMode::LexicalEnvironment:
        return "L";
    case SideEffectMode::OtherEnvironment:
        return "O";
    }

    return "Undefined";
}

#endif /* PROMISEDYNTRACER_SIDE_EFFECT_MODE_H */
