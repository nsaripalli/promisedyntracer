#ifndef PROMISEDYNTRACER_PROMISE_EVENT_GROUP_H
#define PROMISEDYNTRACER_PROMISE_EVENT_GROUP_H

#include "PromiseEvent.h"

#include <vector>

class PromiseEventGroup {
  public:
    explicit PromiseEventGroup() {
        for (std::size_t event_index = 0;
             event_index < to_underlying(PromiseEvent::Type::Count);
             ++event_index) {
            events_.push_back(
                PromiseEvent(static_cast<PromiseEvent::Type>(event_index), 0));
        }
    }

    PromiseEvent& get_event(const PromiseEvent::Type type) {
        return events_[to_underlying(type)];
    }

    const PromiseEvent& get_event(const PromiseEvent::Type type) const {
        return events_[to_underlying(type)];
    }

  private:
    promise_event_sequence_t events_;
};

using promise_event_group_sequence_t = std::vector<PromiseEventGroup>;

#endif /* PROMISEDYNTRACER_PROMISE_EVENT_GROUP_H */
