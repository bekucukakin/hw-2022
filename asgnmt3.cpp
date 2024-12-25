//*****************************************************************
//******       STUDENT NAME: BEKÝRCAN KÜÇÜKAKIN              ******
//******       STUDENT NUMBER: B201202046                    ******
//******       ASSIGNMENT : #3                               ******
//******       -On my honor,I have never neither given       ******
//******        nor received aid on this assignment-         ******
//*****************************************************************
#include<iostream>
#include<ctime>
#include<windows.h>

using namespace std;
const int MAX = 12;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
#define color_white 15
#define color_dark_red 4

// function prototypes
bool checkAlphabet(char[], char[]);
bool checkMatrix(char[MAX][MAX], char[]);

int main()
{
	srand(time(NULL)); 
	FlushConsoleInputBuffer(hConsole); 
	char RandomMatrix[MAX][MAX]; 
	char Alphabet[MAX];
	
	// to generate alphabet randomly and  if there are same letters in Alphabet array,change them
	for (int i = 0; i < MAX; i++)
	{
		Alphabet[i] = (rand() % 26 + 65);
		for (int j = 0; j < i; j++) 
		{
			if (Alphabet[j] == Alphabet[i]) //  to check whether same letters in Alphabet array
			{
				i--;
				break;
			}
		}
	}
	// print the Alphabet array on the screen
	cout << "Generated Alphabet is:  ";
	for (int i = 0; i < MAX; i++) 
	{
		cout << Alphabet[i] << "-";
	}
	cout << endl;
	cout << "******************************" << endl;
	//generate the RandomMatrix with randomly chosen letters in Alphabet array
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			RandomMatrix[i][j] = Alphabet[rand() % MAX];
		}

	// print the RandomMatrix on the screen
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << RandomMatrix[i][j];
		}
		cout << endl;
	}
	cout << "******************************" << endl;
	
	char enteredWord[MAX];
	bool testAlphabet;
	// forcing the user to enter the correct letters using the bool function
	do
	{
		testAlphabet = checkAlphabet(Alphabet, enteredWord); 
		if (!checkAlphabet(Alphabet, enteredWord))  // to force user to enter letters from the Alphabet array
		{
			cout << "Enter a word of using the alphabet:";
			cin >> enteredWord;
		}
	} while (testAlphabet == false);
	
	checkMatrix(RandomMatrix, enteredWord);  // bool function call 
}
// check whether the entered letters are in the alphabet 
// this function checks the matrix letter by lette
bool checkAlphabet(char Alphabet[],char letter[])
{
	int lenWord = strlen(letter); //to find the length of the entered word
	int control = 0; //to check the loops and choose the correct letters

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < lenWord; j++)
		{
			if (Alphabet[i] == letter[j]) 
				control++;
		}
	}
	if (control == lenWord) 
		return true; 
	else
		return false;
}
// check whether there is a word entered in the matrix 
bool checkMatrix(char RandomMatrix[MAX][MAX], char enteredWord[])
{
	int control = 0; //to check the loops and choose the correct words
	int lenWord = strlen(enteredWord); //to find the length of the entered word
	bool checkLine = false;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (!checkLine) 
			{
				for (int k = 0; k < lenWord; k++)
				{
					if (enteredWord[k] == RandomMatrix[i][j + k]) // check all elements in RandomMatrix
					{
						if (j + k < MAX)  // because our matrix [MAX][MAX]
							control++; 
					}
				}
				if (control == lenWord) // to save the memory the words to paint
					checkLine = true;
				else
					control = 0;
			}
			if (checkLine)
			{
				SetConsoleTextAttribute(hConsole, 4); // paint the words red which entered from the keyboard
				cout << RandomMatrix[i][j];
				control--;       
			    if (control == 0)  // when its zero, letters will not be painted
					checkLine = false;
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 15); // paint the matrix white without entered words
				cout << RandomMatrix[i][j];
			}
		}
		cout << endl;
	}
	return true;  
}

