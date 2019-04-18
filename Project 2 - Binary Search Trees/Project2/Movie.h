#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Movie {
protected:
	string	title, rating, color, format;
	double	runningTime;
	int		year;

public:
	//Constructors
	Movie(string title, double runningTime, string rating, string color, string format, int year);
	Movie();

	//Access Methods
	string getTitle();
	string getKey();
	double getRunningTime();
	string getRating();
	string getColor();
	string getformat();
	int getYear();

	//Mutators
	void setTitle(string title);
	void setRunningTime(double runningTime);
	void setRating(string rating);
	void setColor(string color);
	void setFormat(string format);
	void setYear(int year);

	//Print
	void print(ostream& ostr);
};

//Constructors
Movie::Movie(string title, double runningTime, string rating, string color, string format, int year) {
	this->title = title;
	this->runningTime = runningTime;
	this->rating = rating;
	this->color = color;
	this->format = format;
	this->year = year;
}

Movie::Movie() {
	title = "No Title";
	runningTime = 0;
	rating = "";
	color = "No";
	format = "";
	year = 0;
}

//Access Methods
string Movie::getTitle() {
	return title;
}

string Movie::getKey() {
	return getTitle();
}

double Movie::getRunningTime() {
	return runningTime;
}

string Movie::getRating() {
	return rating;
}

string Movie::getColor() {
	return color;
}

string Movie::getformat() {
	return format;
}

int Movie::getYear() {
	return year;
}

//Mutators
void Movie::setTitle(string title) {
	this->title = title;
}

void Movie::setRunningTime(double runningTime) {
	this->runningTime = runningTime;
}

void Movie::setRating(string rating) {
	this->rating = rating;
}

void Movie::setColor(string color) {
	this->color = color;
}

void Movie::setFormat(string format) {
	this->format = format;
}

void Movie::setYear(int year) {
	this->year = year;
}

//Print
void Movie::print(ostream &ostr) {
	ostr << title << endl << runningTime << endl << rating << endl << color << endl << format << endl << year << endl;
}
