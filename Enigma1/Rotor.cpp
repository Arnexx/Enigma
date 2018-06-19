#include "Rotor.h"



Rotor::Rotor()
{
	rotor.resize(26);
	rotorShifts.resize(26);
	position = 0;
}


int Rotor::step()
{
	position = (position + 1) % 26;
	return position;
}

int Rotor::goForward(int value)
{
	return (value + rotorShifts[(value + position) % 26]) % 26;
}

int Rotor::goBackward(int value)
{
	for (int i = 0; i < 26; i++)
	{
		if ((i + rotorShifts[(i + position) % 26 ]) % 26 == value)
			return i;
	}
	return 0;
}

void Rotor::setPosition(int pos)
{
	position = pos % 26;
}

void Rotor::setSequense(string seq)
{
	for (int i = 0; i < 26; i++)
	{
		rotor[i] = int(seq[i]) - 65;
		rotorShifts[i] = (rotor[i] - i + 26) % 26;
	}
}

int Rotor::getPosition()
{
	return position;
}

int Rotor::getNotchPosition()
{
	return notchPosition;
}

void Rotor::setNotchPosition(int value)
{
	notchPosition = value % 26;
}

Rotor::~Rotor()
{
}
