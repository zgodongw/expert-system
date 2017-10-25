/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 14:10:05 by zgodongw          #+#    #+#             */
/*   Updated: 2017/10/25 09:48:36 by zgodongw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int										main(int argc, char *argv[])
{
	Setup*								s = new Setup();
	InstructionMap*	 					map = new InstructionMap();
	Rules*								rule = new Rules();
	Error*								error = new Error();
	TermUI*								ui = new TermUI();
	std::vector<std::string>			rulearray;

	if (argc < 2) {
		PRINT BOLD RED "No text input: "<<RESET BOLD<<"PROGRAM TERMINATED!" END;
		return (-1);
	}

	map->initMap();
	rulearray = s->start((std::string)argv[1]);

	if (error->errorCheck(rulearray) == false) {
		map->findfacts(rulearray);
    
		rule->Programloop(rulearray);
		
		ui->InitUI(rulearray);
	
		map->findquery(rulearray);
		
		ui->queryLoop();
	}

	delete s;
	delete map;
	delete rule;
	delete error;
	delete ui;

	return (0);
}
