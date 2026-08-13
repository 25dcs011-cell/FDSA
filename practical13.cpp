#include<iostream>
#include<string>
using namespace std;

int main()
{
    string sentence,word="",longestword="";
    cout<<"enter the sentence:";
    getline(cin,sentence);
    sentence += " ";
    for (int i = 0; i < sentence.length(); i++)
    {
        if(sentence[i]!=' ')
        {
            word += sentence[i];
        }
        else
        {
            if(word.length()>longestword.length())
            {
                longestword = word;
            }
            word = "";

        }
    }
    cout<<"Longest word: "<<longestword<<endl;
    cout<<"length: "<<longestword.length()<<endl;
}