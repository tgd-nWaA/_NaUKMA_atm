#pragma once

#include "Account.h"

#include <mysql/jdbc.h>

class Savings : public Account {
public:
	Savings(void) = default;

	Savings(Account&, size_t trans_lim);

	Savings(size_t acc_id, size_t dgt_code,
		size_t off_id, size_t clnt_id,
		size_t acc_type, std::string acc_num,
		double balance, std::string  open_date,
		bool is_blocked, double atm_fee,
		double intrest, size_t trans_lim);

	Savings(const Savings&) = default;
	Savings& operator=(const Savings&) = default;

	~Savings() = default;

	inline size_t get_trans_limit() const { return trans_lim; };

private:
	std::ostream& print(std::ostream& os) const override;

	size_t trans_lim;
};