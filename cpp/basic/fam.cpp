/**
 * @file fam.cpp
 * @author ymy1248 (ymy1248@outlook.com)
 * @brief FAM stands for Flexible Array Members
 *  - Declare an array without a dimension means it's size is flexible in nature.
 *  - Such an array inside the structure should preferably be declared as the last member of structure and its size is variable(can be changed be at runtime).
 *  - The structure must contain at least one more named member in addition to the flexible array member.
 *
 * ! Useful when one object has flexible payload. Without extra memory overhead.
 * @version 0.1
 * @date 2021-12-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <gtest/gtest.h>

struct Widget {
 public: 
    uint32_t _i;
    float _f;
    char _fam[];
};

struct Payload {
    uint32_t _data;
};

TEST(FAM, basic) {
    // No extra data for fam.
    EXPECT_EQ(sizeof(Widget), 8);

    // For this widget, it equals to:
    // struct Widget {
    // public: 
    //     uint32_t _i;
    //     float _f;
    //     Payload _fam;
    // };
    Widget *w = reinterpret_cast<Widget*>(malloc(sizeof(Widget) + sizeof(Payload)));
    memset(w, 0, sizeof(Widget) + sizeof(Payload));
    EXPECT_EQ(((Payload*)w->_fam)->_data, 0);
}