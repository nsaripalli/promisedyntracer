#ifndef PROMISEDYNTRACER_PROMISE_LIFECYCLE_SUMMARY_H
#define PROMISEDYNTRACER_PROMISE_LIFECYCLE_SUMMARY_H

#include "PromiseEventGroup.h"
#include "PromiseLifecycle.h"

class PromiseLifecycleSummary {
  public:
    using iterator = promise_lifecycle_sequence_t::iterator;
    using reverse_iterator = promise_lifecycle_sequence_t::reverse_iterator;
    using const_iterator = promise_lifecycle_sequence_t::const_iterator;
    using const_reverse_iterator =
        promise_lifecycle_sequence_t::const_reverse_iterator;
    explicit PromiseLifecycleSummary() {
    }

    size_t size() const {
        return lifecycles_.size();
    }

    bool is_empty() const {
        return lifecycles_.empty();
    }

    iterator begin() {
        return lifecycles_.begin();
    }

    iterator end() {
        return lifecycles_.end();
    }

    reverse_iterator rbegin() {
        return lifecycles_.rbegin();
    }

    reverse_iterator rend() {
        return lifecycles_.rend();
    }

    const_iterator cbegin() const {
        return lifecycles_.cbegin();
    }

    const_iterator cend() const {
        return lifecycles_.cend();
    }

    const_reverse_iterator crbegin() const {
        return lifecycles_.crbegin();
    }

    const_reverse_iterator crend() const {
        return lifecycles_.crend();
    }

    void summarize(const PromiseLifecycle& lifecycle) {
        for (std::size_t i = 0; i < lifecycles_.size(); ++i) {
            if (lifecycles_[i] == lifecycle) {
                lifecycles_[i].increment_count();
                return;
            }
        }
        lifecycles_.push_back(lifecycle);
    }

    /* TODO - add const to PromiseLifecycle in the loop */
    promise_event_group_sequence_t merge(std::size_t total_event_count) {
        promise_event_group_sequence_t groups(total_event_count);
        for (PromiseLifecycle& lifecycle: lifecycles_) {
            std::size_t promise_count = lifecycle.get_count();
            std::size_t index = 0;
            for (const PromiseEvent& event: lifecycle) {
                std::size_t event_count = event.get_count();
                for (std::size_t relative_index = 0;
                     relative_index < event_count;
                     ++relative_index) {
                    groups[index]
                        .get_event(event.get_type())
                        .increment_count(promise_count);
                    ++index;
                    if (index == total_event_count) {
                        break;
                    }
                }
                if (index == total_event_count) {
                    break;
                }
            }
        }
        return groups;
    }

  private:
    promise_lifecycle_sequence_t lifecycles_;
};

#endif /* PROMISEDYNTRACER_PROMISE_LIFECYCLE_SUMMARY_H */
