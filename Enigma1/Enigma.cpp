#include "Enigma.h"



Enigma::Enigma()
{
	leftRotor.setSequense("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
	leftRotor.setNotchPosition(int('Q') - 65);
	leftRotor.setPosition(int('A') - 65);

	middleRotor.setSequense("BDFHJLCPRTXVZNYEIWGAKMUSQO");
	middleRotor.setNotchPosition(int('V') - 65);
	middleRotor.setPosition(int('A') - 65);

	rightRotor.setSequense("ESOVPZJAYQUIRHXLNFTGKDCMWB");
	rightRotor.setNotchPosition(int('J') - 65);
	rightRotor.setPosition(int('A') - 65);
	reflector.setSequense("YRUHQSLDPXNGOKMIEBFZCWVJAT");

}

void Enigma::setPosition(int l, int m, int r)
{
	leftRotor.setPosition(l % 26);
	middleRotor.setPosition(m % 26);
	rightRotor.setPosition(r % 26);
}

int Enigma::encrypt(char value)
{
	int symbol = int(value) - 65;
	step();
	return permutate(symbol);
}

void Enigma::test()
{
	string plainText = "ALLCAPSONTHEINTERNETORINWRITTENELECTRONICDOCUMENTSISOFTENTHERESULTOFAMISTAKEBYOLDERORLESSEXPERIENCEDCOMPUTERUSERSWHOUSECAPSLOCKANDFORGETTHATITISENABLED";
	vector<int> tempText;
	tempText.resize(plainText.length());
	this->setPosition(4,10,10);

	for (int i = 0; i < plainText.length(); i++)
	{
		tempText[i] = this->encrypt(plainText[i]);
		cout << char(tempText[i] + 65);
	}
	cout << endl << endl;
	this->setPosition(4, 10, 10);
	for (int i = 0; i < plainText.length(); i++)
	{
		tempText[i] = this->encrypt(char(tempText[i] + 65));
		cout << char(tempText[i] + 65);
	}
}

void Enigma::step()
{
	rightRotor.step();
	if (((middleRotor.getNotchPosition() + 1) % 26) == rightRotor.getPosition())
	{
		middleRotor.step();

		if (((leftRotor.getNotchPosition() + 1) % 26) == middleRotor.getPosition())
			leftRotor.step();
	}
}

int Enigma::permutate(int symbol)
{
	int temp = 0;

	/*temp = rightRotor.goForward((symbol + rightRotor.getPosition()) % 26);
	temp = middleRotor.goForward((temp + middleRotor.getPosition() - rightRotor.getPosition() + 26) % 26);
	temp = leftRotor.goForward((temp + leftRotor.getPosition() - middleRotor.getPosition() + 26) % 26);

	temp = reflector.goForward((temp - leftRotor.getPosition() + 26) % 26);

	temp = leftRotor.goBackward((temp + leftRotor.getPosition()) % 26);
	temp = middleRotor.goBackward((temp - leftRotor.getPosition() + middleRotor.getPosition() + 26) % 26);
	temp = rightRotor.goBackward((temp - middleRotor.getPosition() + rightRotor.getPosition() + 26) % 26);
	temp = (temp - rightRotor.getPosition() + 26) % 26;*/

	temp = rightRotor.goForward(symbol);
	temp = middleRotor.goForward(temp);
	temp = leftRotor.goForward(temp);

	temp = reflector.goForward(temp);

	temp = leftRotor.goBackward(temp);
	temp = middleRotor.goBackward(temp);
	temp = rightRotor.goBackward(temp);

	return temp;
}

int Enigma::goThroughStecker(int symbol)
{
	return 0;
}




Enigma::~Enigma()
{
}
