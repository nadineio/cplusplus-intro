#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Movie {

public:
	void read() {
		ifstream readFile;

		string movieInFile, movieOutFile;
		string title, rating;
		double runningTime;
		bool color;
		int year;

		movieInFile = "movie.txt";
		movieOutFile = "newmovie.txt";

		readFile.open(movieInFile);

		while (!readFile.eof) {
			getline(readFile, title);
					

		}

		cout << title << endl;




	}


};