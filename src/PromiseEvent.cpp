#include "PromiseEvent.h"

#include <string>

std::string to_string(const PromiseEvent::Type type) {
    switch (type) {
    case PromiseEvent::Type::Allocate:
        return "Allocate";
    case PromiseEvent::Type::Deallocate:
        return "Deallocate";
    case PromiseEvent::Type::Lookup:
        return "Lookup";
    case PromiseEvent::Type::Preforce:
        return "Preforce";
    case PromiseEvent::Type::Force:
        return "Force";
    case PromiseEvent::Type::Metaprogram:
        return "Metaprogram";
    case PromiseEvent::Type::S3Dispatch:
        return "S3Dispatch";
    case PromiseEvent::Type::S4Dispatch:
        return "S4Dispatch";
    case PromiseEvent::Type::Bound:
        return "Bound";
    case PromiseEvent::Type::Unbound:
        return "Unbound";
    case PromiseEvent::Type::ValueAssign:
        return "ValueAssign";
    case PromiseEvent::Type::Escape:
        return "Escape";
    case PromiseEvent::Type::Deserialize:
        return "Deserialize";
    case PromiseEvent::Type::Count:
        return "Invalid";
    }
    return "Invalid";
};
