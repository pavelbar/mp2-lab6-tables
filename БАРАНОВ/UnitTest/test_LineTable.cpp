#pragma comment(lib, "GoogleTest.lib")
#include "Tline.h"
#include <gtest.h>


TEST(Tline, can_create_line_table_with_positive_length)
{
	ASSERT_NO_THROW(Tline v(5));
}

TEST(Tline, cant_create_line_table_with_negative_length)
{
	ASSERT_ANY_THROW(Tline v(-5));
}

TEST(Tline, cant_create_line_table_with_zero_length)
{
	ASSERT_ANY_THROW(Tline v(0));
}

TEST(Tline, cant_create_too_large_line_table) 
{
	ASSERT_ANY_THROW(Tline v(MaxSize + 1));
}

TEST(Tline, cant_add_to_full_line_table) 
{
	Tline v(2);
	v.add("test1","a");
	v.add("test2","b");
	ASSERT_ANY_THROW(v.add("test3","c"));
}

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

//-argOne and argTwo														
TEST(Tline, can_get_argOne_of_line_table_about_one_fo_arg_one)
{
	Tline v(5);
	v.add("test1", "a");
	string result = "test1";
	EXPECT_EQ(result, v.get_argOne_Of_Line_N(0));
}

TEST(Tline, can_get_argTwo_of_line_table_about_one_fo_arg_two)
{
	Tline v(5);
	v.add("test1", "a");
	string result = "a";
	EXPECT_EQ(result, v.get_argTwo_Of_Line_N(0));
}

TEST(Tline, can_get_argOne_of_line_table_about_two_fo_arg_one)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	string result = "test2";
	EXPECT_EQ(result, v.get_argOne_Of_Line_N(1));
}

TEST(Tline, can_get_argTwo_of_line_table_about_two_fo_arg_two)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	string result = "b";
	EXPECT_EQ(result, v.get_argTwo_Of_Line_N(1));
}

TEST(Tline, can_get_argOne_of_line_table_about_three_fo_arg_one)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	string result = "test3";
	EXPECT_EQ(result, v.get_argOne_Of_Line_N(2));
}

TEST(Tline, can_get_argTwo_of_line_table_about_three_fo_arg_two)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	string result = "c";
	EXPECT_EQ(result, v.get_argTwo_Of_Line_N(2));
}
//-----

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

TEST(Tline, IsEmpty_false_of_full_line_table) 
{
	Tline v(2);
	v.add("tes1", "a");
	v.add("tes2","b");
	ASSERT_FALSE(v.IsEmpty());
}

TEST(Tline, IsEmpty_true_of_clear_line_table)
{
	Tline v(2);
	ASSERT_TRUE(v.IsEmpty());
}

TEST(Tline, IsEmpty_false_of_any_line_table)
{
	Tline v(2);
	v.add("tes1", "a");
	ASSERT_FALSE(v.IsEmpty());
}

TEST(Tline, IsFull_true_of_full_line_table)
{
	Tline v(2);
	v.add("tes1", "a");
	v.add("tes2", "b");
	ASSERT_TRUE(v.IsFull());
}

TEST(Tline, IsFull_false_of_clear_line_table)  
{
	Tline v(2);
	ASSERT_FALSE(v.IsFull());
}

TEST(Tline, IsFull_false_of_any_line_table)  
{
	Tline v(2);
	v.add("tes1", "a");
	ASSERT_FALSE(v.IsFull());
}

//searchId
TEST(Tline, can_searchID_argOne)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = 2;
	EXPECT_EQ(result, v.searchID_argOne("test3"));
}

TEST(Tline, cant_searchID_argOne)
	{
		Tline v(5);
		v.add("test1", "a");
		v.add("test2", "b");
		v.add("test3", "c");
		int result = -1;
		EXPECT_EQ(result, v.searchID_argOne("test4"));
}

TEST(Tline, can_searchID_argTwo)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = 2;
	EXPECT_EQ(result, v.searchID_argTwo("c"));
}

TEST(Tline, cant_searchID_argTwo)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = -1;
	EXPECT_EQ(result, v.searchID_argTwo("d"));
}

TEST(Tline, can_searchID_argOne_about_centre)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = 1;
	EXPECT_EQ(result, v.searchID_argOne("test2"));
}

TEST(Tline, can_searchID_argTwo_about_centre)
{
	Tline v(5);
	v.add("test1", "a");
	v.add("test2", "b");
	v.add("test3", "c");
	int result = 1;
	EXPECT_EQ(result, v.searchID_argTwo("b"));
}
//--