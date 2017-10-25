/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:00:32 by zgodongw          #+#    #+#             */
/*   Updated: 2017/10/25 08:52:23 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.hpp"

#pragma once

class Error : public Rules {

	public:
		Error () {
			// empty constructor
		}

	private:
		
		bool			isOperator(char c)
		{
			if (c == '+' || c == '|' || c == '>' || c == '^')
				return true;
			return false;
		}

		bool			isfactelem(char c)
		{
			if ((c >= 'A' && c <= 'Z') || c == '!'
					|| c == '=' || c == '(' || c == ')' || c == '?')
				return true;
			return false;
		}

		bool			goodConclusion(const std::string& rule)
		{
			int			i = 0;
			std::string	cstr;
			
			while (rule[i] != '>' && rule[i])
				i++;
			cstr = &rule[++i];

			if (cstr.find("^") != std::string::npos)
				return false;
			return true;
		}

		bool			goodRule(const std::string& rule)
		{
			int			xors = 0;
			bool		open = false;

			if (rule.empty())
				return false;
			if (!isfactelem(rule[0]))
				return false;
			for (int j = 0; j < (int)rule.length(); j++) {
				if (rule[j] == '(')
					open = true;
				if (rule[j] == ')')
					open = false;
				if (rule[j] == '^' && open == false)
					xors++;
			}
			if (xors > 1) {
				return false;
			}
			for (int i = 0; i < (int)rule.length(); i++) {
				if (isOperator(rule[i]) && !isfactelem(rule[i + 1]))
					return false;
			}
			return true;
		}

	public:

		bool			errorCheck(const std::vector<std::string>& lines)
		{
			int			inifacts = 0;
			int			queries = 0;
			int			errors = 0;
			int			i = 0;

			while (i < (int)lines.size())
			{
				if (lines[i][0] == '=')
					inifacts++;
				if (lines[i][0] == '?')
					queries++;
				if (goodRule(lines[i]) == false) {
					errors++;
					PRINT BOLD RED"Error:"<<RESET BOLD<< "Invalid rule found at Rule: "<< i <<"!" END;
				}
				if (goodConclusion(lines[i]) == false) {
					errors++;
					PRINT BOLD RED"Error: "<<RESET BOLD<<"Invalid conclusion fount at Rule " << i << "!" END;
				}
				i++;
			}
			if (queries > 1) {
				PRINT BOLD YELLOW "Warning: "<<RESET BOLD<<"More than 1 query statement found!" END;
			}
			if (inifacts > 1) {
				PRINT BOLD RED"Error: " <<RESET BOLD<<"More than 1 \'Initial fact\' statement found!" END;
				errors++;
			}

			if (queries == 0) {
				PRINT BOLD RED "Error: "<<RESET BOLD<<"No Queries found!" END;
				errors++;
			}
			if (inifacts == 0) {
				PRINT BOLD RED "Error: "<<RESET BOLD<<"No Initial facts set!" END;
				errors++;
			}

			if (errors > 0)
				return true;
			return false;
		}
};