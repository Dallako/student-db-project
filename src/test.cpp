#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"


TEST(CheckStructure, CanAddStudentToDb) {//requirements 1&2
    Student adam(
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "12345678901",
        Gender::Male
    );

    Database db;
    EXPECT_TRUE(db.add(adam));
    EXPECT_FALSE(db.add(adam));
}