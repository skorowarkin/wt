// This may look like C code, but it's really -*- C++ -*-
/* 
 * Copyright (C) 2011 Emweb bvba, Heverlee, Belgium
 *
 * See the LICENSE file for terms of use.
 */

#ifndef USER_H_
#define USER_H_

#include <Wt/WDateTime>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/WtSqlTraits>

#include <string>

class User {
public:
  std::string     name;
  std::string     password;
  int             gamesPlayed;
  long long       score;
  Wt::WDateTime   lastLogin;

  template<class Action>
  void persist(Action& a)
  {
    Wt::Dbo::field(a, name,        "name");
    Wt::Dbo::field(a, password,    "password");
    Wt::Dbo::field(a, gamesPlayed, "gamesPlayed");
    Wt::Dbo::field(a, score,       "score");
    Wt::Dbo::field(a, lastLogin,   "lastLogin");
  }
  
  User() {}

  User(const std::string &name, const std::string &password);

  int findRanking(Wt::Dbo::Session& session) const;
};

typedef Wt::Dbo::collection< Wt::Dbo::ptr<User> > Users;

#endif //USER_H_
