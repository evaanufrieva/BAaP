#include <gtest/gtest.h>
#include "../include/even_groups.h"
#include "../include/substr.h"
#include "../include/inplace.h"
#include <string>


bool compareGroups(char** actual, int actualCount, const char* expected[], int expectedCount) {
    if (actualCount != expectedCount) return false;
    for (int i = 0; i < actualCount; ++i) {
        int j = 0;
        while (actual[i][j] != '\0' && expected[i][j] != '\0') {
            if (actual[i][j] != expected[i][j])
                return false;
            ++j;
        }
        if (actual[i][j] != expected[i][j])
            return false;
    }
    return true;
}

// --- тесты ---
TEST(BinaryGroupsTest, BasicCase) {
    BinaryGroups bg;
    bg.setInput("111000110");
    bg.findEvenGroups();

    const char* expected[] = {"11",};
    EXPECT_TRUE(compareGroups(bg.groups, bg.count, expected, 1));
}

TEST(BinaryGroupsTest, AllEven) {
    BinaryGroups bg;
    bg.setInput("0011");
    bg.findEvenGroups();

    const char* expected[] = {"00", "11"};
    EXPECT_TRUE(compareGroups(bg.groups, bg.count, expected, 2));
}

TEST(BinaryGroupsTest, NoEvenGroups) {
    BinaryGroups bg;
    bg.setInput("10101");
    bg.findEvenGroups();

    EXPECT_EQ(bg.count, 0);
}

TEST(BinaryGroupsTest, EmptyInput) {
    BinaryGroups bg;
    bg.setInput(""); // пустая строка
    bg.findEvenGroups();

    EXPECT_EQ(bg.count, 0);
}

TEST(BinaryGroupsTest, OneChar) {
    BinaryGroups bg;
    bg.setInput("1");
    bg.findEvenGroups();

    EXPECT_EQ(bg.count, 0);
}

TEST(BinaryGroupsTest, AllZerosEven) {
    BinaryGroups bg;
    bg.setInput("0000");
    bg.findEvenGroups();

    const char* expected[] = {"0000"};
    EXPECT_TRUE(compareGroups(bg.groups, bg.count, expected, 1));
}

TEST(BinaryGroupsTest, Alternating) {
    BinaryGroups bg;
    bg.setInput("01010100");
    bg.findEvenGroups();

    const char* expected[] = {"00"};
    EXPECT_TRUE(compareGroups(bg.groups, bg.count, expected, 1));
}

TEST(BinaryGroupsTest, LongInput) {
    BinaryGroups bg;
    std::string longStr(80, '1'); // строка из 80 единиц
    bg.setInput(longStr.c_str());
    bg.findEvenGroups();

    const char* expected[] = {longStr.c_str()};
    EXPECT_TRUE(compareGroups(bg.groups, bg.count, expected, 1));
}

TEST(BinaryGroupsTest, MixedGroups) {
    BinaryGroups bg;
    bg.setInput("11000111100");
    bg.findEvenGroups();

    const char* expected[] = {"11", "1111", "00"};
    EXPECT_TRUE(compareGroups(bg.groups, bg.count, expected, 3));
}

TEST(BinaryGroupsTest, InvalidCharIgnored) {
    BinaryGroups bg;
    bool ok = bg.setInput("110a00"); 
    EXPECT_FALSE(ok);       
    EXPECT_EQ(bg.count, 0);        
}

TEST(SubStrTest, InsertAfterLetter) {
    SubStr s;

    const char* text = "hello world";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = 'w';
    const char* sub = "eva";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "hello wevaorld");

    
}

// 2. Вставка после пробела
TEST(SubStrTest, InsertAfterSpace) {
    SubStr s;

    const char* text = "hello world";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = ' ';
    const char* sub = "X";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "hello Xworld");

    
}

// 3. Вставка в пустую подстроку (ничего не вставляется)
TEST(SubStrTest, EmptySubstring) {
    SubStr s;

    const char* text = "abc";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = 'b';
    const char* sub = "";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "abc");

    
}

// 4. Вставка подстроки в пустой текст (ничего не вставляется)
TEST(SubStrTest, EmptyText) {
    SubStr s;

    const char* text = "";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = 'a';
    const char* sub = "xyz";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "");

    
}

// 5. Символ для вставки — отсутствует (краевой случай)
TEST(SubStrTest, SymbolNotFound) {
    SubStr s;

    const char* text = "abcdef";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = 'x';
    const char* sub = "123";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "abcdef"); // строка не меняется

    
}

