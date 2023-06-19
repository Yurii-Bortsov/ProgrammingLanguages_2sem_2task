#include <gtest/gtest.h>
#include "list.h"

TEST(list, pushBack)
{
    // arrange
    miit::List list;
    std::string strAnswer = "1 2 3 ";
    std::string strList;

    // act
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    strList = list.toString();

    // assert
    ASSERT_EQ(strAnswer, strList);
}

TEST(list, pushAhead)
{
    // arrange
    miit::List list;
    std::string strAnswer = "1 2 3 ";
    std::string strList;
    
    // act
    list.PushAhead(3);
    list.PushAhead(2);
    list.PushAhead(1);
    strList = list.toString();

    // assert
    ASSERT_EQ(strAnswer, strList);
}

TEST(list, deleteBack)
{
    // arrange
    miit::List list;
    std::string strAnswer = "1 ";
    std::string strList;    

    // act
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.DeleteBack();
    list.DeleteBack();
    strList = list.toString();

    // assert
    ASSERT_EQ(strAnswer, strList);
}

TEST(list, deleteAhead)
{
    // arrange
    miit::List list;
    std::string strAnswer = "3 ";
    std::string strList;

    // act
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.DeleteAhead();
    list.DeleteAhead(); 
    strList = list.toString();

    // assert
    ASSERT_EQ(strAnswer, strList);
}

TEST(list, isEmpty)
{
    // arrange
    miit::List list;

    // act
    bool act = list.IsEmpty();

    // assert
    ASSERT_EQ(true, act);
}

TEST(list, copyConstructor)
{
    // arrange
    miit::List originalList;
    originalList.PushBack(1);
    originalList.PushBack(2);
    originalList.PushBack(3);

    // act
    miit::List copiedList(originalList);
    copiedList.PushBack(55);

    // assert
    ASSERT_NE(originalList.toString(), copiedList.toString());
}

TEST(list, copyOperator)
{
    // arrange
    miit::List originalList;
    originalList.PushBack(1);
    originalList.PushBack(2);
    originalList.PushBack(3);

    miit::List copiedList;
    copiedList.PushBack(4);
    copiedList.PushBack(5);

    // act
    copiedList = originalList;
    copiedList.PushBack(55);

    // assert
    ASSERT_NE(originalList.toString(), copiedList.toString());
}

TEST(list, moveConstructor)
{
    // arrange
    miit::List originalList;
    originalList.PushBack(1);
    originalList.PushBack(2);
    originalList.PushBack(3);

    // act
    miit::List movedList(std::move(originalList));

    // assert
    ASSERT_EQ("1 2 3 ", movedList.toString());
}

TEST(list, moveOperator)
{
    // arrange
    miit::List originalList;
    originalList.PushBack(1);
    originalList.PushBack(2);
    originalList.PushBack(3);

    miit::List movedList;
    movedList.PushBack(4);
    movedList.PushBack(5);

    // act
    movedList = std::move(originalList);

    // assert
    ASSERT_EQ("1 2 3 ", movedList.toString());
}

TEST(list, inequality)
{
    // arrange
    miit::List firstList;
    miit::List secondList;

    firstList.PushBack(1);
    firstList.PushBack(2);
    firstList.PushBack(3);
    firstList.PushBack(4);

    secondList.PushBack(1);
    secondList.PushBack(2);
    secondList.PushBack(3);
    secondList.PushBack(5);

    // act
    bool act = (firstList != secondList);

    // assert
    ASSERT_EQ(true, act);
}