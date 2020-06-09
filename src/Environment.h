#ifndef PROMISEDYNTRACER_ENVIRONMENT_H
#define PROMISEDYNTRACER_ENVIRONMENT_H

#include <unordered_map>

typedef int env_id_t;

#include "Variable.h"

class Environment {
  public:
    Environment(const SEXP rho, env_id_t id): rho_(rho), id_(id) {
        bool is_within_two_degrees = (R_GlobalEnv == ENCLOS(ENCLOS(rho))) ||
                                     (R_GlobalEnv == ENCLOS(rho));
        //        std::cout << "Parent Parent is: " << is_within_two_degrees <<
        //        "\n"; std::cout << "Creating Env: " << id << "\n";
    }

    env_id_t get_id() const {
        return id_;
    }

    int getNumBindings() {
        return variable_mapping_.size();
    }

    Variable& lookup(const std::string& symbol) {
        auto iter = variable_mapping_.find(symbol);
        //        std::cout << "Lookup for " << symbol << " in " << id_ << "\n";
        if (iter == variable_mapping_.end()) {
            dyntrace_log_error("Unable to find variable %s in environment.",
                               symbol.c_str());
        }
        return iter->second;
    }

    bool exists(const std::string& symbol) {
        auto iter = variable_mapping_.find(symbol);
        //        std::cout << "Exists " << symbol << " in " << id_ << "\n";
        return (iter != variable_mapping_.end());
    }

    Variable& define(const std::string& symbol,
                     const var_id_t var_id,
                     const timestamp_t timestamp) {
        auto iter = variable_mapping_.insert(
            {symbol, Variable(symbol, var_id, timestamp, rho_, get_id())});
        //        std::cout << "Define " << symbol << " in " << id_ << "\n";
        return iter.first->second;
    }

    Variable remove(const std::string& symbol) {
        const auto iter = variable_mapping_.find(symbol);
        if (iter == variable_mapping_.end()) {
            dyntrace_log_error("ERROR: unable to find variable for removal");
        }
        //        std::cout << "Remove " << symbol << " in " << id_ << "\n";
        ;
        Variable var = iter->second;
        variable_mapping_.erase(iter);
        return var;
    }

  private:
    const SEXP rho_;
    const env_id_t id_;

    std::unordered_map<std::string, Variable> variable_mapping_;
};

#endif /* PROMISEDYNTRACER_ENVIRONMENT_H */
