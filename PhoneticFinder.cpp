/**
*AUTHORS: <Itay Simhayev 205666407>
 * Date: 2020-03
 */

#include "PhoneticFinder.hpp"
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

namespace phonetic 
{
	std::string find(std::string text, std::string word) 
	{
	    string saveWord=word.substr(0,word.length());
	    transform(word.begin(), word.end(), word.begin(), ::tolower); //change the string word to lower character
	    word=code::stringCode(word);
	    int length=text.length();
	    int index=0;
	    string copy=text.substr(0,length); //copy the string (the changes that we do will be on the copy string and not on the original)
	    transform(copy.begin(), copy.end(), copy.begin(), ::tolower); //change the string copy to lower character
	    while(index<length)
	    {
	        int start=index;
	        int end=0;
	        while(index<length&&copy.at(index)!=32)
	        {
	            index++;end++;
	        }
	        string sub=copy.substr(start,end);
	        sub=code::stringCode(sub);
	        if(sub.compare(word)==0)
	            return text.substr(start,end);
	        index++;
	    }
	    throw runtime_error("Did not find the word '"+saveWord+"' in the text");
	    return NULL;
	}
}
namespace code 
{
	std::string stringCode(std::string word) 
	{
	    char arrayCode [] ={'a','b','c','d','e','b','g','h','i','g','c','l','m','n','o','b','c','r','s','d','o','v','v','x','i','s'};
	    string newWord="";
        for(int i=0;i<word.length();i++)
        {
            int place=word.at(i)-97;
            char c=arrayCode[place];
            newWord=newWord+c;
        }
        return newWord;
	}
}
