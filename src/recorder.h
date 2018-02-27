#ifndef __RECORDER_H__
#define __RECORDER_H__

#include "Context.h"
#include "State.h"
#include "sexptypes.h"
#include "utilities.h"

closure_info_t function_entry_get_info(dyntrace_context_t *context,
                                       const SEXP call, const SEXP op,
                                       const SEXP rho);
closure_info_t function_exit_get_info(dyntrace_context_t *context,
                                      const SEXP call, const SEXP op,
                                      const SEXP rho, const SEXP retval);
builtin_info_t builtin_entry_get_info(dyntrace_context_t *context,
                                      const SEXP call, const SEXP op,
                                      const SEXP rho, function_type fn_type);
builtin_info_t builtin_exit_get_info(dyntrace_context_t *context,
                                     const SEXP call, const SEXP op,
                                     const SEXP rho, function_type fn_type,
                                     const SEXP retval);
prom_basic_info_t create_promise_get_info(dyntrace_context_t *context,
                                          const SEXP promise, const SEXP rho);
prom_info_t force_promise_entry_get_info(dyntrace_context_t *context,
                                         const SEXP promise);
prom_info_t force_promise_exit_get_info(dyntrace_context_t *context,
                                        const SEXP promise);
prom_info_t promise_lookup_get_info(dyntrace_context_t *context,
                                    const SEXP promise);
prom_info_t promise_expression_lookup_get_info(dyntrace_context_t *context,
                                               const SEXP prom);

#endif /* __RECORDER_H__ */
