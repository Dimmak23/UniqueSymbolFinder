#include <gtest/gtest.h>
#include "text_searcher.hpp"
#include <sstream>

TEST(sentenceResearcher, simple) {
	
	EXPECT_EQ(Solution::getUniqueSymbolFromSentence(std::string("are we good?")), 'a');
	EXPECT_EQ(Solution::getUniqueSymbolFromSentence(std::string("just keep it simple")), 'j');

}

TEST(sentenceResearcher, repetetives) {
	
	EXPECT_EQ(Solution::getUniqueSymbolFromSentence(std::string("to be or not to be")), 'o');
	EXPECT_EQ(Solution::getUniqueSymbolFromSentence(std::string("let's leave that hat")), '\0');
	EXPECT_EQ(Solution::getUniqueSymbolFromSentence(std::string("need to get an 'apostrophe\nneed to get an\nwhat you will say?")), '\'');

}

TEST(sentenceResearcher, nothingToReturn) {
	
	EXPECT_EQ(Solution::getUniqueSymbolFromSentence(std::string("to be nor not to be")), '\0');

}

TEST(assignment, Stroustrup) {

	EXPECT_EQ(Solution::getUniqueSymbolFromSentence(std::string("C makes it easy for you to shoot yourself in the foot. C++ makes that harder, but when you do, it blows away your whole leg. (с) Bjarne Stroustrup")), 'e');

}
