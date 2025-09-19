#include <check.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "treedata.h"
#include <stdio.h>

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

//testing myself
// START_TEST(test_finding_node) {
//     char * teststring = "Robert";
//     insertNode(tree, teststring);
//     TreeNode * newNode; 
//     newNode = findNode(tree, teststring);
//     ck_assert_ptr_nonnull(newNode);
//     ck_assert_str_eq(getNodeData(newNode), teststring); //checks if equal using strcmp

// }
// END_TEST

START_TEST(test_finding_node_when_empty) {
    TreeNode * newNode;
    newNode = findNode(tree, "teststring");
    //ck_assert_str_eq(getNodeData(newNode), "teststring");
    ck_assert_ptr_null(getNodeData(newNode));
}
END_TEST

START_TEST(test_finding_node_when_empty_with_contents) {
    insertNode(tree, "car");
    insertNode(tree, "phone");
    insertNode(tree, "earbuds");
    TreeNode * newNode;
    newNode = findNode(tree, "teststring");
    //ck_assert_str_eq(getNodeData(newNode), "teststring");
    ck_assert_ptr_null(getNodeData(newNode));
}
END_TEST

START_TEST(test_compare_strings_when_equal) {
    int result;
    result = compareStrings("string", "string");
    ck_assert_int_eq(result, 0);
}
END_TEST

//
// START_TEST(test_free) {
//     insertNode(tree, "hahaha");
//     char *copy = copyString("hahaha");
//     //ck_assert_ptr_nonnull(copy); //checks if not equal to null
//     destroyString(copy);

//     copy = NULL; //
//     ck_assert_ptr_null(copy); //checks if equal to null   
    

// }
// END_TEST

// START_TEST(test_free_not_exist) {
//     insertNode(tree, "hahaha");
//     char *copy = copyString("hahahaha");
//     //ck_assert_ptr_nonnull(copy); //checks if not equal to null
//     destroyString(copy);

//     copy = NULL; //
//     ck_assert_ptr_null(copy); //checks if equal to null   
    

// }
// END_TEST



                START_TEST (test_get_root_when_no_data) {
                    //insertNode(tree, "hi");
                    getRoot(tree);
                    ck_assert_ptr_null(getRoot);
                }
                END_TEST

                // START_TEST (test_get_root_when_data) {
                //     insertNode(tree, "hi");
                //     getRoot(tree);
                //     ck_assert_ptr_nonnull(getRoot);
                // }
                // END_TEST

// START_TEST (test_correct_height) {
//     // insertNode(tree, "hi");
//     // insertNode(tree, "rob");
//     // insertNode(tree, "bye");
//     // insertNode(tree, "tea");
//     // //ck_assert_int_eq(getNodeHeight("tea"), 1);
//     // //char * address = findNode(tree, "tea");
//     // int result;
//     // result = getNodeHeight(findNode(tree, "tea"));
//     // printf("result is %d", result);
//     // ck_assert_int_eq(result, 3);

// }

//might be repetitive
// START_TEST (test_find_node_similar_name) {
//     insertNode(tree, "eating");
//     insertNode(tree, "eats");
//     ck_assert_ptr_null(findNode(tree, "eat"));
// }

// START_TEST (case_sensitive) {
//     insertNode(tree, "Eat");
//     ck_assert_ptr_null(findNode(tree, " Eat "));
// }

START_TEST (test_right) { //this one failed but lowered the score??
    insertNode(tree, "a");
    insertNode(tree, "b");
    insertNode(tree, "c");
    insertNode(tree, "d");
    TreeNode * newNode;
    newNode = getRoot(tree);
    TreeNode * root = findNode(tree, "b");
    ck_assert_ptr_eq(newNode, root);

    TreeNode * d = findNode(tree, "d");
    TreeNode * right = getRightChild(d);
    char * address = getNodeData(right);
    char * addressOfD = getNodeData(d);

    int result = compareStrings(address, addressOfD);

    ck_assert_int_eq(result, 0); //should be 0 if equal

    
    
    //ck_assert_ptr_eq(getRightChild(findNode(tree, "d")), "d");

}
END_TEST


START_TEST (test_height) {

    insertNode(tree, "a");
    insertNode(tree, "b");
    insertNode(tree, "c");
    insertNode(tree, "d");
    int height;
    height = getNodeHeight(getRoot(tree));
    ck_assert_int_eq(height, 2);
}
END_TEST

START_TEST (test_free_when_empty) {

    destroyTree(tree);
    tree = NULL;
    ck_assert_ptr_null(tree);

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
//    tcase_add_test(tc, test_finding_node); //first test added
    tcase_add_test(tc, test_finding_node_when_empty);
    tcase_add_test(tc, test_finding_node_when_empty_with_contents);
    tcase_add_test(tc, test_compare_strings_when_equal);

    // tcase_add_test(tc, test_free);
    // tcase_add_test(tc, test_free_not_exist);

            tcase_add_test(tc, test_get_root_when_no_data);
//    // tcase_add_test(tc, test_get_root_when_data);
    // tcase_add_test(tc, test_correct_height);

    // tcase_add_test(tc, test_find_node_similar_name);
    // tcase_add_test(tc, case_sensitive);

   tcase_add_test(tc, test_right);

   tcase_add_test(tc, test_height);

   tcase_add_test(tc, test_free_when_empty);


  

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