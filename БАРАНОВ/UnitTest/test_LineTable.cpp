#pragma comment(lib, "GoogleTest.lib")
#include "Tline.h"
#include <gtest.h>

//Get size
TEST(Tline, method_get_sise_work_correctly)//Get size
{
	Tline v(2);
	EXPECT_EQ(2,v.get_SizeTable());
}

//Get count
TEST(Tline, method_get_count_work_correctly_in_an_empty_table)//Get count
{
	Tline v(2);
	EXPECT_EQ(0, v.get_count());
}

TEST(Tline, method_get_count_work_correctly_in_a_non_empty_table)//Get count
{
	Tline v(2);
	v.add("tes1", "a");
	EXPECT_EQ(1, v.get_count());
}
//---

//Kit
TEST(Tline, can_create_line_table_with_positive_length)//kit
{
	ASSERT_NO_THROW(Tline v(5));
}

TEST(Tline, cant_create_line_table_with_negative_length)//kit
{
	ASSERT_ANY_THROW(Tline v(-5));
}

TEST(Tline, cant_create_line_table_with_zero_length)//kit
{
	ASSERT_ANY_THROW(Tline v(0));
}

TEST(Tline, cant_create_too_large_line_table)//kit
{
	ASSERT_ANY_THROW(Tline v(MaxSize + 1));
}
//---

//IsEmpty and IsFull
TEST(Tline, IsEmpty_false_of_full_line_table)//IsEmpty
{
	Tline v(2);
	v.add("tes1", "a");
	v.add("tes2", "b");
	ASSERT_FALSE(v.IsEmpty());
}

TEST(Tline, IsEmpty_true_of_clear_line_table)//IsEmpty
{
	Tline v(2);
	ASSERT_TRUE(v.IsEmpty());
}

TEST(Tline, IsEmpty_false_of_any_line_table)//IsEmpty
{
	Tline v(2);
	v.add("tes1", "a");
	ASSERT_FALSE(v.IsEmpty());
}

TEST(Tline, IsFull_true_of_full_line_table)//IsFull
{
	Tline v(2);
	v.add("tes1", "a");
	v.add("tes2", "b");
	ASSERT_TRUE(v.IsFull());
}

TEST(Tline, IsFull_false_of_clear_line_table)//IsFull
{
	Tline v(2);
	ASSERT_FALSE(v.IsFull());
}

TEST(Tline, IsFull_false_of_any_line_table)//IsFull
{
	Tline v(2);
	v.add("tes1", "a");
	ASSERT_FALSE(v.IsFull());
}
//--- 

//add
TEST(Tline, cant_add_to_full_line_table)//add
{
	Tline v(2);
	v.add("test1","a");
	v.add("test2","b");
	ASSERT_ANY_THROW(v.add("test3","c"));
}

TEST(Tline, can_add_to_line_table)//add
{
	Tline v(2);
	v.add("test1", "a");
	ASSERT_NO_THROW(v.add("test2", "b"));
}

TEST(Tline, method_add_work_properlye_for_first_arg)//add
{
	Tline v(2);
	v.add("test1", "a");
	string result = "test1";
	EXPECT_EQ(result, v.get_argOne_Of_Line_N(0));
}

TEST(Tline, method_add_work_properlye_for_second_arg)//add
{
	Tline v(2);
	v.add("test1", "a");
	string result = "a";
	EXPECT_EQ(result, v.get_argTwo_Of_Line_N(0));
}
//---

//dell
TEST(Tline, can_dell_second_line_of_line_table)//dell
{
	Tline v(2);
	v.add("test1", "a");
	v.add("test2", "b");
	ASSERT_NO_THROW(v.dell(1));
}

TEST(Tline, can_dell_first_line_of_line_table)//dell
{
	Tline v(2);
	v.add("test1", "a");
	v.add("test2", "b");
	ASSERT_NO_THROW(v.dell(0));
}

TEST(Tline, work_count_when_dell_second_line)//dell
{
	Tline v(2);
	v.add("test1", "a");
	v.add("test2", "b");
	v.dell(1);
	EXPECT_EQ(1,v.get_count());
}

TEST(Tline, work_count_when_dell_first_line)//dell
{
	Tline v(2);
	v.add("test1", "a");
	v.add("test2", "b");
	v.dell(0);
	EXPECT_EQ(1, v.get_count());
}

TEST(Tline, work_dell_for_first_line)//dell
{
	Tline v(2);
	v.add("test1", "a");
	v.add("test2", "b");
	v.dell(0);
	EXPECT_EQ("test2", v.get_argOne_Of_Line_N(0));
}

