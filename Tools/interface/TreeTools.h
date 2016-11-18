#include "Common.h"

#ifndef TREETOOLS_H
#define TREETOOLS_H

/*
 * */

//////////////////////////////////////////////////////////////////////////////////

// function that figures out any substrings of s that are branch dependencies
// and sets the status to 1
inline void turnOnBranches(TTree*t,TString s) {
  std::vector<TString> deps = getDependencies(s);
  for (auto d : deps) {
    TBranch *b = (TBranch*)t->GetListOfBranches()->FindObject(d);
    if (b)
      t->SetBranchStatus(d,1);
  }
}

//////////////////////////////////////////////////////////////////////////////////

#endif