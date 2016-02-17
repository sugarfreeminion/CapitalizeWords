/*
 * Solves Code Eval Capitalize Words challenge
 * Program capitalizes first letter of each word
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// ascii representation for start and end of alphabet in lower and upper case
const int A = 65;
const int Z = 90;
const int a = 97;
const int z = 122;

/*
 * Checks if the character sent is a letter in the alphabet
 */
bool IsAlpha(char val)
{
    bool isAlpha = false;

    if((val >= A && val <= Z)
       || (val >= a && val <= z))
    {
        isAlpha = true;
    }
    else
    {
        isAlpha = false;
    }

    return isAlpha;
}

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            stringstream lineStream(line);
            vector<string> words;
            string temp;

            //cout << "Line read in: " << line << endl;

            while(getline(lineStream,temp,' '))
            {
                if(IsAlpha(temp[0]))
                {
                    if(temp[0] >= a && temp[0] <= z)
                    {
                        temp[0] = temp[0] - 32;
                    }
                }

                words.push_back(temp);
            }

            //cout << "Number of words in line: " << words.size() << endl;

            unsigned int index = 0;

            for(vector<string>::const_iterator itr=words.begin();
                itr != words.end();
                ++itr)
            {
                cout << *itr;

                if(index < words.size() - 1)
                {
                    cout << " ";
                }
                else
                {
                    cout << endl;
                }

                ++index;
            }
        }

        inputFile.close();
    }
    return 0;
}
