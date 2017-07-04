/* $Id$
 *
 * Name:    exprCondLt.hpp
 * Author:  Daniel Bloemendal
*
 * This file is licensed under the Eclipse Public License (EPL)
 */

#ifndef COUENNE_EXPRCONDLT_H
#define COUENNE_EXPRCONDLT_H

#include "CouenneExprCond.hpp"

namespace Couenne {

class exprCondLt: public exprCond {

 public:

  exprCondLt (expression* left, expression* right, expression* if_true, expression* if_false):
    exprCond(left, right, if_true, if_false) {}

  /// Cloning method
  exprCondLt *clone (Domain *d = NULL) const
    {return new exprCondLt (arglist_[0]->clone(d), arglist_[1]->clone(d), arglist_[2]->clone(d), arglist_[3]->clone(d));}

  /// Code for comparisons
  virtual enum expr_type code ()
  {return COU_EXPRCONDLT;}

  std::string printOp () const
  {return "<";}  

  CouNumber operator () () {
    if ((*(arglist_[0]))() < (*(arglist_[1]))())
      return (*(arglist_[2]))();
    else
      return (*(arglist_[3]))();
  }
  
};

}

#endif
