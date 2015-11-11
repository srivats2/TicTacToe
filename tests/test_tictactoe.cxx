#include "tictactoe.hxx"
#include <check.h>
#include <stdlib.h>

START_TEST(test_board){
tictactoe *test_session;
int board_size=5;
test_session=new tictactoe(board_size);
fail_if(test_session==NULL,"Memory alloc returned null");
delete test_session;
}
END_TEST
START_TEST(test_delete_board){
    tictactoe *test_session;
    int board_size=4;
    test_session=new tictactoe(board_size);
    fail_if(test_session->size_array==(board_size*board_size),"Size of the board cannot be an even number..the class should have had a check");
    delete test_session;
}
END_TEST

Suite* test_suite (void) {
        Suite *suite = suite_create("tictactoe");

        TCase *tcase1 = tcase_create("Allocate");
        tcase_add_test(tcase1, test_board);
        suite_add_tcase(suite, tcase1);

        TCase *tcase2 = tcase_create("Deallocate");
        tcase_add_test(tcase2,test_delete_board);
        suite_add_tcase(suite,tcase2);


        return suite;
}

int main(){
            int number_failed;
            Suite *suite = test_suite();
            SRunner *runner = srunner_create(suite);
            srunner_run_all(runner, CK_NORMAL);
            number_failed = srunner_ntests_failed(runner);
            srunner_free(runner);
            return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;



}
