library(promisedyntracer)
library(dplyr)
dyntrace_promises({
                    # Recursive function to find factorial
                    recursive.factorial <- function(x) {
                      if (x == 0)    return(1)
                      else
                        starwars %>%
                          filter(species == "Droid")
                      return(x * recursive.factorial(x - 1))
                    }

                    recursive.factorial(5)
                  }
  , './znalysis', 'dplyr')