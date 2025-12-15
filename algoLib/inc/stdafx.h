#pragma once

#include <algorithm>
#include <chrono>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <random>
#include <stack>
#include <thread>
#include <vector>

#define PROPERTY_CREATE(type, name)             \
   private:                                     \
    type m_##name;                              \
                                                \
   public:                                      \
    type get##name() const { return m_##name; } \
    void set##name(const type& value) { m_##name = value; }

#define SAFE_DELETE_ARRAY(arr) \
    do {                       \
        if (arr) {             \
            delete[] arr;      \
            arr = nullptr;     \
        }                      \
    } while (0);

#define SAFE_DELETE_POINT(point) \
    do {                         \
        if (point) {             \
            delete point;        \
            point = nullptr;     \
        }                        \
    } while (0);

#define DISABLE_COPY(Class)       \
    Class(const Class&) = delete; \
    Class& operator=(const Class&) = delete;
