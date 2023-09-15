#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "nlohmann/json.hpp"

struct Movie
{
	short yearProduction;
	std::string name;
	std::string country;
	std::string screenwriter;
	std::string regisseur;
	std::string producer;
	std::string studio;
	std::map <std::string, std::map<std::string, std::string>> actors;
};

int main()
{
	Movie theGentlemen;
	nlohmann::json dict;

	theGentlemen.name = "Revolver";
	theGentlemen.yearProduction = 2005;
	theGentlemen.country = "Great Britain, France";
	theGentlemen.screenwriter = "Guy Ritchie";
	theGentlemen.regisseur = "Guy Ritchie";
	theGentlemen.producer = "Luc Besson";
	theGentlemen.studio = "Europa corp.";

	theGentlemen.actors = { {"Actors", {{"Al", "Bill Moody"},
										{"Avi", "Andre Benjamin"},
										{"Benny", "Vincent Riotta"},
										{"Billy", "Andrew Howard"},
										{"Doreen", "Anjela Lauren Smith"},
										{"Dorothy Macha", "Ray Liotta"},
										{"Eddie A", "Ian Puleston-Davies"},
										{"Francesca Annis", "Lily Walker"},
										{"French Paul", "Terrence Maynard"},
										{"Ivan", "Faruk Pruti"},
										{"Jake Green", "Jason Statham"},
										{"Joe", "Stephen Walters"},
										{"Lord John", "Tom Wu"},
										{"Rachel", "Elana Binysh"},
										{"Sorter", "Mark Strong"},
										{"Teddy", "Shend"},
										{"Zach", "Vincent Pastore"}}} };

	std::ofstream movieFile("..//infoAboutMovie.json", std::ios::app);

	if (!movieFile.is_open())
	{
		std::cout << "Error! " << std::endl;
		return 0;
	}
	else
	{
		dict[theGentlemen.name] = theGentlemen.actors;
		dict[theGentlemen.name].emplace("Studio", theGentlemen.studio);
		dict[theGentlemen.name].emplace("Producer", theGentlemen.producer);
		dict[theGentlemen.name].emplace("Release", theGentlemen.yearProduction);
		dict[theGentlemen.name].emplace("Country", theGentlemen.country);
		dict[theGentlemen.name].emplace("Screenwriter", theGentlemen.screenwriter);
		dict[theGentlemen.name].emplace("Regisseur", theGentlemen.regisseur);

		movieFile << dict;

		movieFile.close();
	}

	return 0;
}