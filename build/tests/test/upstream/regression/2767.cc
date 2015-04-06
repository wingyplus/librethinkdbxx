// auto-generated by yaml_to_cxx.py from test/upstream/regression/2767.yaml
#include "testlib.h"
void test_upstream_regression_2767() {
    enter_section("test_upstream_regression_2767: 2767 -- Evaulate secondary index function with pristine env.");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    TEST_EQ(tbl.index_create("foo", [=](R::Var x){ return (((*x)["a"] + R::array(1, 2, 3, 4, 5)) + R::array(6, 7, 8, 9, 10)).count(); }).run(*conn), (R::Object{{"created",1}}));
    TEST_EQ(tbl.insert(R::object("id", 1, "a", R::array(1, 2, 3, 4, 5))).run(*conn), (R::Object{{"deleted",0}, {"replaced",0}, {"unchanged",0}, {"errors",0}, {"skipped",0}, {"inserted",1}}));
    TEST_EQ(tbl.coerce_to("array").run(*conn), (R::Array{R::Object{{"id",1}, {"a",R::Array{1, 2, 3, 4, 5}}}}));
    TEST_EQ(tbl.get_all(15, R::OptArgs{{"index", R::expr("foo")}}).coerce_to("array").run(*conn), (R::Array{R::Object{{"id",1}, {"a",R::Array{1, 2, 3, 4, 5}}}}));
    TEST_EQ(tbl.get_all(15, R::OptArgs{{"index", R::expr("foo")}}).coerce_to("array").run(*conn), (R::Array{R::Object{{"id",1}, {"a",R::Array{1, 2, 3, 4, 5}}}}));
    exit_section();
}