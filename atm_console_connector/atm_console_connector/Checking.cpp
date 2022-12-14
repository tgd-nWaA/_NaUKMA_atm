#include "Bank.h"

#include "Checking.h"

mdls::Checking::Checking(
	const std::string& num, size_t dgt_code,
	double balance, const std::string& open_date,
	bool blocked, double atm_fee,
	double intrest, size_t overdraft_lim,
	size_t id, size_t off_id,
	size_t clnt_id, size_t acc_type)
	: Account(
		num, dgt_code,
		balance, open_date,
		blocked, atm_fee,
		intrest, id,
		off_id, clnt_id, acc_type),
		overdraft_lim(overdraft_lim) {};

mdls::Checking::Checking(
	const Account& acc, size_t overdraft_lim)
	: Checking(
		acc.num(), acc.digital_code(),
		acc.balance(), acc.open_date(),
		acc.is_blocked(), acc.atm_fee(),
		acc.intrest(), overdraft_lim,
		acc.id(), acc.office_id(),
		acc.client_id(), acc.type()) {};

//mdls::Checking::Checking(std::string num)
//	: Cheking(Bank::get_checking(num)) {};


std::ostream& mdls::Checking::print(std::ostream& os) const {
	std::cout << "Checking print\n";
	return Account::print(os) << "Overdraft limit is: " << overdraft_lim << "\n";
}



