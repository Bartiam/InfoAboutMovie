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
	Movie Revolver;
	nlohmann::json dict;

	Revolver.name = "Revolver";
	Revolver.yearProduction = 2005;
	Revolver.country = "Great Britain, France";
	Revolver.screenwriter = "Guy Ritchie";
	Revolver.regisseur = "Guy Ritchie";
	Revolver.producer = "Luc Besson";
	Revolver.studio = "Europa corp.";

	Revolver.actors = { {"Actors", {{"Al", "Bill Moody"},
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

	std::ofstream movieFile("..//infoAboutMovie.json");

	if (!movieFile.is_open())
	{
		std::cout << "Error! " << std::endl;
		return 0;
	}
	else
	{
		dict[Revolver.name] = Revolver.actors;
		dict[Revolver.name].emplace("Studio", Revolver.studio);
		dict[Revolver.name].emplace("Producer", Revolver.producer);
		dict[Revolver.name].emplace("Release", Revolver.yearProduction);
		dict[Revolver.name].emplace("Country", Revolver.country);
		dict[Revolver.name].emplace("Screenwriter", Revolver.screenwriter);
		dict[Revolver.name].emplace("Regisseur", Revolver.regisseur);

		movieFile << dict;

		movieFile.close();
	}

	return 0;
}