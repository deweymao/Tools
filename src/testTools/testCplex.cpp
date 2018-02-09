#include "stdafx.h"
#include "testCplex.h"

/*object function : max(8 * x1 + 10 * x2)
constraints :
			2 * x1 + x2 <= 11;
			x1 + 2 * x2 <= 10;
			0 <= x1 <= 100;
			0 <= x2 <= 100;
			x1, x2 are integer.
CPLEX to solve!*/

bool TEST_CPLEX::testCplex() {
	IloEnv env;
	try {
		IloModel model(env, "Max Slove");
		IloNumVar x[2] = { IloNumVar(env, 0, 100, ILOINT), IloNumVar(env, 0, 100, ILOINT) };
		IloExpr objFunc = IloExpr(env);
		objFunc = 8 * x[0] + 10 * x[1];
		IloExpr constraint1 = IloExpr(env);
		constraint1 = 2 * x[0] + x[1];
		IloExpr constraint2 = IloExpr(env);
		constraint2 = x[0] + 2 * x[1];
		model.add(IloMaximize(env, objFunc));
		model.add(constraint1 <= 11);
		model.add(constraint2 <= 10);
		objFunc.end();
		constraint1.end();
		constraint2.end();

		IloCplex cplex(model);
		cplex.setOut(env.getNullStream()); //NOT output to console
		cplex.exportModel("testCplex.lp");
		if (cplex.solve()) {
			std::cout << "CPLEX solved!" << std::endl;
			std::cout << "x1=" << cplex.getValue(x[0]) << std::endl;
			std::cout << "x2=" << cplex.getValue(x[1]) << std::endl;
			std::cout << "objValue=" << cplex.getObjValue() << std::endl;
		} else {
			std::cout << "CPLEX failed!" << std::endl;
		}
	}
	catch (...) {
		return false;
	}
	env.end();
	return true;
}
