/* $Id$
 *
 * Name:    exprCondEq.hpp
 * Author:  Daniel Bloemendal
*
 * This file is licensed under the Eclipse Public License (EPL)
 */

#ifndef COUENNE_EXPRCONDEQ_H
#define COUENNE_EXPRCONDEQ_H

#include "CouenneExprCond.hpp"

namespace Couenne {

class exprCondEq: public exprCond {

 public:

  exprCondEq (expression* left, expression* right, expression* if_true, expression* if_false):
    exprCond(left, right, if_true, if_false) {}

  /// Cloning method
  exprCondEq *clone (Domain *d = NULL) const
    {return new exprCondEq (arglist_[0]->clone(d), arglist_[1]->clone(d), arglist_[2]->clone(d), arglist_[3]->clone(d));}

  /// Code for comparisons
  virtual enum expr_type code ()
  {return COU_EXPRCONDGE;}

  std::string printOp () const
  {return ">=";}  

  CouNumber operator () () {
    if (fabs((*(arglist_[0]))() - (*(arglist_[1]))()) < COUENNE_EPS)
      return (*(arglist_[2]))();
    else
      return (*(arglist_[3]))();
  }
  
};

}

#endif
