#include <check.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "treedata.h"

Tree *tree;

void setup(void) {
    tree = createTree(compareStrings, destroyString, copyString);
}

void teardown(void) {
    destroyTree(tree);
    tree = NULL;
}

/* ---------- Empty tree: atomic tests ---------- */

START_TEST(test_create_tree_not_null) {
    ck_assert_ptr_nonnull(tree);
}
END_TEST

START_TEST(test_empty_tree_root_is_null) {
    ck_assert_ptr_null(getRoot(tree));
}
END_TEST


/* ---------- Suite and Runner ---------- */

Suite *tree_suite(void) {
    Suite *s = suite_create("BalancedTree");

    TCase *tc = tcase_create("Core");
    tcase_add_checked_fixture(tc, setup, teardown);

    /* Empty tree */
    tcase_add_test(tc, test_create_tree_not_null);
    tcase_add_test(tc, test_empty_tree_root_is_null);

  

    suite_add_tcase(s, tc);
    return s;
}

int main(void) {
    int failed;
    Suite *s = tree_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}