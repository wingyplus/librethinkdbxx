// auto-generated by yaml_to_cxx.py from test/upstream/regression/522.yaml
#include "testlib.h"
void test_upstream_regression_522() {
    enter_section("test_upstream_regression_522: Skip after orderby causes use-after-free (#522)");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    tbl.insert(R::array(R::object("id", 0), R::object("id", 1), R::object("id", 2))).run(*conn);
    TEST_EQ(tbl.order_by("id").skip(1).run(*conn), (R::Array{R::Object{{"id",1}}, R::Object{{"id",2}}}));
    exit_section();
}