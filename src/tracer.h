#ifndef PROMISEDYNTRACER_TRACER_H
#define PROMISEDYNTRACER_TRACER_H

#include <Rinternals.h>

#ifdef __cplusplus
extern "C" {
#endif

SEXP create_dyntracer(SEXP package_name,
                      SEXP output_dirpath,
                      SEXP verbose,
                      SEXP truncate,
                      SEXP binary,
                      SEXP compression_level);

SEXP destroy_dyntracer(SEXP dyntracer_sexp);

#ifdef __cplusplus
}
#endif

#endif /* PROMISEDYNTRACER_TRACER_H */
