#include "gtest/gtest.h"
//#include <string>

typedef enum
{
    forward = 0,
    backward,
    left,
    right
}enuCommand;

typedef enum
{
    N = 0,
    S,
    E,
    W
}enuDirection;

typedef struct
{
    unsigned char x;
    unsigned char y;
} strPosition;

class Rover
{
public:
    strPosition m_position;
    enuDirection m_direction;

    Rover(strPosition position, enuDirection direction)
    {
        this->m_position.x = position.x;
        this->m_position.y = position.y;
        this->m_direction = direction;
    }

    void moveFB(enuCommand command)
    {
        switch(command)
        {
            case forward:
                switch(this->m_direction)
                {
                    case N:
                        this->m_position.y += 1;
                        break;
                    case S:
                        this->m_position.y -= 1;
                        break;
                    case E:
                        this->m_position.x += 1;
                        break;
                    case W:
                        this->m_position.x -= 1;
                        break;
                    default:
                        break;
                }
            break;

            case backward:
                this->m_position.y -= 1;
                break;

            default:
                break;
        }

    }
};

/* -------------------- TESTS -------------------- */
TEST(TestRobot, Constructor) {
    strPosition position = {0, 0};
    Rover myRover = Rover(position, N);
    ASSERT_EQ(myRover.m_direction, N);
    ASSERT_EQ(myRover.m_position.x, 0);
    ASSERT_EQ(myRover.m_position.y, 0);
}

TEST(TestRobot, MoveForwardNord) {
    strPosition position = {0, 0};
    Rover myRover = Rover(position, N);
    myRover.moveFB(forward);
    ASSERT_EQ(myRover.m_direction, N);
    ASSERT_EQ(myRover.m_position.x, 0);
    ASSERT_EQ(myRover.m_position.y, 1);
}

TEST(TestRobot, MoveBackwardNord) {
    strPosition position = {2, 2};
    Rover myRover = Rover(position, N);
    myRover.moveFB(backward);
    ASSERT_EQ(myRover.m_direction, N);
    ASSERT_EQ(myRover.m_position.x, 2);
    ASSERT_EQ(myRover.m_position.y, 1);
}

TEST(TestRobot, MoveForwardEst) {
    strPosition position = {0, 0};
    Rover myRover = Rover(position, E);
    myRover.moveFB(forward);
    ASSERT_EQ(myRover.m_direction, E);
    ASSERT_EQ(myRover.m_position.x, 1);
    ASSERT_EQ(myRover.m_position.y, 0);
}

TEST(TestRobot, MoveForwardWest) {
    strPosition position = {2, 2};
    Rover myRover = Rover(position, W);
    myRover.moveFB(forward);
    ASSERT_EQ(myRover.m_direction, W);
    ASSERT_EQ(myRover.m_position.x, 1);
    ASSERT_EQ(myRover.m_position.y, 2);
}

TEST(TestRobot, MoveForwardSouth) {
    strPosition position = {2, 2};
    Rover myRover = Rover(position, S);
    myRover.moveFB(forward);
    ASSERT_EQ(myRover.m_direction, S);
    ASSERT_EQ(myRover.m_position.x, 2);
    ASSERT_EQ(myRover.m_position.y, 1);
}
