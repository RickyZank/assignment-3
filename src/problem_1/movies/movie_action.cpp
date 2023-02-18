#include "movie_action.h"

int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    /*
     * TODO: homework
     */
    int base_fee = num_of_days_past_due * get_late_fee_per_day_in_dollar();

    int fee = (num_of_days_past_due >= 5) ? 2 * base_fee : base_fee;
    if(mercy_rule_apply()){
        return 0;
    }
    else{
        return fee;
    }

}

bool MovieAction::action_movie_mercy_rule_apply() {
    return title.find("pulp fiction") != std::string::npos;
}

bool MovieAction::mercy_rule_apply() {
    return StoreMediaInterface::mercy_rule_apply() && action_movie_mercy_rule_apply();
}