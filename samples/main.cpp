#include <iostream>

#include <sqlite-winq/abstract/abstract.h>
#include <sqlite-winq/accessor/cpp_accessor.h>
#include <sqlite-winq/binding/binding.h>
#include <sqlite-winq/binding/column_binding.h>
#include <sqlite-winq/binding/constraint_binding.h>
#include <sqlite-winq/binding/index_binding.h>

#include "message_schema.hpp"

using namespace SQLITEWINQ;
int main() {

    std::cout << MessageSchema::TableName() << std::endl;

    std::cout << StatementPragma{}.pragma(Pragma::UserVersion, 1) << std::endl;

    std::cout << MessageSchema::uid().inTable(MessageSchema::TableName()).count().as(MessageSchema::id()) << std::endl;

    auto v = sqlite_winq_column_redirection_null_type(MessageSchema, uid_type);

    const ResultList res{
        MessageSchema::AllProperties(),
    };

    auto expr = StatementSelect{}
                    .select(res, res.isDistinct())
                    .from(MessageSchema::TableName())
                    .where(MessageSchema::uid().in({"a", "b"}));
    std::cout << expr.getDescription() << ";" << std::endl;

    const Binding &binding = MessageSchema::Bindings();
    const StatementCreateTable &statement = binding.generateCreateTableStatement(MessageSchema::TableName());
    std::cout << statement << std::endl;

    const std::shared_ptr<IndexBindingMap> &indexBindingMap = binding.getIndexBindingMap();
    if (indexBindingMap) {
        for (const auto &indexBinding : *indexBindingMap.get()) {
            const StatementCreateIndex &statement = indexBinding.second->generateCreateIndexStatement(MessageSchema::TableName());
            std::cout << statement << std::endl;
        }
    }

    do {
        const PropertyList propertyList{
            MessageSchema::AllProperties(),
        };
        StatementInsert insert = StatementInsert{}
                                     .insert(MessageSchema::TableName(), propertyList, Conflict::Replace)
                                     .values(ExprList(propertyList.size(), Expr::BindParameter));
        std::cout << insert << std::endl;
    } while (0);
    return 0;
}
