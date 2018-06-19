#pragma once
#include "Rotor.h"
#include <iostream>

class Enigma
{
private:
	Rotor leftRotor;
	Rotor middleRotor;
	Rotor rightRotor;
	Rotor reflector;
	vector<int> stecker;

	void step();
	int permutate(int symbol);
	int goThroughStecker(int symbol);

public:
	Enigma();
	void setPosition(int l, int m, int r);
	int encrypt(char value);
	void test();

	~Enigma();
};

