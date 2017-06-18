#include "WGameRunner.hpp"

WGameRunner::WGameRunner (GameRunner *gameRunnner, QWidget *parent) :
    QWidget (parent),
    m_gameRunner (gameRunnner)
{
}
