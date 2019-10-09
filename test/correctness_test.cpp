#include <experimental/random>
#include <iostream>

#include "custom_list.hpp"
#include "gtest/gtest.h"

TEST(key, custom_list) {
	CustomList<int> list;
	list.push_back("eggs", 0);
	list.push_back("salt", 1);
	list.push_back("flour", 2);
	list.push_back("sugar", 3);
	list.push_back("milk", 4);
    ASSERT_EQ(list.get_by_key("sugar"), 3);
}

TEST(index, custom_list) {
	CustomList<int> list;
	list.push_back("sugar", 0);
	list.push_back("salt", 1);
	list.push_back("flour", 2);
	list.push_back("eggs", 3);
	list.push_back("milk", 4);
    ASSERT_EQ(list.get_by_index(3), 3);
}

TEST(no_index, custom_list) {
	CustomList<int> list;
	list.push_back("sugar", 0);
	list.push_back("salt", 1);
	list.push_back("flour", 2);
	list.push_back("eggs", 3);
	list.push_back("milk", 4);
    ASSERT_EQ(list.get_by_index(NULL), NULL);
}

TEST(no_key, custom_list) {
	CustomList<int> list;
	list.push_back("sugar", 0);
	list.push_back("salt", 1);
	list.push_back("flour", 2);
	list.push_back("eggs", 3);
	list.push_back("milk", 4);
    EXPECT_THROW(list.get_by_key(""), std::out_of_range);
}

TEST(access_empty, custom_list) {
	CustomList<int> list;
    EXPECT_THROW(list.get_by_key("sugar"), std::out_of_range);
}

TEST(throw_key, custom_list) {
	CustomList<int> list;
	list.push_back("sugar", 0);
	list.push_back("salt", 1);
	list.push_back("flour", 2);
	list.push_back("eggs", 3);
	list.push_back("milk", 4);
    EXPECT_THROW(list.get_by_key("baking_soda"), std::out_of_range);
}

TEST(throw_index, custom_list) {
	CustomList<int> list;
	list.push_back("sugar", 0);
	list.push_back("salt", 1);
	list.push_back("flour", 2);
	list.push_back("eggs", 3);
	list.push_back("milk", 4);
    EXPECT_THROW(list.get_by_index(5), std::out_of_range);
}

TEST(neg_index, custom_list) {
	CustomList<int> list;
	list.push_back("sugar", 0);
	list.push_back("salt", 1);
	list.push_back("flour", 2);
	list.push_back("eggs", 3);
	list.push_back("milk", 4);
    EXPECT_THROW(list.get_by_index(-2), std::out_of_range);
}

TEST(size, custom_list) {
	CustomList<int> list;
	list.push_back("sugar", 0);
	list.push_back("salt", 1);
	list.push_back("flour", 2);
	list.push_back("eggs", 3);
	list.push_back("milk", 4);
    ASSERT_EQ(list.size(), 5);
}

TEST(empty, custom_list) {
	CustomList<int> list;
    ASSERT_EQ(list.empty(), true);
}

TEST(no_empty, custom_list) {
	CustomList<int> list;
	list.push_back("sugar", 0);
    ASSERT_EQ(list.empty(), false);
}

TEST(big_by_key, custom_list) {
	CustomList<int> list;
	int total = 100000;
	for(int i = 0; i < total; ++i) {
		list.push_back(std::to_string(i), i);
	}
	int rand = std::experimental::randint(0, total - 1);
	ASSERT_EQ(list.get_by_key(std::to_string(rand)), rand);
}

TEST(big_by_index, custom_list) {
	CustomList<int> list;
	int total = 100000;
	for(int i = 0; i < total; ++i) {
		list.push_back(std::to_string(i), i);
	}
	int rand = std::experimental::randint(0, total - 1);
    ASSERT_EQ(list.get_by_index(rand), rand);
}

TEST(non_int_key, custom_list) {
	CustomList<std::string> list;
	list.push_back("sugar", "0");
	list.push_back("salt", "1");
	list.push_back("flour", "2");
	list.push_back("eggs", "3");
	list.push_back("milk", "4");
    ASSERT_EQ(list.get_by_key("salt"), "1");
}


TEST(non_int_index, custom_list) {
	CustomList<std::string> list;
	list.push_back("sugar", "0");
	list.push_back("salt", "1");
	list.push_back("flour", "2");
	list.push_back("eggs", "3");
	list.push_back("milk", "4");
    ASSERT_EQ(list.get_by_index(1), "1");
}

TEST(custom_class_key, custom_list) {
	class CustomClass {
		int data;
	public:
		CustomClass(int d) {data = d;}
		bool operator==(const CustomClass &other) const {
			return (this->data == other.data);
		}
	};
	CustomList<CustomClass> list;
	list.push_back("sugar", CustomClass(0));
	list.push_back("salt", CustomClass(1));
	list.push_back("flour", CustomClass(2));
	list.push_back("eggs", CustomClass(3));
	list.push_back("milk", CustomClass(4));
    ASSERT_EQ(list.get_by_key("flour"), CustomClass(2));
}

TEST(custom_class_index, custom_list) {
	class CustomClass {
		int data;
	public:
		CustomClass(int d) {data = d;}
		bool operator==(const CustomClass &other) const {
			return (this->data == other.data);
		}
	};
	CustomList<CustomClass> list;
	list.push_back("sugar", CustomClass(0));
	list.push_back("salt", CustomClass(1));
	list.push_back("flour", CustomClass(2));
	list.push_back("eggs", CustomClass(3));
	list.push_back("milk", CustomClass(4));
    ASSERT_EQ(list.get_by_index(1), CustomClass(1));
}