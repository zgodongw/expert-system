/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:10:05 by zgodongw          #+#    #+#             */
/*   Updated: 2018/01/23 17:39:57 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int										main(int argc, char *argv[])
{
	Setup								s;
	InstructionMap	 					map;
	Rules								rule;
	Error								error;
	TermUI								ui;
	std::vector<std::string>			rulearray;
	std::vector<std::string>			array2;

	PRINT CLEAR;
	if (argc < 2) {
		PRINT BOLD RED "No text input: "<<RESET BOLD<<"Please Insert Rules:" END;
		rulearray = s.start(ui.interact(), false);
		array2 = s.start("temp.txt", true);
		remove("temp.txt");
	}
	else {
		rulearray = s.start((std::string)argv[1], false);
		array2 = s.start((std::string)argv[1], true);
	}

	map.initMap();
	if (!rulearray.empty()) {
		if (error.errorCheck(rulearray) == false) {
			map.findfacts(rulearray);
    
			rule.Programloop(rulearray);
		
			ui.InitUI(array2);
	
			map.findquery(rulearray);
		
			ui.queryLoop();
		}
	}

	return (0);
}
