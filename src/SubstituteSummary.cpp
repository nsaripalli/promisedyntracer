#include "SubstituteSummary.h"

#include "Call.h"
#include "Function.h"

SubstituteSummary::SubstituteSummary(const Call* const call,
                                     SubstituteClass subst_class) {
    if (call == nullptr) {
        function_id_ = "<no-matching-function-id>";
        function_namespace_ = "<no-matching-function-namespace>";
        function_names_ = "<no-matching-function-names>";
    } else {
        const Function* const function = call->get_function();
        function_id_ = function->get_id();
        function_namespace_ = function->get_namespace();
        function_names_ = function->get_name_string();
    }
    subst_class_ = subst_class;
    call_count_ = 1;
}

bool SubstituteSummary::is_mergeable_(const Call* const call,
                                      SubstituteClass subst_class) {
    function_id_t function_id = "<no-matching-function>";
    if (call != nullptr) {
        function_id = call->get_function()->get_id();
    }
    return (get_function_id() == function_id &&
            get_substitute_class() == subst_class);
}
