#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

/*
    The below algorithm implements a version of the Galois LFSR.
    When the system is clocked with the feedback value, bits that are not taps are shifted one position to the right unchanged. 
    The taps, are XORed with the output bit before they are stored in the next position.

    In the grand scheme of data and effeciency, an EC algoirthm could be considered and/or implemented
*/

unsigned char *Crypt(unsigned char *data, int dataLength, unsigned int initialValue)
{
    unsigned int a = 0x87654321; //Feedback Value
    unsigned int b = initialValue;
    int leastSigBit, count;

    for (int i = 0; i < dataLength; i++)
    {
        //count = 0;
        data[i] = (data[i]) ^ ((b & 0x000000FF)); //Extracting the lowest byte
        //count++;
        leastSigBit = b & 1; //Make leastSigBit the output bit
        b >>= 1;             //Shift Register
        if (leastSigBit)
            b ^= a; //If leastSigBit is 1, then XOR feedback product of the 32-bit shift register

        //On the 8th step it will stop loop and extract lowest byte
    }

    return data;
}

int main()
{
    unsigned int initialVal = 0x12345678;
    unsigned char *data;
    int dataLength = 5;
    int i;

    data[0] = 'a';
    data[1] = 'p';
    data[2] = 'p';
    data[3] = 'l';
    data[4] = 'e';

    cout << endl;
    cout << "Original Message: "; //Print Original Data
    cout << data << endl;

    cout << "Encrypted Message: ";
    Crypt(data, dataLength, initialVal);
    for (int i = 0; i < dataLength; i++)
        cout << "\\x" << hex << (int)data[i]; //Print Encrypted Data
    cout << endl;

    cout << "Recovered Message: ";
    Crypt(data, dataLength, initialVal);
    cout << data << endl; //Printing Recovered Message

    cout << endl;

    return 0;
}
