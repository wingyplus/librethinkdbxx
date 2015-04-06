// auto-generated by yaml_to_cxx.py from test/upstream/mutation/sync.yaml
#include "testlib.h"
void test_upstream_mutation_sync() {
    enter_section("test_upstream_mutation_sync: Tests syncing tables");
    TEST_EQ(R::db("test").table_create("test1").run(*conn), (partial(R::Object{{"tables_created",1}})));
    TEST_EQ(R::db("test").table_create("test1soft").run(*conn), (partial(R::Object{{"tables_created",1}})));
    TEST_EQ(R::db("test").table("test1soft").config().update(R::object("durability", "soft")).run(*conn), (R::Object{{"skipped",0}, {"deleted",0}, {"unchanged",0}, {"errors",0}, {"replaced",1}, {"inserted",0}}));
    TEST_DO(auto tbl = (R::db("test").table("test1")));
    TEST_DO(auto tbl_soft = (R::db("test").table("test1soft")));
    TEST_EQ(tbl.index_create("x").run(*conn), (partial(R::Object{{"created",1}})));
    TEST_EQ(tbl.index_wait("x").pluck("index", "ready").run(*conn), (R::Array{R::Object{{"ready",true}, {"index","x"}}}));
    TEST_EQ(tbl.sync().run(*conn), (R::Object{{"synced",1}}));
    TEST_EQ(tbl_soft.sync().run(*conn), (R::Object{{"synced",1}}));
    TEST_EQ(tbl.sync().run(*conn), (R::Object{{"synced",1}}));
    TEST_EQ(tbl.sync().run(*conn), (R::Object{{"synced",1}}));
    TEST_EQ(R::db("test").table_drop("test1").run(*conn), (partial(R::Object{{"tables_dropped",1}})));
    TEST_EQ(R::db("test").table_drop("test1soft").run(*conn), (partial(R::Object{{"tables_dropped",1}})));
    exit_section();
}