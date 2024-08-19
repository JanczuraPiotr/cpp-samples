#include "ControlledConstructionGTest.hpp"
#include "../classes/ControlledConstruction.hpp"

TEST_F(ControlledConstructionGTest, toShort)
{
    EXPECT_EQ(ControlledConstruction::Valid::TO_SHORT, ControlledConstruction::validate("12"));
    EXPECT_NE(ControlledConstruction::Valid::TO_SHORT, ControlledConstruction::validate("123"));
}

TEST_F(ControlledConstructionGTest, toLong)
{
    EXPECT_NE(ControlledConstruction::Valid::TO_LONG, ControlledConstruction::validate("0123456789"));
    EXPECT_EQ(ControlledConstruction::Valid::TO_LONG, ControlledConstruction::validate("01234567891"));
}

TEST_F(ControlledConstructionGTest, ok)
{
    EXPECT_EQ(ControlledConstruction::Valid::OK, ControlledConstruction::validate("1234"));
}

