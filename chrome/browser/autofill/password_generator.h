// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_AUTOFILL_PASSWORD_GENERATOR_H_
#define CHROME_BROWSER_AUTOFILL_PASSWORD_GENERATOR_H_

#include <string>

#include "base/basictypes.h"
#include "base/gtest_prod_util.h"

namespace autofill {

// Class to generate random passwords. Currently we just use a generic algorithm
// for all sites, but eventually we can incorporate additional information to
// determine passwords that are likely to be accepted (i.e. use pattern field,
// previous generated passwords, crowdsourcing, etc.)
class PasswordGenerator {
 public:
  // |max_length| is used as a hint for the generated password's length.
  explicit PasswordGenerator(size_t max_length);
  ~PasswordGenerator();

  // Returns a random password such that:
  // (1) Each character is guaranteed to be a non-whitespace printable ASCII
  //     character.
  // (2) The generated password will contain AT LEAST one upper case letter, one
  //     lower case letter, one digit, and one other symbol.
  // (3) The password length will be equal to |password_length_| (see comment
  //     for the constructor).
  std::string Generate() const;

 private:
  // Unit test also need to access |kDefaultPasswordLength|.
  static const size_t kDefaultPasswordLength;
  FRIEND_TEST_ALL_PREFIXES(PasswordGeneratorTest, PasswordLength);

  // The length of the generated password.
  const size_t password_length_;

  DISALLOW_COPY_AND_ASSIGN(PasswordGenerator);
};

}  // namespace autofill

#endif  // CHROME_BROWSER_AUTOFILL_PASSWORD_GENERATOR_H_