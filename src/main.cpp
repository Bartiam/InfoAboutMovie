#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "nlohmann/json.hpp"

struct Movie
{
	short yearProduction;
	std::string country;
	std::string screenwriter;
	std::string regisseur;
	std::string producer;
	std::string studio;
	std::map<std::string, std::string> actors;
};

int main()
{
	Movie theGentlemen;
	nlohmann::json dict;

	theGentlemen.yearProduction = 2019;
	theGentlemen.country = "Great Britain";
	theGentlemen.screenwriter = "Guy Ritchie";
	theGentlemen.regisseur = "Guy Ritchie";
	theGentlemen.producer = "Ivan Atkinson";
	theGentlemen.studio = "Miramax Films";

	theGentlemen.actors = { {"Michael \"Mickey\" Pearson", "Matthew McConaughey"},
							{"Raymond Smith", "Charlie Hunnam"},
							{"Dry Eye", "Henry Golding"},
							{"Rosalind", "Michelle Dockery"},
							{"Coach", "Colin Farrell"},
							{"Fletcher", "Hugh Grant"},
							{"Matthew Berger", "Jeremy Strong"},
							{"Big Dave", "Eddie Marsan"},
							{"Phuc", "Jason Wong"},
							{"Jackie", "Line Reni"},
							{"Chris Ivangelou", "Primetime"},
							{"Evgenia Kuzmina", "Misha"},
							{"Tom By", "Lord George"},
							{"Bugzy Malone", "Ernie"},
							{"Eliot Sumner", "Laura Presfield"} };

	std::ofstream movieFile("..//infoAboutMovie.json");

	if (!movieFile.is_open())
	{
		std::cout << "Error! " << std::endl;
		return 0;
	}
	else
	{
		dict["studio"] = theGentlemen.studio;
		dict["release"] = theGentlemen.yearProduction;
		dict["actors"] = theGentlemen.actors;
		dict["country"] = theGentlemen.country;
		dict["screenwriters"] = theGentlemen.screenwriter;
		dict["regisseur"] = theGentlemen.regisseur;
		dict["producers"] = theGentlemen.producer;

		movieFile << dict;

		movieFile.close();
	}

	return 0;
}