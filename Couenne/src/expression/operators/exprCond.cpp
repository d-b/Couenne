/* $Id$ */
/*
 * Name:    exprCond.cpp
 * Author:  Daniel Bloemendal
 *
 * This file is licensed under the Eclipse Public License (EPL)
 */


#include "OsiSolverInterface.hpp"

#include "CouenneCutGenerator.hpp"
#include "CouenneTypes.hpp"
#include "CouenneExprCond.hpp"
#include "CouenneExprCondGt.hpp"
#include "CouenneExprCondGe.hpp"
#include "CouenneExprCondLt.hpp"
#include "CouenneExprCondLe.hpp"
#include "CouenneExprCondEq.hpp"
#include "CouenneExprConst.hpp"

using namespace Couenne;

void exprCond::getBounds (expression *&lower, expression *&upper) {
  lower = new exprConst (-COIN_DBL_MAX);
  upper = new exprConst ( COIN_DBL_MAX);
}

void exprCond::generateCuts (expression *w, //const OsiSolverInterface &si, 
			    OsiCuts &cs, const CouenneCutGenerator *cg,
			    t_chg_bounds *chg, int,
			    CouNumber, CouNumber) 
{}
