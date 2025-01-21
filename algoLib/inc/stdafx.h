#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>

#define TO_UPPER_FIRST_CHAR(name) \
    (name[0] >= 'a' && name[0] <= 'z' ? (name[0] - 'a' + 'A') : name[0])

#define PROPERTY_CREATE(type, name)             \
private:                                        \
    type m_##name;                              \
                                                \
public:                                         \
    type get##name() const { return m_##name; } \
    void set##name(const type &value) { m_##name = value; }
