#include "movie_comedy.h"

int MovieComedy::calculate_late_fees(int num_of_days_past_due) {
    /*
     * TODO: homework
     */
    int base_fee = num_of_days_past_due * get_late_fee_per_day_in_dollar();

    int fee = (num_of_days_past_due >= 5) ? 2 * base_fee : base_fee;

    if (num_of_days_past_due == 0) {
        fee = 0;
    } else if (num_of_days_past_due <= 5) {
        fee = late_fee_per_day;
    } else if (num_of_days_past_due <= 10) {
        fee = late_fee_per_day * 2;
    } else {
        fee = late_fee_per_day * num_of_days_past_due;
    }

    return fee;
}
