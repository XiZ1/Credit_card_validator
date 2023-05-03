/*
 *	Copyright (C) 2023 Jakub Gorecki - All Rights Reserved.
 */

#include "credit_card_validator.h"

int main()
{
	credit_card_validator ccv;
	do
	{
		std::string card_number;
		system("cls");
		std::cout << "Enter the credit card number: ";
		std::cin >> card_number;
		ccv.start_luhn_algorithm(card_number);
	} while (true);
}
