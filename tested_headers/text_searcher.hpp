#ifndef TEXT_SEARCHER_HPP
#define TEXT_SEARCHER_HPP

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Solution
{
	public:
		static char getUniqueSymbolFromWord(std::string word);
		static char getUniqueSymbolFromSentence(const std::string& sentence);
};

// 1. Pass one word at a time to the function
inline char Solution::getUniqueSymbolFromWord(std::string word)
{
	// 2. Get pointer to the star of the word:
	std::string::iterator searchPos = word.begin();
	
	if(*(searchPos + 1) == '\0') return *searchPos; // It's only the one symbol in the word
	
	// 3. Similar get pointer to the very next posistion:
	std::string::iterator comparePos = word.begin() + 1;

	// 4. Where we keep output symbol?
	char symbol = *searchPos;

	// 5. We might what to return to the next serch position while searching:
	std::string::iterator searchNextPos = word.begin() + 1;

	// 6. We mark first search position as should be erased one
	// (so if have erased at least one erased the first one too)
	bool haveErased {false};

	// If next search position are symbol that we already serched - we don't want to return there
	while(*searchPos == *searchNextPos)
	{
		word.erase(searchNextPos);
		haveErased = true;
		if (*searchNextPos == '\0') return '\0';
	}
	// Move from search postition - it has been compromised
	if (haveErased)
	{
		searchPos++;
		searchNextPos = searchPos + 1;
		symbol = *searchPos;
	}

	// 6. And let's start to compare right with the next to the searchPos cell:
	comparePos = searchPos + 1; // should be the same as:
	// comparePos = serchNextPos;
	
	// 7. Noew we are looking at next cell, and move search position further if have to
	while(*searchNextPos != '\0')
	{
		// Seems that next cell are the same, so this not the symbol that we are looking for
		if(*searchPos == *comparePos)
		{
			word.erase(comparePos);
			searchPos = searchNextPos;
			searchNextPos++;
			symbol = *searchPos;
			while(*searchPos == *searchNextPos)
			{
				searchPos = searchNextPos;
				searchNextPos++;
				symbol = *searchNextPos; // This mean that search position can't be original
				if(*searchNextPos == '\0') return '\0'; // there is no original symbols left
			}
			comparePos = searchPos + 1;
		}
		else
		{
			comparePos++; // Simply look at the next cell
			// symbol = *searchPos;
		}
		// If we looked everywhere
		if(*comparePos == ('\0'))
		{
			return symbol; // there is no original symbols left
		}
	}
	
	// Here we return *searchPos in case we didn't step into the loop
	return symbol;
}

inline char Solution::getUniqueSymbolFromSentence(const std::string& sentence)
{
	// 1. Split sentence
	std::vector<std::string> words;

	// 2. Single word: here to emplace words from sentence, later to get a final result
	std::stringstream singleWord;

	// Loop and split
	for(int index{}; index < sentence.size()+1; index++)
	{
		if((index == sentence.size()) || (sentence.at(index) == ' ') || (sentence.at(index) == '\n') )
		{
			words.emplace_back(singleWord.str());
			singleWord.str("");
			continue;
		}
		else
		{
			singleWord << sentence.at(index);
		}
	}

	// 3. Send vector of words and get final word instead
	for(auto& word: words)
	{
		singleWord << getUniqueSymbolFromWord(word);
	}

	// 4. Here we can return result via calling get unique from word:
	return getUniqueSymbolFromWord(singleWord.str()); 
}

#endif //TEXT_SEARCHER_HPP