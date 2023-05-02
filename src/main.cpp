#include "credit_card_validator.h"

int main()
{
	do
	{
		int card_number = 0;
		system("cls");
		std::cout << "Enter the credit card number: ";
		std::cin >> card_number;
		credit_card_validator ccv;
		ccv.start_luhn_algorithm(card_number);
	} while (true);
	return 0;
}
