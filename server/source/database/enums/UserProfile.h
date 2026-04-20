#pragma once

#include <string>
#include <stdexcept>

enum class UserProfile
{
  Regular = 1,
  NewStudent = 2,
  Wheelchair = 3,
  Crutches = 4,
  LimitedMobility = 5,
  Staff = 6,
  Visitor = 7,
};

// Convert UserProfile to string
inline std::string toString(UserProfile profile)
{
  switch (profile)
  {
  case UserProfile::Regular:
    return "Regular";
  case UserProfile::NewStudent:
    return "NewStudent";
  case UserProfile::Wheelchair:
    return "Wheelchair";
  case UserProfile::Crutches:
    return "Crutches";
  case UserProfile::LimitedMobility:
    return "LimitedMobility";
  case UserProfile::Staff:
    return "Staff";
  case UserProfile::Visitor:
    return "Visitor";
  default:
    throw std::invalid_argument("Invalid UserProfile");
  }
}

// Convert string to UserProfile
inline UserProfile userProfileFromString(const std::string &str)
{
  if (str == "Regular")
    return UserProfile::Regular;
  if (str == "NewStudent")
    return UserProfile::NewStudent;
  if (str == "Wheelchair")
    return UserProfile::Wheelchair;
  if (str == "Crutches")
    return UserProfile::Crutches;
  if (str == "LimitedMobility")
    return UserProfile::LimitedMobility;
  if (str == "Staff")
    return UserProfile::Staff;
  if (str == "Visitor")
    return UserProfile::Visitor;
  throw std::invalid_argument("Invalid UserProfile string: " + str);
}

// Convert UserProfile to int
inline int toInt(UserProfile profile)
{
  return static_cast<int>(profile);
}
