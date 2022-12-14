#pragma once

#include "Account.h"

namespace mdls {
	class Checking : public Account {
	public:

		// constructor that's getting info from db
		Checking(const std::string& num);

		Checking(const Checking&) = default;
		Checking& operator=(const Checking&) = default;

		Checking& operator=(Checking&&) noexcept = default;
		Checking(Checking&&) noexcept = default;

		~Checking() = default;

		inline size_t get_overdraft_lim() const { return overdraft_lim; };

		//TODO delete?
		/*friend mdls::Account& Bank::get_account(const std::string& num);*/
		friend class Bank;

	private:
		Checking(void) = default;

		Checking(
			const std::string& num, size_t dgt_code,
			double balance, const std::string& open_date,
			bool blocked, double atm_fee,
			double intrest, size_t overdraft_lim,
			size_t id = 0, size_t off_id = 0,
			size_t clnt_id = 0, size_t acc_type = 0);

		Checking(
			const Account& acc, size_t overdraft_lim);

		std::ostream& print(std::ostream& os) const override;

		size_t overdraft_lim;
	};
}