TEST(Tline, work_dell_for_second_line)//dell
{
	Tline v(2);
	v.add("test1", "a");
	v.add("test2", "b");
	v.dell(1);
	EXPECT_EQ("test1", v.get_argOne_Of_Line_N(0));
}
//---

//get_argOne and get_argTwo														
TEST(Tline, can_get_argOne_of_line_table_about_one_for_first_arg)//argOne 
{
	Tline v(5);
	v.add("test1", "a");
	string result = "test1";
	EXPECT_EQ(result, v.get_argOne_Of_Line_N(0));
}

TEST(Tline, can_get_argTwo_of_line_table_about_one_for_second_arg)//argTwo	
{
	Tline v(5);
	v.add("test1", "a");
	string result = "a";
	EXPECT_EQ(result, v.get_argTwo_Of_Line_N(0));
}

TEST(Tline, can_get_argOne_of_line_table_about_two_for_first_arg)//argTwo	
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	string result = "test2";
	EXPECT_EQ(result, v.get_argOne_Of_Line_N(1));
}

TEST(Tline, can_get_argTwo_of_line_table_about_two_for_second_arg)//argTwo	
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	string result = "b";
	EXPECT_EQ(result, v.get_argTwo_Of_Line_N(1));
}

TEST(Tline, can_get_argOne_of_line_table_about_three_for_first_arg)//argOne
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	string result = "test3";
	EXPECT_EQ(result, v.get_argOne_Of_Line_N(2));
}

TEST(Tline, can_get_argTwo_of_line_table_about_three_for_second_arg)//argTwo	
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	string result = "c";
	EXPECT_EQ(result, v.get_argTwo_Of_Line_N(2));
}
//-----

//searchID_argOne and searchID_argTwo
TEST(Tline, can_searchID_argOne)//searchID_argOne
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = 2;
	EXPECT_EQ(result, v.searchID_argOne("test3"));
}

TEST(Tline, cant_searchID_argOne)//searchID_argOne
	{
		Tline v(5);
		v.add("test1", "a");
		v.add("test2", "b");
		v.add("test3", "c");
		int result = -1;
		EXPECT_EQ(result, v.searchID_argOne("test4"));
}

TEST(Tline, can_searchID_argTwo)//searchID_argTwo
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = 2;
	EXPECT_EQ(result, v.searchID_argTwo("c"));
}

TEST(Tline, cant_searchID_argTwo)//searchID_argTwo
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = -1;
	EXPECT_EQ(result, v.searchID_argTwo("d"));
}

TEST(Tline, can_searchID_argOne_about_centre)//searchID_argOne
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = 1;
	EXPECT_EQ(result, v.searchID_argOne("test2"));
}

TEST(Tline, can_searchID_argTwo_about_centre)//searchID_argTwo
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = 1;
	EXPECT_EQ(result, v.searchID_argTwo("b"));
}
//---
//Лишнее
/*

TEST(Tline, cant_popID_of_clear_line_table)
{
Tline v(2);
ASSERT_ANY_THROW(v.popID());
}

TEST(Tline, cant_topID_of_clear_line_table)
{
Tline v(2);
ASSERT_ANY_THROW(v.topID());
}

//PopID
TEST(Tline, can_popID_of_line_table_about_one)
{
Tline v(5);
v.add("test1", "a");
int result = 0;
EXPECT_EQ(result, v.popID());
}

TEST(Tline, can_popID_of_line_table_about_two)
{
Tline v(5);
v.add("test1", "a");
v.add("test2", "b");
int result = 1;
EXPECT_EQ(result, v.popID());
}

TEST(Tline, can_popID_of_line_table_about_three)
{
Tline v(5);
v.add("test1", "a");
v.add("test2", "b");
v.add("test3", "c");
int result = 2;
EXPECT_EQ(result, v.popID());
}
//----

//TopId
TEST(Tline, can_topID_of_line_table_about_one)
{
Tline v(5);
v.add("test1", "a");
int result = 1;
EXPECT_EQ(result, v.topID());
}

TEST(Tline, can_topID_of_line_table_about_two)
{
Tline v(5);
v.add("test1", "a");
v.add("test2", "b");
int result = 2;
EXPECT_EQ(result, v.topID());
}

TEST(Tline, can_topID_of_line_table_about_three)
{
Tline v(5);
v.add("test1", "a");
v.add("test2", "b");
v.add("test3", "c");
int result = 3;
EXPECT_EQ(result, v.topID());
}
//---
*/