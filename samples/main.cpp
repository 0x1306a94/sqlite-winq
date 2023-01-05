#include <iostream>

#include <sqlite-winq/abstract/abstract.h>

#include "message.hpp"

using namespace SQLITEWINQ;
int main() {

    std::cout << SQLITEWINQ::Message::TableName() << std::endl;

    std::cout << SQLITEWINQ::Message::uid().inTable(SQLITEWINQ::Message::TableName()).getDescription() << std::endl;

    const ResultList res{
        Message::uid(),
    };

    auto expr = StatementSelect{}
                    .select(res, res.isDistinct())
                    .from(Message::TableName())
                    .where(Message::uid().in({"a", "b"}));
    std::cout << expr.getDescription() << std::endl;
    auto expr2 = SQLITEWINQ::Expr(SQLITEWINQ::Message::uid().inTable(SQLITEWINQ::Message::TableName()));
    std::cout << expr2.getDescription() << std::endl;

    return 0;
}

