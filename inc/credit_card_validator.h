/*
 *	Copyright (C) 2023 Jakub Gorecki - All Rights Reserved.
 */

// ReSharper disable IdentifierTypo

#pragma once

#include <iostream>

class credit_card_validator
{
	public:

		bool start_luhn_algorithm(const std::string& card_number);

	private:

		std::string credit_card_number_;
		int splited_number_[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		const int multiply_numbers_[10] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
		int sum_of_digits_ = 0;

		bool check_lenght_card_number() const;
		bool card_number_verification();
		void split_the_number();
		void multiply_the_number();
		void summing_digits();
		bool modulo_10() const;
		static void show_message(const std::string& message, const int pause_time);

};
