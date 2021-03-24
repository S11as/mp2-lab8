#include <gtest.h>
#include "TStackList.h"

TEST(Stack, can_create_stack)
{
    ASSERT_NO_THROW(TStackList<int>());
}


TEST(Stack, can_push_item_to_stack)
{
    TStackList<int> s;
    ASSERT_NO_THROW(s.push(1));
}

TEST(Stack, can_copy_stack)
{
    TStackList<int> s;
    for (int i = 0; i < 20; ++i) {
        s.push(i);
    }
    TStackList<int> b = s;

    for (int j = 19; j >= 0; --j) {
        EXPECT_EQ(b.pop(), j);
    }
    ASSERT_NO_THROW(s.push(1));
}


TEST(Stack, can_pop_item_from_stack)
{
    TStackList<int> s;
    s.push(1);
    int number = s.pop();
    EXPECT_EQ(number, 1);
}

TEST(Stack, default_stack_is_empty)
{
    TStackList<int> s;
    EXPECT_EQ(s.is_empty(), true);
}

TEST(Stack, item_pop_makes_stack_empty)
{
    TStackList<int> s;
    s.push(1);
    int number = s.pop();
    EXPECT_EQ(s.is_empty(), true);
}

TEST(Stack, stack_with_items_is_not_empty)
{
    TStackList<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.is_empty(), false);
}

TEST(Stack, cant_pop_item_from_empty_stack)
{
    TStackList<int> s;
    s.push(1);
    s.pop();
    ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_get_max_element)
{
    TStackList<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.get_max(), 3);

}

TEST(Stack, can_get_least_element)
{
    TStackList<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.get_least(), 1);
}



