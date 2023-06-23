/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
// SPDX-License-Identifier: GPL-3.0

#include <libsolidity/codegen/experimental/Common.h>
#include <libsolidity/ast/experimental/TypeSystem.h>

#include <libsolutil/CommonIO.h>

#include <libyul/AsmPrinter.h>

using namespace std;
using namespace solidity::langutil;
using namespace solidity::frontend;
using namespace solidity::util;
using namespace solidity::yul;

namespace solidity::frontend::experimental
{

string IRNames::function(FunctionDefinition const& _function, Type _type)
{
	if (_function.isConstructor())
		return constructor(*_function.annotation().contract);

	return "fun_" + _function.name() + "_" + to_string(_function.id()) + "$" + canonicalTypeName(_type) + "$";
}

string IRNames::function(VariableDeclaration const& _varDecl)
{
	return "getter_fun_" + _varDecl.name() + "_" + to_string(_varDecl.id());
}

string IRNames::creationObject(ContractDefinition const& _contract)
{
	return _contract.name() + "_" + toString(_contract.id());
}

string IRNames::deployedObject(ContractDefinition const& _contract)
{
	return _contract.name() + "_" + toString(_contract.id()) + "_deployed";
}

string IRNames::constructor(ContractDefinition const& _contract)
{
	return "constructor_" + _contract.name() + "_" + to_string(_contract.id());
}

string IRNames::localVariable(VariableDeclaration const& _declaration)
{
	return "var_" + _declaration.name() + '_' + std::to_string(_declaration.id());
}

string IRNames::localVariable(Expression const& _expression)
{
	return "expr_" + to_string(_expression.id());
}

}
