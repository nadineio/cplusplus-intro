// Project 1 - Movies and People
// Nadine Mansour
// Due 2/21/2019

#include "Movie.h"
#include "People.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

vector<Movie>	movies;
vector<Person>	people;

void readPeople();
void readMovies();
void readFiles(); 

void inputMovie();
void inputPerson();
void displayMovies();
void displayPeople();

void writePeople();
void writeMovies();
void writeFiles();

int main() {
	char command;
	
	readFiles();

	cout << "Please enter a command (enter H for help): ";
	cin >> command;

	while (tolower(command) != 'x') {
		switch (tolower(command)) {
			case 'm':
				inputMovie();
				break;
			case 'p':
				inputPerson();
				break;
			case 's':
				displayMovies();
				break;
			case 'd':
				displayPeople();
				break;
			case 'a':
				cout << "Programmer: Nadine Mansour" << endl;
				cout << "Version: 7.1.7" << endl;
				break;
			case 'h':
				cout << "Please enter one of the following commands: " << endl;
				cout << "M: Input a movie and add it to the list of movies." << endl;
				cout << "P: Input a person and add it to the list of people." << endl;
				cout << "S: Show the list of movies input." << endl;
				cout << "D: Display the list of people input." << endl;
				cout << "A: Print an about message that gives the programmer’s name and a version for the program." << endl;
				cout << "H: Print a help message detailing these commands." << endl;
				cout << "X: Exit the program." << endl;
				break;
			case 'x':
				break;

			default:
				cout << command << " is not a valid command." << endl;
				break;
		}
		cout << endl << "Please enter a command (enter H for help): ";
		cin >> command;
	}

	writeFiles();
	
	system("pause");
	return EXIT_SUCCESS;

}

void readMovies() {
	ifstream readFile;
	string	 movieInFileName, temp;

	Movie	newMovie;
	string	title, rating, color, format;
	double	runningTime;
	int		year;

	movieInFileName = "movie.txt";
	readFile.open(movieInFileName);

	if (readFile.good()) {
		while (!readFile.eof()) {
			getline(readFile, title);
			readFile >> runningTime;
			getline(readFile, temp);
			getline(readFile, rating);
			getline(readFile, color);
			getline(readFile, format);
			readFile >> year;
			getline(readFile, temp);

			newMovie.setTitle(title);
			newMovie.setRunningTime(runningTime);
			newMovie.setRating(rating);
			newMovie.setColor(color);
			newMovie.setFormat(format);
			newMovie.setYear(year);

			movies.push_back(newMovie);
		}		
	}
	else {
		cout << "Unable to open " << movieInFileName << " to read movies." << endl;
	}
}

void readPeople() {
	ifstream readFile;
	string	 peopleInFileName, temp;

	Person	newPerson;
	string	name, gender, death;
	int		birth;

	peopleInFileName = "people.txt";
	readFile.open(peopleInFileName);

	if (readFile.good()) {
		while (!readFile.eof()) {
			getline(readFile, name);
			readFile >> birth;
			getline(readFile, temp);
			getline(readFile, death);
			getline(readFile, gender);

			newPerson.setName(name);
			newPerson.setBirth(birth);
			newPerson.setDeath(death);
			newPerson.setGender(gender);

			people.push_back(newPerson);
		}
	}
	else {
		cout << "Unable to open " << peopleInFileName << " to read people." << endl;
	}
}

void writeMovies() {
	ofstream writeFile;
	string	 movieOutFileName;

	movieOutFileName = "newmovie.txt";

	writeFile.open(movieOutFileName);
	if (writeFile.good()) {
		for (Movie nextMovie : movies) {
			nextMovie.print(writeFile);
		}
		writeFile.close();
	} 
	else {
		cout << "Unable to open " << movieOutFileName << " to write movies." << endl;
	}
}

void writePeople() {
	ofstream writeFile;
	string	 peopleOutFileName;

	peopleOutFileName = "newpeople.txt";

	writeFile.open(peopleOutFileName);
	if (writeFile.good()) {
		for (Person nextPerson : people) {
			nextPerson.print(writeFile);
		}
		writeFile.close();
	}
	else {
		cout << "Unable to open " << peopleOutFileName << " to write people." << endl;
	}
}

void readFiles() {
	readMovies();
	readPeople();
}

void writeFiles() {
	writeMovies();
	writePeople();
}

void inputMovie() {
	Movie	newMovie;
	string	title, rating, color, format;
	double	runningTime;
	int		year;

	runningTime = 0;

	cout << "Title: ";
	cin >> title;
	newMovie.setTitle(title);

	cout << "Running Time: ";
	cin >> runningTime;
	while (cin.fail() || runningTime < 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid entry. Please re-enter Running Time: ";
		cin >> runningTime;
	}
	newMovie.setRunningTime(runningTime);

	cout << "MPAA Rating: ";
	cin.ignore();
	getline(cin, rating);
	newMovie.setRating(rating);
	
	cout << "Color? (Yes or No) ";
	cin >> color;
	while (color != "Yes" && color != "No") {
		cout << "Invalid entry. Please enter Yes or No for color: ";
		cin >> color;
	}
	newMovie.setColor(color);

	cout << "Format or aspect ratio: ";
	cin.ignore();
	getline(cin, format);
	newMovie.setFormat(format);

	cout << "Year Released: ";
	cin >> year;
	while (cin.fail() || year < 1800) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid entry. Please re-enter Year Released: ";
		cin >> year;
	}
	newMovie.setYear(year);

	movies.push_back(newMovie);
}

void inputPerson() {
	Person	newPerson;
	string	name, gender, death;
	int		birth;

	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	newPerson.setName(name);

	cout << "Year Born: ";
	cin >> birth;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid entry. Please re-enter Year Born: ";
		cin >> birth;
	}
	newPerson.setBirth(birth);

	cout << "Year Died: ";
	cin.ignore();
	getline(cin, death);
	newPerson.setDeath(death);
	
	cout << "Gender: ";
	cin >> gender;
	newPerson.setGender(gender);

	people.push_back(newPerson);
}

void displayMovies() {
	cout << "List of movies: " << endl;
	for (Movie nextMovie : movies) {
		nextMovie.print(cout);
	}

}

void displayPeople() {
	cout << "List of people: " << endl;
	for (Person nextPerson : people) {
		nextPerson.print(cout);
	}

}