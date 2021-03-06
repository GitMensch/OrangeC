/* Software License Agreement
 * 
 *     Copyright(C) 1994-2018 David Lindauer, (LADSoft)
 * 
 *     This file is part of the Orange C Compiler package.
 * 
 *     The Orange C Compiler package is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version, with the addition of the 
 *     Orange C "Target Code" exception.
 * 
 *     The Orange C Compiler package is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with Orange C.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *     contact information:
 *         email: TouchStone222@runbox.com <David Lindauer>
 * 
 */

#include "Variable.h"

bool Variable::environmentHasPriority = false;
VariableContainer *VariableContainer::instance = nullptr;

Variable::Variable(const std::string &Name, const std::string &Value, Flavor oFlavor, Origin oOrigin)
    : name(Name), value(Value), flavor(oFlavor), origin(oOrigin), constant(false), permanent(false)
{
    exportFlag = origin == o_command_line || origin == o_environ || origin == o_environ_override;
}
void Variable::AppendValue(const std::string &Value, bool dooverride)
{
    if (dooverride || (origin != o_command_line && origin != o_environ_override))
    {
        if (!constant)
            value += Value;
    }
}
void Variable::AssignValue(const std::string &Value, Origin oOrigin, bool dooverride)
{
    if (dooverride || (origin != o_command_line && origin != o_environ_override))
    {
        if (!constant)
        {
            value = Value;
            origin = oOrigin;
        }
    }
}

VariableContainer *VariableContainer::Instance()
{
    if (!instance)
        instance = new VariableContainer;
    return instance;
}
Variable *VariableContainer::Lookup(const std::string &name)
{
    Variable *rv = nullptr;
    if (name.find_first_of('%') != std::string::npos)
    {
        for (PatternIterator it = PatternBegin(); it != PatternEnd(); ++it)
        {
            if ((*it)->GetName() == name)
            {
                rv = *it;
                break;
            }
        }
    }
    else
    {
        auto it = variables.find(&name);
        if (it != variables.end())
        {
            rv = it->second;
        }
    }
    return rv;
}
void VariableContainer::operator +(Variable *variable)
{
    if (variable->GetName().find_first_of('%') != std::string::npos)
    {
        patternVariables.push_back(variable);
    }
    else
    {
        variables[&variable->GetName()] = variable;
    }
}
void VariableContainer::Clear()
{
    for (PatternIterator it = PatternBegin(); it != PatternEnd(); ++it)
    {
        Variable *p = (*it);
        delete p;
    }
    patternVariables.clear();
    for (auto var : *this)
        delete var.second;
    variables.clear();
}