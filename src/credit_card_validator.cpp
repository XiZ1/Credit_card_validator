// ReSharper disable IdentifierTypo

#include "credit_card_validator.h"
#include "string"

bool credit_card_validator::start_luhn_algorithm(const int card_number)
{
	credit_card_number_ = std::to_string(card_number);
	if (check_lenght_card_number() && card_number_verification())
	{
		return true;
	}
	return false;
}

bool credit_card_validator::check_lenght_card_number() const
{
	if (credit_card_number_.length() == 16)
	{
		return true;
	}
	system("cls");
	std::cout << "Uncorrected credit card length.\n";
	return false;
}

bool credit_card_validator::card_number_verification()
{
	split_the_number();
	multiply_the_number();
	return true;
}

void credit_card_validator::split_the_number()
{
	for (int i = 0; i < 16; i++)
	{
		splited_number_[i] = static_cast<int>(credit_card_number_[i]);
	}
}

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
