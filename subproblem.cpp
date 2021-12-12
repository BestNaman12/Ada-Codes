#include <iostream>
#include <string.h>
using namespace std;
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}
bool Break_word(string str)
{
    int size = str.size();
    if (size == 0)   return true;
    bool wb[size+1];
    memset(wb, 0, sizeof(wb)); 
 
    for (int i=1; i<=size; i++)
    {
        if (wb[i] == false && dictionaryContains( str.substr(0, i) ))
            wb[i] = true;
        if (wb[i] == true)
        {
            if (i == size)
                return true;
 
            for (int j = i+1; j <= size; j++)
            {
                if (wb[j] == false && dictionaryContains( str.substr(i, j-i) ))
                    wb[j] = true;
                if (j == size && wb[j] == true)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    Break_word("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    Break_word("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    Break_word("")? cout <<"Yes\n": cout << "No\n";
    Break_word("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    Break_word("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    Break_word("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}