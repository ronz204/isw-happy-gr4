#pragma once

#include "Profile.h"
#include "RegularProfile.h"
#include "NewStudentProfile.h"
#include "WheelchairProfile.h"
#include "../../database/enums/ProfileType.h"
#include <memory>
#include <stdexcept>

class ProfileFactory
{
public:
  // Create a profile instance from ProfileType enum
  static std::unique_ptr<Profile> createProfile(ProfileType type)
  {
    switch (type)
    {
    case ProfileType::Regular:
      return std::make_unique<RegularProfile>();
    case ProfileType::NewStudent:
      return std::make_unique<NewStudentProfile>();
    case ProfileType::Wheelchair:
      return std::make_unique<WheelchairProfile>();
    default:
      throw std::invalid_argument("Invalid ProfileType");
    }
  }

  // Create a profile instance from string
  static std::unique_ptr<Profile> createProfile(const std::string &profileStr)
  {
    ProfileType type = profileTypeFromString(profileStr);
    return createProfile(type);
  }
};
