// ReSharper disable IdentifierTypo

#include "credit_card_validator.h"
#include "string"
#include "Windows.h"

//
// PUBLIC METHOD
//

bool credit_card_validator::start_luhn_algorithm(const std::string& card_number)
{
	credit_card_number_ = card_number;
	if (check_lenght_card_number() && card_number_verification())
	{
		show_message("Credit card number is correct!\n", 2000);
		return true;
	}
	show_message("Credit card number is incorrect!\n", 2000);
	return false;
}

//
// PRIVATE METHOD
//

bool credit_card_validator::check_lenght_card_number() const
{
	if (credit_card_number_.length() == 16)
	{
		return true;
	}
	return false;
}

bool credit_card_validator::card_number_verification()
{
	split_the_number();
	multiply_the_number();
	summing_digits();
	if (modulo_10())
	{
		return true;
	}
	return false;
}

/**
 * \brief: This function breaks the credit card number given as a string into single digits and stores them as int.
 */
void credit_card_validator::split_the_number()
{
	for (int i = 0; i < 16; i++)
	{
		splited_number_[i] = credit_card_number_[i] - 48;
	}
}

/**
 * \brief: This function looks for even positions in a credit card number and multiplies them by two. 
 */
void credit_card_validator::multiply_the_number()
{
	for (int i = 15; i >= 0; i--)
	{
		if (i % 2 == 0)
		{
			for (int y = 0; y < 9; y++)
			{
				if (splited_number_[i] == y)
				{
					splited_number_[i] = multiply_numbers_[y];
					break;
				}
			}
		}
	}
}

/**
 * \brief: This function sums up all digit of a credit card.
 */
void credit_card_validator::summing_digits()
{
	for (int i = 0; i < 16; i++)
	{
		sum_of_digits_ += splited_number_[i];
	}
}

/**
 * \brief: This function checks the correctness of the provided credit card number. 
 * \return: Function returns true if sum of credit card digits divided by ten will be integer.
 */
bool credit_card_validator::modulo_10() const
{
	if (sum_of_digits_ % 10 == 0)
	{
		return true;
	}
	return false;
}

void credit_card_validator::show_message(const std::string& message, const int pause_time)
{
	system("cls");
	std::cout << message;
	Sleep(pause_time);
}
