/* $Id$
 *
 * Name:    exprCond.hpp
 * Author:  Daniel Bloemendal
*
 * This file is licensed under the Eclipse Public License (EPL)
 */

#ifndef COUENNE_EXPRCOND_H
#define COUENNE_EXPRCOND_H

#include "CouenneExprOp.hpp"

namespace Couenne {

class exprCond: public exprOp {

 public:
 
  exprCond (expression* left, expression* right, expression* if_true, expression* if_false):
    exprOp(new expression*[4], 4) {
    arglist_[0] = left;
    arglist_[1] = right;
    arglist_[2] = if_true;
    arglist_[3] = if_false;
  }

  // Print conditional
  void print (std::ostream &out, bool descend) const {
    out << "(" << std::flush;
    arglist_[0]->print(out, descend); out << std::flush;
    out << printOp() << std::flush;
    arglist_[1]->print(out, descend); out << std::flush;
    out << "?" << std::flush;
    arglist_[2]->print(out, descend); out << std::flush;
    out << ":" << std::flush;
    arglist_[3]->print(out, descend); out << std::flush;
    out << ")" << std::flush;
  }

  /// Differentiation
  inline expression *differentiate (int) 
    {return NULL;} 

  /// Simplification
  inline expression *simplify () 
    {return NULL;}

  /// get a measure of "how linear" the expression is (see CouenneTypes.h)
  virtual inline int Linearity () 
    {return NONLINEAR;}

  // Get lower and upper bound of an expression (if any)
  void getBounds (expression *&, expression *&);

  /// Reduce expression in standard form, creating additional aux
  /// variables (and constraints)
  virtual inline exprAux *standardize (CouenneProblem *, bool addAux = true)
    {return NULL;}

  /// Generate equality between *this and *w
  void generateCuts (expression *w, //const OsiSolverInterface &si, 
             OsiCuts &cs, const CouenneCutGenerator *cg, 
             t_chg_bounds * = NULL, int = -1, 
             CouNumber = -COUENNE_INFINITY, 
             CouNumber =  COUENNE_INFINITY);
};

}

#endif