// 6. Символ для вставки — первый символ
TEST(SubStrTest, InsertAfterFirst) {
    SubStr s;

    const char* text = "abcdef";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = 'a';
    const char* sub = "123";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "a123bcdef");

    
}

// 7. Символ для вставки — последний символ (краевой случай)
TEST(SubStrTest, InsertAfterLast) {
    SubStr s;

    const char* text = "abcdef";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = 'f';
    const char* sub = "XYZ";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "abcdefXYZ");

    
}

// 8. Вставка подстроки равной длины текста
TEST(SubStrTest, SubstringSameLength) {
    SubStr s;

    const char* text = "abc";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = 'b';
    const char* sub = "123";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "ab123c");

    
}

TEST(SubStrTest, MultipleCharactersSubstring) {
    SubStr s;

    const char* text = "12345";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = '3';
    const char* sub = "XYZ";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "123XYZ45");

   
}

TEST(SubStrTest, UTF8Simulation) {
    SubStr s;

    const char* text = "privet";
    s.input = new char[strlen(text)+1]; strcpy(s.input, text); s.textLength = strlen(text);
    s.symbol = 'i';
    const char* sub = "XYZ";
    s.substr = new char[strlen(sub)+1]; strcpy(s.substr, sub); s.substringLength = strlen(sub);

    s.placeSubStr();
    ASSERT_STREQ(s.input, "priXYZvet");

}
// 1. Обычный случай
TEST(InPlaceTest, NormalCase) {
    InPlace ip;
    const char* text = "hello eva anufr 2006";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    for (size_t i = 0; i < ip.lenArray; i++) ip.input[i] = text[i];
    ip.input[ip.lenArray] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "2006 anufr eva hello");
}

// 2. Два слова
TEST(InPlaceTest, TwoWords) {
    InPlace ip;
    const char* text = "hello world";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    for (size_t i = 0; i < ip.lenArray; i++) ip.input[i] = text[i];
    ip.input[ip.lenArray] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "world hello");
}

// 3. Один символ
TEST(InPlaceTest, SingleChar) {
    InPlace ip;
    const char* text = "a";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    ip.input[0] = 'a';
    ip.input[1] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "a");
}

// 4. Одно слово (краевой случай)
TEST(InPlaceTest, SingleWord) {
    InPlace ip;
    const char* text = "word";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    for (size_t i = 0; i < ip.lenArray; i++) ip.input[i] = text[i];
    ip.input[ip.lenArray] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "word");
}

// 5. Пустая строка (краевой случай)
TEST(InPlaceTest, EmptyString) {
    InPlace ip;
    ip.lenArray = 0;
    ip.input = new char[1];
    ip.input[0] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "");
}

// 6. Строка с пробелами в начале и конце
TEST(InPlaceTest, LeadingTrailingSpaces) {
    InPlace ip;
    const char* text = "  hello world  ";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    for (size_t i = 0; i < ip.lenArray; i++) ip.input[i] = text[i];
    ip.input[ip.lenArray] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "  world hello  ");
}

// 7. Несколько пробелов между словами
TEST(InPlaceTest, MultipleSpaces) {
    InPlace ip;
    const char* text = "hello   eva  anufr";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    for (size_t i = 0; i < ip.lenArray; i++) ip.input[i] = text[i];
    ip.input[ip.lenArray] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "anufr  eva   hello");
}

// 8. Цифры и буквы
TEST(InPlaceTest, LettersAndNumbers) {
    InPlace ip;
    const char* text = "abc 123 def 456";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    for (size_t i = 0; i < ip.lenArray; i++) ip.input[i] = text[i];
    ip.input[ip.lenArray] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "456 def 123 abc");
}

// 9. Специальные символы
TEST(InPlaceTest, SpecialChars) {
    InPlace ip;
    const char* text = "! @ # $ % ^";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    for (size_t i = 0; i < ip.lenArray; i++) ip.input[i] = text[i];
    ip.input[ip.lenArray] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "^ % $ # @ !");
}

// 10. Длинная строка
TEST(InPlaceTest, LongString) {
    InPlace ip;
    const char* text = "one two three four five six seven eight nine ten";
    ip.lenArray = 0;
    while (text[ip.lenArray] != '\0') ip.lenArray++;
    ip.input = new char[ip.lenArray + 1];
    for (size_t i = 0; i < ip.lenArray; i++) ip.input[i] = text[i];
    ip.input[ip.lenArray] = '\0';

    ip.inplaceWords();
    std::string result;
    for (size_t i = 0; i < ip.lenArray; i++) result += ip.input[i];
    EXPECT_EQ(result, "ten nine eight seven six five four three two one");
}