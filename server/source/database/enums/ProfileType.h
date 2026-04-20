#pragma once

#include <string>
#include <stdexcept>

enum class ProfileType
{
  Regular = 1,
  NewStudent = 2,
  Wheelchair = 3,
};

// Convert ProfileType to string
inline std::string toString(ProfileType profile)
{
  switch (profile)
  {
  case ProfileType::Regular:
    return "Regular";
  case ProfileType::NewStudent:
    return "NewStudent";
  case ProfileType::Wheelchair:
    return "Wheelchair";
  default:
    throw std::invalid_argument("Invalid ProfileType");
  }
}

// Convert string to ProfileType
inline ProfileType profileTypeFromString(const std::string &str)
{
  if (str == "Regular")
    return ProfileType::Regular;
  if (str == "NewStudent")
    return ProfileType::NewStudent;
  if (str == "Wheelchair")
    return ProfileType::Wheelchair;
  throw std::invalid_argument("Invalid ProfileType string: " + str);
}

// Convert ProfileType to int
inline int toInt(ProfileType profile)
{
  return static_cast<int>(profile);
}
