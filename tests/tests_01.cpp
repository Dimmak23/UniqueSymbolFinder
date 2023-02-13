#include <gtest/gtest.h>
#include "text_searcher.hpp"
#include <sstream>

TEST(wordResearcher, repetetives) {
	
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("aaaaaaaaa)")), ')');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("uuuuuuuuuuuuuu")), '\0');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("arrrrrrrrrrrrrrrrrrrrrrrrrr")), 'a');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("ggggggggggggggggggggggggggg")), '\0');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,")), '\0');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("fgggggggkkkkkkkkksssssssss")), 'f');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("ntga'ntgawyws")), '\'');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("tbnntb")), '\0');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("llhh")), '\0');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("ll")), '\0');
	
}

TEST(wordResearcher, singleChar) {
	
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("b")), 'b');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("y")), 'y');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("e")), 'e');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string(".")), '.');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string(")")), ')');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("3")), '3');

}

TEST(wordResearcher, simpleWords) {
	
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("are")), 'a');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("Asja")), 'A');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("Dmytro")), 'D');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("Table")), 'T');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("using")), 'u');
	EXPECT_EQ(Solution::getUniqueSymbolFromWord(std::string("const")), 'c');
	
}
