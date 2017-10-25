/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TermUI.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:01:14 by zgodongw          #+#    #+#             */
/*   Updated: 2017/10/25 10:05:07 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.hpp"

#pragma once

class TermUI {
	public:
		TermUI() {
			//empty constructor
		}

		std::vector<std::string>				splitspace(const std::string& str)
		{
			int 								i = 0;
			std::vector<std::string> 			strarray;

			while (i < (int)str.length())
			{
				std::string strdup;
				while (str[i])
				{
					if (str[i] != ' ')
						strdup += str[i];
					else
						break ;
					i++;
				}
				if (!strdup.empty())
					strarray.emplace_back(strdup);
				i++;
			}
			return strarray;
		}


		void									printRules(const std::vector<std::string>& rules)
		{
			std::string							line;
			bool								set;
			
			for (int j = 0; j < (int)rules.size(); j++) {
				line = rules[j];
				set = false;
				for (int k = 0; k < (int)line.length(); k++) {
					if (isalpha(line[k]))
						PRINT BOLD MAGENTA << line[k] << RESET;
					else if ((line[k] == '+' || line[k] == '|' || line[k] == '^') && !isalpha(line[k]))
						PRINT YELLOW << " " << line[k] << RESET << " ";
					else if  (line[k] == '>')
						PRINT LBLUE << line[k] << RESET << " ";
					else if (line[k] == '<') {
						PRINT LBLUE << " " << line[k] << RESET;
						set = true;
					}
					else if (line[k] == '=' && set == false)
						PRINT LBLUE << " " << line[k] << RESET;
					else
						PRINT LBLUE << line[k] << RESET;
				}
				PRINT '\n';
			}
		}
		
		std::string								getStates(const std::vector<std::string>& rules)
		{
			for (int i = 0; i < (int)rules.size(); i++)
				if (rules[i][0] == '=' && isalpha(rules[i][1]))
					return &rules[i][1];
			return ("nothing");
		}

	public:
		void									InitUI(const std::vector<std::string>& argv)
		{
			Rules								r;
			std::vector<std::string>			rule;
			std::string							states;

			states = getStates(argv);
			rule = r.getRules(argv);
			PRINT CLEAR;
			PRINT RESET BOLD  "Using " << MAGENTA << states << RESET BOLD " as "<<GREEN "true:" END END;
			PRINT RESET BOLD  "Using Rules: " END;
			printRules(rule);
			PRINT '\n';
			PRINT CYAN BOLD "Conclusion: " END;

		}
		
		void 									queryLoop(void)
		{
			InstructionMap						q;
			std::string							option;
			std::string							query;
			int									errors;
		
			while (1) {
				errors = 0;
				PRINT BOLD BLUE "\nWould you like to query another fact? (y/n) : ";

				std::cin >> option;
			if (option == "y" || option == "yes"
					|| option == "Y" || option == "YES") {
				PRINT "Please Enter Query/ies here : ";
				std::cin >> query;
				for (int i = 0; i < (int)query.length(); i++) {
					if (!isalpha(query[i]) || !(query[i] >= 'A' && query[i] <='Z')) {
						PRINT BOLD RED "Error : "<<RESET BOLD<<"Invalid QUERY" END;
						errors++;
					}
				}
				if (errors == 0) {
					q.getQuery("=" + query);
				}
			}
			else if (option == "n" || option == "N"
					|| option == "no" || option == "NO"){
				PRINT RESET BOLD "PROGRAM TERMINATED" END;
				break ;
			}
			else
				PRINT BOLD RED"Error: "<<RESET BOLD<<"Invalid input" END;
		}

	}
};
